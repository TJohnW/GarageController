//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Opening.h"

void Opening::onEnter(Garage &garage) {
    std::cout << "Entered Opening state.." << "\n";
}

void Opening::accept(Garage &garage, Event event) {

}

void Opening::onExit(Garage &garage) {
    std::cout << "Exiting Opening state.." << "\n";
}
