//
// Created by Tristan Whitcher on 4/4/16.
//

#ifndef APPLICATION_IOPORT_H
#define APPLICATION_IOPORT_H

#include <stdint.h>
#include <sys/mman.h>
#include <bitset>
#include <hw/inout.h>

#define IO_PORT_SIZE 1
#define IO_CONTROL_REGISTER 0x28B

#define IO_A_REGISTER 0x288
#define IO_B_REGISTER 0x289


#define INPUT_FULL_OPEN 0
#define INPUT_FULL_CLOSE 0
#define INPUT_IR_BROKEN 0
#define INPUT_OVERCURRENT 0
#define INPUT_REMOTE_BUTTON 0

#define OUTPUT_MOTOR_UP 0
#define OUTPUT_MOTOR_DOWN 0
#define OUTPUT_IR_ON 0

#define OUTPUT_RESET 0



class IOPort {
public:
    static uintptr_t CONTROL_HANDLE;
    static uintptr_t A_HANDLE;
    static uintptr_t B_HANDLE;

    static bool isSetBit(uintptr_t byte, int bit);
    static void setBit(uintptr_t byte, int bit, bool value);

    static bool IS_FULL_OPEN();
    static bool IS_FULL_CLOSE();

    IOPort();

};


#endif //APPLICATION_IOPORT_H
