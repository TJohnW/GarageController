//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_MOTOR_H
#define GARAGECONTROLLER_MOTOR_H


#include "util/Subject.h"

class Motor : public Subject  {

    int position;
    bool up;

public:
    Motor();

    void run();

    void overcurrent();

    void fullyOpen();

    void fullyClosed();
};


#endif //GARAGECONTROLLER_MOTOR_H
