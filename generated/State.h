#ifndef State_h
#define State_h

class Garage;

class State {

 public:

    virtual void onEnter(void  garage)  = 0;

    virtual void accept(Garage garage, Event e)  = 0;

    virtual void onExit(void  garage)  = 0;

public:
    // virtual destructor for interface 
    virtual ~State() { }

 public:

    /**
     * @element-type Garage
     */
    Garage *1;

    Garage *myGarage;

    Garage *myGarage;
};

#endif // State_h
