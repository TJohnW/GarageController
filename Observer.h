//
// Created by Tristan Whitcher on 3/10/16.
//

#ifndef GARAGECONTROLLER_OBSERVER_H
#define GARAGECONTROLLER_OBSERVER_H


#include "Event.h"

class Observer {
public:
    virtual void update(Event& event) = 0;
};


#endif //GARAGECONTROLLER_OBSERVER_H
