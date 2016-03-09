#ifndef Application_h
#define Application_h

#include "Garage.h"
#include "InputController.h"


class Application {

 public:

    virtual void Application();

 public:
    Garage garage;
    InputController input;

 public:

    /**
     * @element-type InputController
     */
    InputController *1;

    Garage *myGarage;

    InputController myInputController;

    Garage myGarage;
};

#endif // Application_h
