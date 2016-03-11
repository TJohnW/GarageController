//
// Created by Tristan Whitcher on 3/10/16.
//

#include <iostream>
#include "OpeningStopped.h"


void OpeningStopped::onEnter(Garage &garage) {
    std::cout << "Entered OpeningStopped state.." << "\n";
}

void OpeningStopped::accept(Garage &garage, Event event) {

}

void OpeningStopped::onExit(Garage &garage) {
    std::cout << "Exiting OpeningStopped state.." << "\n";
}
