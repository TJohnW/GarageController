//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Opening.h"
#include "States.h"

void Opening::onEnter(Garage &garage) {
    std::cout << "State: Opening" << std::endl;
    garage.getMotor()->setDirection(true);
    garage.getMotor()->turnOn();
}

void Opening::accept(Garage &garage, Event event) {
    switch(event) {
        case FULLY_OPEN:
        case BUTTON_PRESSED:
        case OVERCURRENT:
            garage.transition(States::OPENING_STOPPED);
            break;
        default:
            break;
    }
}

void Opening::onExit(Garage &garage) {
    garage.getMotor()->turnOff();
}
