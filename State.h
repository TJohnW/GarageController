//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_STATE_H
#define GARAGECONTROLLER_STATE_H


#include <iosfwd>
#include <string>
#include "Garage.h"
#include "Event.h"

class State {

    std::string name;

public:

    State(std::string name);

    virtual void onEnter(Garage& garage) = 0;
    virtual void accept(Garage& garage, Event event) = 0;
    virtual void onExit(Garage& garage) = 0;
};


#endif //GARAGECONTROLLER_STATE_H
