//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "Closing.h"

void Closing::onEnter(Garage &garage) {
    std::cout << "Entered Closing state.." << "\n";
}

void Closing::accept(Garage &garage, Event event) {

}

void Closing::onExit(Garage &garage) {
    std::cout << "Exiting Closing state.." << "\n";
}
