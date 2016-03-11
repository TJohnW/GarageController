//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_GARAGE_H
#define GARAGECONTROLLER_GARAGE_H


#include "Motor.h"
class State;
class Garage {

    State* currentState;
    Motor motor;

public:
    Garage();

    void transition(State* state);

    void sendEvent(Event event);

    Motor& getMotor();

};


#endif //GARAGECONTROLLER_GARAGE_H
