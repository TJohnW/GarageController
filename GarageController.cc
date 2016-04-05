#include <iostream>
#include <pthread.h>

#include <sys/neutrino.h>

#include "Application.h"
#include "SafeOutput.h"
#include "IOPort.h"

using namespace std;


void *startGarage(void* garage) {
	((Garage*) garage)->run();
}

void *startMotor(void* motor) {
	((Motor*) motor)->run();
}


void verifyThreadAccess() {
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
	{
		perror("Failed to get I/O access permission");
		exit(1);
	}
}


int main(int argc, char *argv[]) {
	bool sim = false;
	if(argc > 0) {
		if(argv[0] == "s") {
			sim = true;
		}
	}

	if(!sim) {
		verifyThreadAccess();
	}

	IOPort ioPort = IOPort();

	SafeOutput out;
	SafeOutput::init();

	Application garageController(sim);

	pthread_t garageThread;
	pthread_t motorThread;

	pthread_create(&garageThread, NULL, startGarage, (void*) garageController.garage);
	pthread_create(&motorThread, NULL, startMotor, (void*) garageController.garage->getMotor());

	garageController.inputController->run();

	return EXIT_SUCCESS;
}
