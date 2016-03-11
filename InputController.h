//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_INPUTCONTROLLER_H
#define GARAGECONTROLLER_INPUTCONTROLLER_H


#include "Garage.h"
#include "Observer.h"

class InputController : Observer {

    Garage garage;

public:
    void printState();

    void run();

    void forwardEvent(Event& event);

    void update(Event& event);
};


#endif //GARAGECONTROLLER_INPUTCONTROLLER_H
