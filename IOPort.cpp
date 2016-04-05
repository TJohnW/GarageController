//
// Created by Tristan Whitcher on 4/4/16.
//

#include "IOPort.h"

#include <iostream>
#include <assert.h>

#include <stdint.h>
#include <sys/mman.h>

#include <bitset>

#include <unistd.h>


uintptr_t IOPort::CONTROL_HANDLE = mmap_device_io(IO_PORT_SIZE, IO_CONTROL_REGISTER);
uintptr_t IOPort::A_HANDLE = mmap_device_io(IO_PORT_SIZE, IO_A_REGISTER);
uintptr_t IOPort::B_HANDLE = mmap_device_io(IO_PORT_SIZE, IO_B_REGISTER);


IOPort::IOPort() {
    /* Set bits 1 and 4 for the input and output */
    // set both to input for now.

    if(CONTROL_HANDLE == MAP_DEVICE_FAILED)
    {

        std::cout << "Failed to map control register";
    }

    if(A_HANDLE == MAP_DEVICE_FAILED)
    {
        std::cout << "Failed to map control register";

    }

    if(B_HANDLE == MAP_DEVICE_FAILED)
    {

        std::cout << "Failed to map control register";

    }


    setBit(CONTROL_HANDLE, 1, 0);
    setBit(CONTROL_HANDLE, 4, 1);

    //setBit(B_HANDLE, 3, 1);
    //sleep(1);
    //setBit(B_HANDLE, 3, 0);

    while(true) {
        std::cout << "A_HANDLE: " << std::bitset<8>(in8(A_HANDLE)) << " B_HANDLE: " << std::bitset<8>(in8(B_HANDLE)) << " CONTROL_HANDLE: " << std::bitset<8>(in8(CONTROL_HANDLE)) << std::endl;
        sleep(1);

    }

    //std::cout << isSetBit(CONTROL_HANDLE, 1) << ":" << std::bitset<8>(CONTROL_HANDLE) << std::endl;
}

bool IOPort::isSetBit(uintptr_t& port, int bit) {
    uint8_t readValue = in8(port);
    std::bitset<8> set(readValue);
    return set.test(bit);
}

void IOPort::setBit(uintptr_t& port, int bit, bool value) {
    uint8_t readValue = in8(port);
    std::bitset<8> set(readValue);
    set.set((size_t) bit, value);
    readValue = (uint8_t) set.to_ulong();
    out8(port, readValue);
}



bool IOPort::IS_FULL_OPEN() {
    return consume(A_HANDLE, INPUT_FULL_OPEN);
}

bool IOPort::IS_FULL_CLOSE() {
    return consume(A_HANDLE, INPUT_FULL_CLOSE;
}

bool IOPort::IS_IR_BROKEN() {
    return consume(A_HANDLE, INPUT_IR_BROKEN);
}

bool IOPort::IS_OVERCURRENT() {
    return consume(A_HANDLE, INPUT_OVERCURRENT);
}

bool IOPort::IS_REMOTE_BUTTON() {
    return consume(A_HANDLE, INPUT_REMOTE_BUTTON);
}

void IOPort::MOTOR_UP_ON() {
    setBit(B_HANDLE, OUTPUT_MOTOR_UP, true);
}

void IOPort::MOTOR_UP_OFF() {
    setBit(B_HANDLE, OUTPUT_MOTOR_UP, false);
}

void IOPort::MOTOR_DOWN_ON() {
    setBit(B_HANDLE, OUTPUT_MOTOR_DOWN, true);
}

void IOPort::MOTOR_DOWN_OFF() {
    setBit(B_HANDLE, OUTPUT_MOTOR_DOWN, true);
}

void IOPort::IR_ON() {
    setBit(B_HANDLE, OUTPUT_IR_ON, true);
}

void IOPort::IR_OFF() {
    setBit(B_HANDLE, OUTPUT_IR_ON, false);
}

void IOPort::RESET_ON() {
    setBit(B_HANDLE, OUTPUT_RESET, true);
}

void IOPort::RESET_OFF() {
    setBit(B_HANDLE, OUTPUT_RESET, false);
}

bool IOPort::consume(uintptr_t &port, int bit) {
    // wait until the bit is no longer set
    if(isSetBit(port, bit)) {
        while(isSetBit(port, bit));
        return true;
    }

    return false;
}
