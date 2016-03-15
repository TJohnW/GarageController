//
// Created by Tristan Whitcher on 3/9/16.
//

#include <iostream>
#include "InputController.h"

InputController::InputController(Garage* garage) : garage(garage) {
    enabled = true;
    std::cout << "Initializing InputController" << "\n";
    garage->getMotor()->attach(this);
}


void InputController::printState() {

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

        int c = getchar();

        if((char) c == '\n') {
            continue;
        }

        std::cout << (char) c << " received. \n";
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
