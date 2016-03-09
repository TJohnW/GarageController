cmake_minimum_required(VERSION 3.3)
project(GarageController)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GarageController.cpp GarageController.h Garage.cpp Garage.h InputController.cpp InputController.h State.cpp State.h Event.cpp Event.h ClosingStopped.cpp ClosingStopped.h)
add_executable(GarageController ${SOURCE_FILES})