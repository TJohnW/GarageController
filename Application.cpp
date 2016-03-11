//
// Created by Tristan Whitcher on 3/9/16.
//

#include "Application.h"

Application::Application() : inputController(garage) {
    this->inputController.run();
}

