/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Debugger is used to output debugging messages to console during
** 				executions.  bool DEBUG_MESSAGES can be toggled to show or hide output.
**************************************************************************************/
#include "Debugger.hpp"
#include <cctype>

void dm(std::string msg) {
	if (DEBUG_MESSAGES) {
		std::cout << msg << std::endl;
	}
}
