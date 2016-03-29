//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "ClosingStopped.h"
#include "States.h"
#include "SafeOutput.h"

void ClosingStopped::onEnter(Garage &garage) {
    SafeOutput::safe_output("State: ClosingStopped");
}

void ClosingStopped::accept(Garage &garage, Event event) {
    switch(event) {
        case BUTTON_PRESSED:
            garage.transition(States::OPENING);
            break;
        default:
            break;
    }
}

void ClosingStopped::onExit(Garage &garage) {

}
