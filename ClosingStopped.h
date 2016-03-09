//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_CLOSINGSTOPPED_H
#define GARAGECONTROLLER_CLOSINGSTOPPED_H


#include "State.h"

class ClosingStopped : State {

public:
    ClosingStopped(const std::string &name) : State(name) { }

};


#endif //GARAGECONTROLLER_CLOSINGSTOPPED_H
