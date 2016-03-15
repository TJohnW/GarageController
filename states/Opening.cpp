//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Opening.h"
#include "States.h"

void Opening::onEnter(Garage &garage) {
    std::cout << "Entered Opening state.." << "\n";
    std::cout << "IR Beam on..." << "\n";
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
    std::cout << "Exiting Opening state.." << "\n";
    std::cout << "IR Beam off..." << "\n";
    garage.getMotor()->turnOff();
}
