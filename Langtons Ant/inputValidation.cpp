/****************************************************************************
** Program name: Langton's Ant
** Author:       Chen Zou
** Date:         8 April 2018
** Description:  This is the implentation file of input validation function,
                 which validates the input from outside source. The function 
                 has three parameters: a pointer to the receiving variable, 
                 the maximum and minimum limit of the input. The function only
                 checks for integer inputs for Langton's Ant program, but can 
                 be expanded for future projects.
****************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include "inputValidation.hpp"

/***************************************************************************
** Description: This function takes a pointer to receiving int variable as
		parameter. It checks if the input string is all numbers, if
		so, itconverts input string to integer then assigns the value
		to the receiving variable.  
****************************************************************************/
void getInt(int* variable)
{
	// taking input as string and convert to int if each character is a 
	// digit. Code modified based on Zalta's post on cplusplus.com
	std::string input = " ";
	int number;
	// initialize input marker as true to start while loop
	bool invalidInput = true;
 
	while(invalidInput)
	{
		std::cout << "Please enter an interger: ";
		std::getline(std::cin, input);
 
		// check if input is empty
		if(input.empty())
		{
			std::cout<<"\nEmpty input, try again!" << std::endl;
		}
		
		else
		{
			// check if the input are all numbers, if not,
			// mark as invalid input and redo the while loop
			invalidInput = false;
			for(int i = 0; i < input.size(); i++)
			{
				if(!isdigit(input[i]))
				{
					std::cout << "Error! Try again!";
					invalidInput = true;
					std::cin.clear();
				
					break;
				}
			}	
		}		
	}
	
	// if input is all numbers, convert string to digit
	number = std::stoi(input);
	// assign the input value to the receiving variable  
	*variable = number;
} 	   
 

/****************************************************************************
** Description: This function checks if the input is integer using the getInt 
		function, then validates an assigns to the receiving variable
		if it meets the minimum value requirement passed as parameter.
****************************************************************************/
void getIntWithMin(int* variable, int min)
{
	 
	int number;

	while(true)
	{
		std::cout << "We need an integer equal or greater than "
			  << min << "!\n";
		getInt(&number);
		// break the loop if the input meets min value requirement 
		if(number >= min)
			break;
		//continue loop if input doesnot meet requirement
		std::cout << "Invalid input! Please try again!" << std::endl;
		std::cin.clear();
	}
	*variable = number;
} 


/****************************************************************************
** Description: This function checks and takes an integer using the getInt
		function, then validates and assigns to the receiving variable 
		if it is within the range specified as parameters   
****************************************************************************/ 
void getIntInRange(int* variable, int min, int max)
{
	int number;
	
	while(true)
	{
		std::cout << "We need an integer between " << min
			  << " and " << max << "!\n";
		getInt(&number);
		
		// break the loop if the input within specified range
		if((number <= max) && (number >= min)) 
			break;
		std::cout << "Invalid input! Please try again!" << std::endl;
		std::cin.clear();
		
	}
 
 	*variable = number;
}

