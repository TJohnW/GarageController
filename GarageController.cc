#include <iostream>
#include <pthread.h>
#include "Application.h"
#include "SafeOutput.h"

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

int main(int argc, char *argv[]) {
	SafeOutput out;
	SafeOutput::init();

	Application garageController;
	//pthread_t inputThread;
	pthread_t garageThread;
	pthread_t motorThread;
	//pthread_create(&inputThread, NULL, startInputController, (void *) garageController.inputController);
	pthread_create(&garageThread, NULL, startGarage, (void*) garageController.garage);
	pthread_create(&motorThread, NULL, startMotor, (void*) garageController.garage->getMotor());

	garageController.inputController->run();

	return EXIT_SUCCESS;
}
