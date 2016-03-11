//
// Created by Tristan Whitcher on 3/9/16.
//

#include "GarageController.h"

GarageController::GarageController() : inputController(garage) {
    this->garage.sendEvent(BUTTON_PRESSED);
    this->garage.sendEvent(OVERCURRENT);
}

