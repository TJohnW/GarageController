//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_OPENINGSTOPPED_H
#define GARAGECONTROLLER_OPENINGSTOPPED_H


#include "State.h"

class OpeningStopped : public State {

public:
    OpeningStopped(const std::string &name) : State(name) { }

    virtual void onEnter(Garage &garage);

    virtual void accept(Garage &garage, Event event);

    virtual void onExit(Garage &garage);
};


#endif //GARAGECONTROLLER_OPENINGSTOPPED_H
