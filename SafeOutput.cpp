//
// Created by Tristan Whitcher on 3/29/16.
//

#include <iostream>
#include "SafeOutput.h"

pthread_mutexattr_t SafeOutput::outputMutexAttr; //Mutex attribute variable
pthread_mutex_t SafeOutput::outputMutex; //Mutex for output blocking

void SafeOutput::lock(pthread_mutex_t *mutex) {
    int result = pthread_mutex_trylock(mutex);
    while (result != 0) {
        result = pthread_mutex_trylock(mutex);
    }
}

void SafeOutput::unlock(pthread_mutex_t *mutex) {
    int result = pthread_mutex_unlock(mutex);
    while (result != 0) {
        result = pthread_mutex_unlock(mutex);
    }
}

void SafeOutput::safe_output(std::string outString) {
    lock(&outputMutex);
    std::cout << outString << std::endl;
    unlock(&outputMutex);
}

void SafeOutput::init() {
    pthread_mutexattr_init(&outputMutexAttr);
    pthread_mutexattr_settype(&outputMutexAttr, PTHREAD_MUTEX_ERRORCHECK); //Set mutex attribute to error-checking type
    pthread_mutex_init(&outputMutex, &outputMutexAttr); //Initialize queue mutex with attributes
}
