//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_GARAGE_H
#define GARAGECONTROLLER_GARAGE_H


#include "State.h"
#include "ClosingStopped.h"

class Garage {



public:
    static State& CLOSING_STOPPED;
    static State& OPENING_STOPPED;
    static State& OPENING;
    static State& CLOSING;
};


#endif //GARAGECONTROLLER_GARAGE_H
