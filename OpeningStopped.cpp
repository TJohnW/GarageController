//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "OpeningStopped.h"
#include "States.h"


void OpeningStopped::onEnter(Garage &garage) {
    std::cout << "State: OpeningStopped" << std::endl;
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
