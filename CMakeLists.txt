cmake_minimum_required(VERSION 3.3)
project(Application)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Application.cpp Application.h Garage.cpp Garage.h InputController.cpp InputController.h states/State.cpp states/State.h Event.h states/ClosingStopped.cpp states/ClosingStopped.h Motor.cpp Motor.h util/Subject.cpp util/Subject.h util/Observer.cpp util/Observer.h states/ClosingStopped.cpp states/ClosingStopped.h states/OpeningStopped.cpp states/OpeningStopped.h states/Opening.cpp states/Opening.h states/Closing.cpp states/Closing.h states/States.cpp states/States.h)
add_executable(Application ${SOURCE_FILES})