/****************************************************************************
** Program name: Recursive functions
** Author:       Chen Zou
** Date:         1 May 2018        
** Description:  This program prompts user to choose a recusive function,
			then get the inputs for the recusrive function user 
			selected and displays the results.
****************************************************************************/

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "recursive.hpp"
#include "inputValidation.hpp"  

void fillArray(int*, int);

int main()
{
	Menu menu;

	menu.add("Print String In Reverse");
	menu.add("Calculate Sum of Array");
	menu.add("Calculate Triangular Number");
	menu.add("Exit");
	
	int choice;
	std::cout << "\nPlease choose a function you would like to use.\n";

	menu.display();
	choice = menu.getUserChoice();

	std::string inputStr; // input string to take user input
	int size; 		// size of array
	int* array;		// pointer to array
	int number;		// number for triangular calculation	
	while(choice != 4)
	{
		switch(choice)
		{
				// prompt user to enter a string
		case 1: inputStr = menu.promptStr("Please enter a string: ");
				std::cout << "The reverse string is ";
				printReverse(inputStr);
				break;

		case 2: size = menu.promptInt("Please enter the size of the array. ");
				array = new int[size];
				fillArray(array, size);
				std::cout << "The sum of the array you entered is: "
						  << sumArray(array, size) << std::endl;
				delete [] array;
				array = NULL;		  
				break;
				
		case 3: number = menu.promptInt("Please enter a number for triangular. ");
				std::cout << "The triangular for number " << number << " is: " 
						  << triangular(number) << std::endl;
				break;
		
		case 4: std::cout << "You have chosen to exit the program, bye!\n";
				return 1;
		}
		
		std::cout << "\nWould you like to try another option?\n";
		menu.display();
		choice = menu.getUserChoice();
		
	}	
		
	return 0;
}	


/****************************************************************************
**  This function takes an array and size, then promote user and fill the 
	array with user input.
****************************************************************************/
void fillArray(int* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << "Please enter a number for " << i+1 << "st element:";
		getInt(array + i);
	}	
	
}