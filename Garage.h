//
// Created by Tristan Whitcher on 3/9/16.
//

#ifndef GARAGECONTROLLER_GARAGE_H
#define GARAGECONTROLLER_GARAGE_H


#include <queue>
#include "Motor.h"
class State;
class Garage {

    bool enabled;

    State* currentState;
    Motor motor;

    std::queue<Event> eventQueue;

    void sendEvent(Event event);

public:

    //static void* run(void *garage);

    Garage();

    void transition(State* state);

    Motor* getMotor();

    void queueEvent(Event event);

    void run();
};


#endif //GARAGECONTROLLER_GARAGE_H
