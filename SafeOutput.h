//
// Created by Tristan Whitcher on 3/29/16.
//

#ifndef APPLICATION_SAFEOUTPUT_H
#define APPLICATION_SAFEOUTPUT_H

#include <pthread.h>
#include <string>

class SafeOutput {

    static pthread_mutexattr_t outputMutexAttr; //Mutex attribute variable
    static pthread_mutex_t outputMutex; //Mutex for output blocking

public:

    static void init();

    static void lock(pthread_mutex_t* mutex);

    static void unlock(pthread_mutex_t* mutex);

    static void safe_output(std::string outString);

};


#endif //APPLICATION_SAFEOUTPUT_H
