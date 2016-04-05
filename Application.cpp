//
// Created by Tristan Whitcher on 3/9/16.
//

#include <pthread.h>
#include <iostream>
#include "Application.h"

bool Application::SIMULATION = false;
Application::Application(bool simulation) {
    SIMULATION = simulation;
    garage = new Garage();
    inputController = new InputController(garage);
}

