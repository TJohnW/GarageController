//
// Created by Tristan Whitcher on 4/4/16.
//

#ifndef APPLICATION_IOPORT_H
#define APPLICATION_IOPORT_H

#include <sys/_types/_uintptr_t.h>


#define IO_PORT_SIZE 1
#define IO_CONTROL_REGISTER 0x28B
#define IO_A_REGISTER 0x288
#define IO_B_REGISTER 0x289


#define INPUT_FULL_OPEN;
#define INPUT_FULL_CLOSE;
#define INPUT_IR_BROKEN;
#define INPUT_OVERCURRENT;
#define INPUT_REMOTE_BUTTON;

#define OUTPUT_MOTOR_UP;
#define OUTPUT_MOTOR_DOWN;
#define OUTPUT_IR_ON;

#define OUTPUT_RESET;



class IOPort {
public:
    static uintptr_t CONTROL_HANDLE;
    static uintptr_t A_HANDLE;
    static uintptr_t B_HANDLE;

    static bool isSetBit(uintptr_t byte, int bit);
    static void setBit(uintptr_t& byte, int bit, bool value);

    static bool IS_FULL_OPEN();
    static bool IS_FULL_CLOSE();

    IOPort();

};


#endif //APPLICATION_IOPORT_H
