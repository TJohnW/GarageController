//
// Created by Tristan Whitcher on 3/9/16.
//

#include <iostream>
#include "InputController.h"

InputController::InputController(Garage &garage) : garage(garage) {
    garage.getMotor().attach(this);
}


void InputController::printState() {

}

void InputController::run() {

}

void InputController::forwardEvent(Event& event) {

}

void InputController::update(Event& event) {
    std::cout << "Recieved notification from the motor!: " << event << "\n";
}
