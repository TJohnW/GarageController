//
// Created by Tristan Whitcher on 3/9/16.
//

#include <pthread.h>
#include <iostream>
#include "Application.h"


Application::Application() {
    garage = new Garage();
    inputController = new InputController(garage);

}

