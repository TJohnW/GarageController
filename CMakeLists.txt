cmake_minimum_required(VERSION 3.3)
project(Application)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES GarageController.cc Application.cpp Application.h Garage.cpp Garage.h InputController.cpp InputController.h State.cpp State.h Event.h ClosingStopped.cpp ClosingStopped.h Motor.cpp Motor.h Subject.cpp Subject.h Observer.cpp Observer.h ClosingStopped.cpp ClosingStopped.h OpeningStopped.cpp OpeningStopped.h Opening.cpp Opening.h Closing.cpp Closing.h States.cpp States.h SafeOutput.cpp SafeOutput.h)
add_executable(Application ${SOURCE_FILES})