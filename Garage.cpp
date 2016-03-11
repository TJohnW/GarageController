//
// Created by Tristan Whitcher on 3/9/16.
//

#include <iostream>
#include "Garage.h"
#include "states/States.h"


Garage::Garage() : currentState{States::CLOSING_STOPPED} {
    std::cout << this->currentState->getName();
}
