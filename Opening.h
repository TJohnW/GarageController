//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_OPENING_H
#define GARAGECONTROLLER_OPENING_H


#include "State.h"

class Opening : public State {

public:
    Opening(const std::string &name) : State(name) { }

    virtual void onEnter(Garage &garage);

    virtual void accept(Garage &garage, Event event);

    virtual void onExit(Garage &garage);
};


#endif //GARAGECONTROLLER_OPENING_H
