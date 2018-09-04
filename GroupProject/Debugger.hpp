/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Debugger is used to output debugging messages to console during
** 				executions.  bool DEBUG_MESSAGES can be toggled to show or hide output.
**************************************************************************************/
#ifndef DEBUGGER_CPP
#define DEBUGGER_CPP

#include "Game.hpp"

#include <string>
#include <iostream>

//This value can be toggled to hide or display debugging messages
const bool DEBUG_MESSAGES = false;

void dm(std::string);
#endif