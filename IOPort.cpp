//
// Created by Tristan Whitcher on 4/4/16.
//

#include "IOPort.h"

#include <iostream>
#include <assert.h>

#include <stdint.h>
#include <sys/mman.h>

/*
IOPort::CONTROL_HANDLE = mmap_device_io(IO_PORT_SIZE, IO_CONTROL_REGISTER);
IOPort::A_HANDLE = mmap_device_io(IO_PORT_SIZE, IO_A_REGISTER);
IOPort::B_HANDLE = mmap_device_io(IO_PORT_SIZE, IO_B_REGISTER);
 */


uintptr_t IOPort::CONTROL_HANDLE = 0x0;
uintptr_t IOPort::A_HANDLE = 0x3;
uintptr_t IOPort::B_HANDLE = 0x4;


IOPort::IOPort() {
    /* Set bits 1 and 4 for the input and output */
    // set both to input for now.

    setBit(CONTROL_HANDLE, 1, 1);
    setBit(CONTROL_HANDLE, 4, 1);



    std::cout << isSetBit(CONTROL_HANDLE, 1) << ":" << std::bitset<8>(CONTROL_HANDLE) << std::endl;
}

bool IOPort::isSetBit(uintptr_t byte, int bit) {
    std::bitset<8> set(byte);
    return set.test(bit);
}

void IOPort::setBit(uintptr_t& byte, int bit, bool value) {
    std::bitset<8> set(byte);
    set.set(bit, value);
    byte = set.to_ulong();
}

bool IOPort::IS_FULL_OPEN() {
    // checks bit of the input and if its true, waits until set back to 0
}
