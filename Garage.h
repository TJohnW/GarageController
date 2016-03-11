//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_GARAGE_H
#define GARAGECONTROLLER_GARAGE_H


#include "Motor.h"
#include "states/State.h"

class Garage {

    State* currentState;
    Motor motor;

public:
    Garage();

    void transition(State* state);

    Motor& getMotor();

};


#endif //GARAGECONTROLLER_GARAGE_H
