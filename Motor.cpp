//
// Created by Tristan Whitcher on 3/10/16.
//

#include "Motor.h"
#include "Event.h"

Motor::Motor() {
    position = 0;
    enabled = true;
    up = true;
    active = false;
}

void Motor::run() {
    while(enabled) {
        if(active) {
            if(up && position /* < FULLY_CLOSED_POSITION */) {
                position++;
            } else if(position /* > FULLY_OPEN_POSITION */) {
                position--;
            }

            if(position == FULLY_CLOSED_POSITION) {
                fullyClosed();
            } else if(position == FULLY_OPEN_POSITION) {
                fullyOpen();
            }
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
}
