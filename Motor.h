//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_MOTOR_H
#define GARAGECONTROLLER_MOTOR_H


#include "Subject.h"
#include <pthread.h>

class Motor : public Subject  {

    int position;
    bool active;
    bool up;
    bool enabled;

    pthread_mutexattr_t mutexAttr; //Mutex attribute variable
    pthread_mutex_t dirMutex; //Mutex for direction variable
    pthread_mutex_t pwrMutex; //Mutex for power variable

public:

    static const int FULLY_OPEN_POSITION = 10;
    static const int FULLY_CLOSED_POSITION = 1;

    Motor();

    void run();

    void overcurrent();

    void fullyOpen();

    void fullyClosed();

    void turnOn();

    void turnOff();

    void setDirection(bool up);

    bool isOn();

    bool isUp();

};


#endif //GARAGECONTROLLER_MOTOR_H
