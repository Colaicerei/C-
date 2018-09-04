/**************************************************************************
** Program name: Recursive functions
** Author:       Chen Zou
** Date:         5 May 2018
**Description:  This is the header file for class Menu, the Menu class
		has functions to validate and take user choice, add
		or remove user specified menu items, and display and 
		clear the menu, and prompt user for string or integer
		input with a message.                       
**************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Menu.hpp"
#include "inputValidation.hpp"


// constructor
Menu::Menu()
{ 
	setTitle(" ");
} 


/***************************************************************************
** This function sets the title of the menu.
***************************************************************************/ 
void Menu::setTitle(std::string menuTitle)
{
	title = menuTitle;
}


/**************************************************************************
** This function returns the title of the menu.
**************************************************************************/
 
std::string Menu::getTitle()
{
	return title;
}


/***************************************************************************
** This function add user specified item to the item list.
***************************************************************************/
void Menu::add(std::string newItem)
{
	list.push_back(newItem);
}


/**************************************************************************
** This function removes item of user specified index from the menu.
**************************************************************************/ 
void Menu::remove(int itemNumber)
{
	list.erase(list.begin() + itemNumber - 1);
}


/*************************************************************************
** This function clears the menu
*************************************************************************/ 
void Menu::clear()
{
	list.clear();
}


/***************************************************************************
** This function displays the list of items in the menu
***************************************************************************/
void Menu::display()
{
	std::cout << "Please choose from the following options:\n";
	for(unsigned int i = 0; i < list.size(); i++)
		std::cout << i+1 << ". " << list[i] << "\n";
} 	


/***************************************************************************
** This function asks user for choices, then validates and returns the choice
   until a valid input is entered.
***************************************************************************/ 	  
int Menu::getUserChoice()
{
	std::cout <<  "\nPlease enter your choice.\n";
	int choice;
	getInt(&choice);

	while(choice < 1 || choice > (int)list.size())
	{
		std::cout << "\nChoices must be between 1 and " << list.size()
			  << ". " << "Please re-enter choice.\n";
		getInt(&choice);
		std::cin.clear();
	}
	 
	return choice;
}


/***************************************************************************
** This function prompt user to input an int with a message.
***************************************************************************/ 	  
int Menu::promptInt(std::string promptMsg)
{
	std::cout << promptMsg;
	int input;
	getIntWithMin(&input, 1);
	return input;
}


/***************************************************************************
** This function prompt user to input a string with a message.
***************************************************************************/
std::string Menu::promptStr(std::string promptMsg)
{
	std::cout << promptMsg;
	std::string inputStr;
	std::getline(std::cin, inputStr);
	return inputStr;
}