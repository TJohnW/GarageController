//
// Created by Tristan Whitcher on 3/10/16.
//

#include "Subject.h"

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}


void Subject::notifyObservers(Event event) {
    for(int i = 0; i < observers.size(); i++) {
        observers[i]->update(event);
    }
}

void Subject::detach(Observer *observer) {
    for(int i = 0; i < observers.size(); i++) {
        if(observers[i] == observer) {
            observers.erase(observers.begin() + i);
            return;
        }
    }
}
