//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_CONCRETESTATE_H
#define GARAGECONTROLLER_CONCRETESTATE_H


#include "State.h"

class ClosingStopped : public State {

public:
    ClosingStopped(const std::string &name) : State(name) { }

    virtual void onEnter(Garage &garage);

    virtual void accept(Garage &garage, Event event);

    virtual void onExit(Garage &garage);
};


#endif //GARAGECONTROLLER_CONCRETESTATE_H
