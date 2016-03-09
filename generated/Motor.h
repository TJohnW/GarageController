#ifndef Motor_h
#define Motor_h

#include "void.h"

class Garage;

class Motor {

 public:

    virtual Integer getMode();

    virtual void overcurrent();

 private:

    virtual void run();

 public:
    Integer mode;
    Integer position;

 public:

    Garage *myGarage;

    Garage *myGarage;

    /**
     * @element-type Garage
     */
    Garage *1;

    Garage *myGarage;
};

#endif // Motor_h
