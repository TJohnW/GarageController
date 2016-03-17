//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include <unistd.h>
#include "Motor.h"

Motor::Motor() {
    position = 1;
    enabled = true;
    up = true;
    active = false;
}

void Motor::run() {
    while(enabled) {
        if(active) {
            if(up /* && position  < FULLY_CLOSED_POSITION */) {
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
    active = true;
    std::cout << "Motor on." << std::endl;
}

void Motor::setDirection(bool up) {
    this->up = up;
}

void Motor::turnOff() {
    active = false;
    std::cout << "Motor off." << std::endl;
}
