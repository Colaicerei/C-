/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Validations class which contains methods for 
** for validating user input
**************************************************************************************/

#ifndef VALIDATIONS_HPP
#define VALIDATIONS_HPP

#include <string>

short promptShort(const std::string prompt, const short min, const short max, bool displayRange = true);
void promptEnter(std::string prompt);

#endif // !VALIDATIONS_HPP
