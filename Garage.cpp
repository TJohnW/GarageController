//
// Created by Tristan Whitcher on 3/9/16.
//

#include <iostream>
#include "Garage.h"
#include "States.h"


Garage::Garage() : currentState(States::CLOSING_STOPPED) {
    enabled = true;
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
    this->eventQueue.push(event);
}

void Garage::sendEvent(Event event) {
    this->currentState->accept(*this, event);
}


void Garage::run() {
    this->currentState->onEnter(*this);
    while(enabled) {
        if(this->eventQueue.size() > 0) {
            this->sendEvent(this->eventQueue.front());
            this->eventQueue.pop();
        }
    }
}

