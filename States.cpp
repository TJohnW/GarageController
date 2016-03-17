//
// Created by Tristan Whitcher on 3/10/16.
//

#include "States.h"
#include "ClosingStopped.h"
#include "OpeningStopped.h"
#include "Closing.h"
#include "Opening.h"

State* States::CLOSING_STOPPED = new ClosingStopped("Closing Stopped");
State* States::OPENING_STOPPED = new OpeningStopped("Opening Stopped");
State* States::CLOSING = new Closing("Closing");
State* States::OPENING = new Opening("Opening");