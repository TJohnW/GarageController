//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "OpeningStopped.h"
#include "States.h"
#include "SafeOutput.h"


void OpeningStopped::onEnter(Garage &garage) {
    SafeOutput::safe_output("State: OpeningStopped");
}

void OpeningStopped::accept(Garage &garage, Event event) {
    switch(event) {
        case BUTTON_PRESSED:
            garage.transition(States::CLOSING);
            break;
        default:
            break;
    }
}

void OpeningStopped::onExit(Garage &garage) {

}
