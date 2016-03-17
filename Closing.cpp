//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Closing.h"
#include "States.h"

void Closing::onEnter(Garage &garage) {
    std::cout << "State: Closing" << std::endl;
    garage.getMotor()->setDirection(false);
    garage.getMotor()->turnOn();
    std::cout << "IR Beam on." << std::endl;
}

void Closing::accept(Garage &garage, Event event) {
    switch(event) {
        case BUTTON_PRESSED:
        case FULLY_CLOSED:
            garage.transition(States::CLOSING_STOPPED);
            break;
        case OVERCURRENT:
        case IR_BEAM:
            garage.transition(States::OPENING);
            break;
        default:
            break;
    }
}

void Closing::onExit(Garage &garage) {
    garage.getMotor()->turnOff();
    std::cout << "IR Beam off." << std::endl;
}
