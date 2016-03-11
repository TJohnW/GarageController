//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_CLOSING_H
#define GARAGECONTROLLER_CLOSING_H


#include "State.h"

class Closing : public State {

public:
    Closing(const std::string &name) : State(name) { }

    virtual void onEnter(Garage &garage);

    virtual void accept(Garage &garage, Event event);

    virtual void onExit(Garage &garage);
};


#endif //GARAGECONTROLLER_CLOSING_H
