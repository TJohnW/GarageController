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


/*
uintptr_t IOPort::CONTROL_HANDLE = 0x0;
uintptr_t IOPort::A_HANDLE = 0x3;
uintptr_t IOPort::B_HANDLE = 0x4;
*/


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

    setBit(B_HANDLE, 3, 1);
    sleep(1);
    //setBit(B_HANDLE, 3, 0);

    while(true) {
        std::cout << "A_HANDLE: " << std::bitset<8>(in8(A_HANDLE)) << " B_HANDLE: " << std::bitset<8>(in8(B_HANDLE)) << " CONTROL_HANDLE: " << std::bitset<8>(in8(CONTROL_HANDLE)) << std::endl;
        sleep(1);

    }

    //std::cout << isSetBit(CONTROL_HANDLE, 1) << ":" << std::bitset<8>(CONTROL_HANDLE) << std::endl;
}

bool IOPort::isSetBit(uintptr_t byte, int bit) {
    uint8_t readValue = in8(byte);
    std::bitset<8> set(readValue);
    return set.test(bit);
}

void IOPort::setBit(uintptr_t byte, int bit, bool value) {
    uint8_t readValue = in8(byte);
    std::bitset<8> set(readValue);
    set.set(bit, value);
    readValue = set.to_ulong();
    out8(byte, readValue);
}

bool IOPort::IS_FULL_OPEN() {
    // checks bit of the input and if its true, waits until set back to 0
}
