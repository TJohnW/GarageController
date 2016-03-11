//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "ClosingStopped.h"

void ClosingStopped::onEnter(Garage &garage) {
    std::cout << "Entered ClosingStopped state.." << "\n";
}

void ClosingStopped::accept(Garage &garage, Event event) {

}

void ClosingStopped::onExit(Garage &garage) {
    std::cout << "Exiting ClosingStopped state.." << "\n";
}
