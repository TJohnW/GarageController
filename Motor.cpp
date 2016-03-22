//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include <unistd.h>
#include "Motor.h"
#include <pthread.h>

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
                std::cout << "Garage Reached Closed Position." << "\n";
            } else if(position == FULLY_OPEN_POSITION) {
                fullyOpen();
                std::cout << "Garage Reached Open Position." << "\n";
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
    int result = pthread_mutex_trylock(&pwrMutex);
    while (result != 0) {
        result = pthread_mutex_trylock(&pwrMutex);
    }
    active = true;
    std::cout << "Motor on." << std::endl;
    //Release mutex
    result = pthread_mutex_unlock(&pwrMutex);
    while (result != 0) {
        result = pthread_mutex_unlock(&pwrMutex);
    }
}

void Motor::setDirection(bool up) {
    int result = pthread_mutex_trylock(&dirMutex);
    while (result != 0) {
        result = pthread_mutex_trylock(&dirMutex);
    }
    this->up = up;
    result = pthread_mutex_unlock(&dirMutex);
    while (result != 0) {
        result = pthread_mutex_unlock(&dirMutex);
    }
}

void Motor::turnOff() {
    int result = pthread_mutex_trylock(&pwrMutex);
    while (result != 0) {
        result = pthread_mutex_trylock(&pwrMutex);
    }
    active = false;
    std::cout << "Motor off." << std::endl;
    //Release mutex
    result = pthread_mutex_unlock(&pwrMutex);
    while (result != 0) {
        result = pthread_mutex_unlock(&pwrMutex);
    }
}

bool Motor::isOn() {
    bool retval;
    int result = pthread_mutex_trylock(&pwrMutex);
    while (result != 0) {
        result = pthread_mutex_trylock(&pwrMutex);
    }
    retval = active;
    //Release mutex
    result = pthread_mutex_unlock(&pwrMutex);
    while (result != 0) {
        result = pthread_mutex_unlock(&pwrMutex);
    }
    return retval;
}

bool Motor::isUp() {
    bool retval;
    int result = pthread_mutex_trylock(&dirMutex);
    while (result != 0) {
        result = pthread_mutex_trylock(&dirMutex);
    }
    retval = up;
    result = pthread_mutex_unlock(&dirMutex);
    while (result != 0) {
        result = pthread_mutex_unlock(&dirMutex);
    }
    return retval;
}
