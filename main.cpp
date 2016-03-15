#include <iostream>
#include "Application.h"

using namespace std;


void *startGarage(void* garage) {
    ((Garage*) garage)->run();
}

void *startInputController(void* inputController) {
    ((InputController*) inputController)->run();
}

void *startMotor(void* motor) {
    ((Motor*) motor)->run();
}

int main() {

    Application garageController;

    pthread_t inputThread;
    pthread_t garageThread;
    pthread_t motorThread;

    pthread_create(&inputThread, NULL, startInputController, (void *) garageController.inputController);
    pthread_create(&garageThread, NULL, startGarage, (void*) garageController.garage);
    pthread_create(&motorThread, NULL, startMotor, (void*) garageController.garage->getMotor());
    while(1);
    return 0;
}