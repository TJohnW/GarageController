//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_MOTOR_H
#define GARAGECONTROLLER_MOTOR_H


#include "Subject.h"

class Motor : Subject  {

    int position;
    bool up;

public:
    Motor();

    void run();

    void overcurrent();
};


#endif //GARAGECONTROLLER_MOTOR_H
