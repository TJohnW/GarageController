//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_INPUTCONTROLLER_H
#define GARAGECONTROLLER_INPUTCONTROLLER_H


#include "Garage.h"

class InputController : public Observer {

    Garage* garage;
    bool enabled;

public:

    InputController(Garage* garage);

    void printState();

    void forwardEvent(Event event);

    void update(Event event);

    void overcurrent();

    void ir_beam();

    void button_pressed();

    void run();

};


#endif //GARAGECONTROLLER_INPUTCONTROLLER_H
