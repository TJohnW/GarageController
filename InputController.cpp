//
// Created by Tristan Whitcher on 3/9/16.
//

#include <iostream>
#include <stdio.h>
#include <termios.h>
#include "InputController.h"
#include "SafeOutput.h"

InputController::InputController(Garage* garage) : garage(garage) {
    enabled = true;
    SafeOutput::safe_output("Initializing InputController");
    garage->getMotor()->attach(this);
}


void InputController::forwardEvent(Event event) {
    garage->queueEvent(event);
}

void InputController::update(Event event) {
    forwardEvent(event);
}

void InputController::overcurrent() {
    garage->getMotor()->overcurrent();
}

void InputController::ir_beam() {
    forwardEvent(IR_BEAM);
}

void InputController::button_pressed() {
    forwardEvent(BUTTON_PRESSED);
}

void InputController::run() {
    while(enabled) {
        char c;
        std::cin >> c;

        if(c == '\n') {
            continue;
        }

        SafeOutput::safe_output(std::string(1, (char) c) + " received.");
        switch((char) c) {
            case 'm':
                this->overcurrent();
                break;
            case 'i':
                this->ir_beam();
                break;
            case 'r':
                this->button_pressed();
                break;
            default:
                break;
        }
    }
}
