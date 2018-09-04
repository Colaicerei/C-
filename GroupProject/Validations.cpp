/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Implementation for the Validations class which contains methods for 
** for validating user input
**************************************************************************************/

#include "Validations.hpp"
#include <iostream>

/******************************************************************************
** Name:         promptShort
** Description:  Prompts a user for input and attempts to validate that input
** Arguments:    prompt - the text string used to prompt a user for input
**				 min - minimum allowed value
**				 max - maximum allowed vcalue
** Return value: A short derived from validated input provided by user
******************************************************************************/
short promptShort(const std::string prompt, const short min, const short max, bool displayRange)
{
	bool valid = false;
	do
	{
		std::cout << prompt;
		if (displayRange) {
			std::cout << " (" << min << "-" << max << ")";
		}
		std::cout << ": ";
		std::string input = "";
		std::getline(std::cin, input);

		//Ensure only digits
		bool digitOnly = (((input[0] == '-' || input[0] == '+') && input.length() > 1) || isdigit(input[0])); //Start by ensuring the leading char is valid.
		for (unsigned int chr = 1; chr < input.length() && digitOnly; chr++) //First char valid.  Iterate through remaining chars.
		{
			if (!isdigit(input[chr]))
			{
				digitOnly = false;
			}
		}

		if (digitOnly && input.length() > 0) //Ensure input consists only of digits and if not a blank value
		{
			errno = 0; //Reset error code; strtol will provide an errno of out of bounds if the input is out of bounds.
			long temp = strtol(input.c_str(), NULL, 10);


			if (errno != ERANGE //Check if out of long range
				&& temp <= max //Check to ensure value is within the provided int range
				&& temp >= min)
			{
				valid = true;
				return (short)temp;
			}
			else
			{
				std::cout << "Entry " << input << " does not fall within an acceptable range of " << min << " to " << max << ".\n";
			}
		}
		else
		{
			std::cout << "Non-numeric, decimal, or comma formatted entries are not valid.\n";
		}
	} while (!valid);
	return 0;
}

/******************************************************************************
** Name:         promptEnter
** Description:  Displays a customer prompt and waits for user to press enter
**			     Flushes the buffer at exit. Used for "Press enter to
**				 continue" prompts
** Arguments:    prompt - the text string used to prompt a user for input
** Return value: none
******************************************************************************/
void promptEnter(std::string prompt)
{
	std::string input;
	std::cout << prompt;
	getline(std::cin, input);
	std::cin.clear();
}