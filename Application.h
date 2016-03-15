//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_GARAGECONTROLLER_H
#define GARAGECONTROLLER_GARAGECONTROLLER_H


#include "Garage.h"
#include "InputController.h"

class Application {
public:

    Garage* garage;
    InputController* inputController;

    Application();
};


#endif //GARAGECONTROLLER_GARAGECONTROLLER_H
