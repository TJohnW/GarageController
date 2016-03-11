//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_STATES_H
#define GARAGECONTROLLER_STATES_H


#include "State.h"
#include "ClosingStopped.h"
#include "OpeningStopped.h"
#include "Closing.h"
#include "Opening.h"

class States {
public:
    static State* CLOSING_STOPPED;
    static State* OPENING_STOPPED;
    static State* CLOSING;
    static State* OPENING;
};

#endif //GARAGECONTROLLER_STATES_H
