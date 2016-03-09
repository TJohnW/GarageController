#ifndef Garage_h
#define Garage_h

#include "Map.h"
#include "Motor.h"
#include "State.h"
#include "void.h"

class InputController;
class Application;

class Garage {

 public:

    virtual State getCurrentState();

    virtual void sendEvent(void  Event);

    virtual void run();

    virtual void transition(void  State);

 public:
    Map states;
    State* currentState;
    Motor motor;


 public:

    /**
     * @element-type InputController
     */
    InputController *1;

    /**
     * @element-type State
     */
    State **;

    Motor *?;

    Motor *myMotor;

    Application *myApplication;

    /**
     * @element-type InputController
     */
    InputController *1;

    /**
     * @element-type InputController
     */
    InputController *myInputController;

    InputController *myInputController;

    Application *myApplication;

    State &myState;

    /**
     * @element-type Motor
     */
    Motor 1;

    Motor myMotor;

    State &myState;
};

#endif // Garage_h
