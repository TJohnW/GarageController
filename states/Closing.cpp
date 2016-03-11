//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Closing.h"
#include "States.h"

void Closing::onEnter(Garage &garage) {
    std::cout << "Entered Closing state.." << "\n";
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
    std::cout << "Exiting Closing state.." << "\n";
}
