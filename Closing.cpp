//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Closing.h"
#include "States.h"
#include "SafeOutput.h"

void Closing::onEnter(Garage &garage) {
    SafeOutput::safe_output("State: Closing");
    garage.getMotor()->setDirection(false);
    garage.getMotor()->turnOn();
    SafeOutput::safe_output("IR Beam on.");
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
    SafeOutput::safe_output("IR Beam off.");
}
