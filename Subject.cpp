//
// Created by Tristan Whitcher on 3/10/16.
//

#include "Subject.h"

void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

void Subject::notifyObserver(Event event) {


}
