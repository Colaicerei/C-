/****************************************************************************
** Program name: Stack and Queue STL Containers
** Author:       Chen Zou
** Date:         30 May 2018        
** Description:  This program provides user the options to simulate a buffer
			using Queue container, or create a palindrome using stack
			container. 
****************************************************************************/

#include <iostream>
#include <string>
#include "StackNQueue.hpp"
#include "Menu.hpp"
#include <cstdlib>
#include <ctime>
#include "inputValidation.hpp"  

int main()
{
		
	// create menu
	Menu menu;
	int choice;
	srand(time(NULL));
	
	menu.add("Simulate Buffer");
	menu.add("Create Palindrome");
	menu.add("Exit");
	menu.display();

	choice = menu.getUserChoice();

	int pctAdd;
	int pctRM;
	int rounds;
	std::string inputStr;

	while(true)
	{
		switch(choice)
		{	
			case 1:	pctAdd = promptIntInRange("Please enter the percentage of chance to put a random number at the end of buffer. ", 0, 100);
					pctRM = promptIntInRange("Please enter the percentage of chance to remove a random number at the fronf of buffer. ", 0, 100);
					rounds  = promptPInt("Please enter the total number of rounds: ");
					buffer(pctAdd, pctRM, rounds);
					break;
			case 2: inputStr = promptString("Please enter the a string: ");
					std::cout << "The palindrome created is: " << palindrome(inputStr);
					break;
			case 3: std::cout << "You have chosen to exit the program, bye!\n";
					return 1;
		}
	
		std::cout << "\nWould you like to make another choice?\n";
		menu.display();
		choice = menu.getUserChoice();
	}	
		
	return 0;

}	

