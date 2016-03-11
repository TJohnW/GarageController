//
// Created by Tristan Whitcher on 3/9/16.
//

#include "Garage.h"
#include "states/States.h"


Garage::Garage() : currentState(States::CLOSING_STOPPED) {
    this->currentState->onEnter(*this);
}

void Garage::transition(State *state) {
    this->currentState->onExit(*this);
    this->currentState = state;
    this->currentState->onEnter(*this);
}

Motor& Garage::getMotor() {
    return motor;
}
