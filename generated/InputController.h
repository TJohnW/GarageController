#ifndef InputController_h
#define InputController_h

#include "Garage.h"
#include "input.h"
#include "void.h"

class Application;

class InputController {

 public:

    virtual void printState();

    virtual void run();

    virtual void generateEvent();

 public:
    Garage garage;
    input inputStream;

 public:

    /**
     * @element-type Garage
     */
    Garage *1;

    /**
     * @element-type Application
     */
    Application *1;

    Garage *myGarage;

    /**
     * @element-type Garage
     */
    Garage *myGarage;

    Garage *myGarage;

    Application *myApplication;
};

#endif // InputController_h
