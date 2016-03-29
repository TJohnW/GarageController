//
// Created by Tristan Whitcher on 3/9/16.
//

#include <iostream>
#include "Garage.h"
#include "States.h"
#include <pthread.h>
#include "SafeOutput.h"


Garage::Garage() : currentState(States::CLOSING_STOPPED) {
    enabled = true;
    pthread_mutexattr_init(&mutexAttr); //Initialize mutex attribute variable
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute to error-checking type
    pthread_mutex_init(&queueMutex, &mutexAttr); //Initialize queue mutex with attributes
}

void Garage::transition(State *state) {
    this->currentState->onExit(*this);
    this->currentState = state;
    this->currentState->onEnter(*this);
}


Motor* Garage::getMotor() {
    return &motor;
}

void Garage::queueEvent(Event event) {
    //Get mutex
    SafeOutput::lock(&queueMutex);
    //Add event
    this->eventQueue.push(event);
    //Release mutex
    SafeOutput::unlock(&queueMutex);
}

void Garage::sendEvent() {
    //Get mutex
    SafeOutput::lock(&queueMutex);
    //Send event if one exists
    if(this->eventQueue.size() > 0) {
        this->currentState->accept(*this, this->eventQueue.front());
        this->eventQueue.pop();
    }
    //Release mutex
    SafeOutput::unlock(&queueMutex);
}


void Garage::run() {
    this->currentState->onEnter(*this);
    while(enabled) {
        this->sendEvent();
    }
}

