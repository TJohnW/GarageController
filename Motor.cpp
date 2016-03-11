//
// Created by Tristan Whitcher on 3/10/16.
//

#include "Motor.h"
#include "Event.h"

Motor::Motor() {
    position = 0;
    up = true;
    run();
}

void Motor::run() {
    overcurrent();
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
