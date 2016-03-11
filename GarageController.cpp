//
// Created by Tristan Whitcher on 3/9/16.
//

#include "GarageController.h"
#include "states/States.h"

GarageController::GarageController() : inputController(garage) {
    garage.transition(States::OPENING);
    garage.transition(States::OPENING_STOPPED);
    garage.getMotor().overcurrent();
}
