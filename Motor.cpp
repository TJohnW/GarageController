//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include "Motor.h"
#include "SafeOutput.h"

Motor::Motor() {
    position = 1;
    enabled = true;
    up = true;
    active = false;

    pthread_mutexattr_init(&mutexAttr); //Initialize mutex attribute variable
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute to error-checking type
    pthread_mutex_init(&dirMutex, &mutexAttr); //Initialize direction mutex with attributes
    pthread_mutex_init(&pwrMutex, &mutexAttr); //Initialize power mutex with attributes
}

void Motor::run() {
    while(enabled) {
        if(isOn()) {
            if(isUp() /* && position  < FULLY_CLOSED_POSITION */) {
                position++;
            } else /* if(position > FULLY_OPEN_POSITION )*/ {
                position--;
            }

            // std::cout << "Position: " << position << "\n";

            if(position == FULLY_CLOSED_POSITION) {
                fullyClosed();
                SafeOutput::safe_output("Garage Reached Closed Position.");
            } else if(position == FULLY_OPEN_POSITION) {
                fullyOpen();
                SafeOutput::safe_output("Garage Reached Open Position.");
            }
            sleep(1);
        }
    }
}

void Motor::overcurrent() {
    notifyObservers(OVERCURRENT);
}

void Motor::fullyOpen() {
    notifyObservers(FULLY_OPEN);
}

void Motor::fullyClosed() {
    notifyObservers(FULLY_CLOSED);
}

void Motor::turnOn() {
    SafeOutput::lock(&pwrMutex);
    active = true;
    SafeOutput::safe_output("Motor on.");
    //Release mutex
    SafeOutput::unlock(&pwrMutex);
}

void Motor::setDirection(bool up) {
    SafeOutput::lock(&dirMutex);
    this->up = up;
    SafeOutput::unlock(&dirMutex);
}

void Motor::turnOff() {
    SafeOutput::lock(&pwrMutex);
    active = false;
    SafeOutput::safe_output("Motor off.");
    SafeOutput::unlock(&pwrMutex);
}

bool Motor::isOn() {
    return active; // this is an atomic operation, no need for a mutex
}

bool Motor::isUp() {
    return up; // same here
}
