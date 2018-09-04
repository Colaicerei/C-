/**************************************************************************
** Program name: Stack and Queue STL Containers
** Author:       Chen Zou
** Date:         30 May 2018  
** Description:  This is the function impliementation file of the class Menu,
         the Menu class has two data members: menu title, and a string
		 vector of  menu  items. The class has functions to add, and
		 remove items from the list, display and clear menu, and
		 function to validate and take choices from user.                         
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
** This function displays the title of the menu.
***************************************************************************/ 
void Menu::showTitle()
{
	std::cout << getTitle() << "\n\n";
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
	getIntInRange(&choice, 1, list.size());

	/*while(choice < 1 || choice > (int)list.size())
	{
		std::cout << "\nChoices must be between 1 and " << list.size()
			  << ". " << "Please re-enter choice.\n";
		getInt(&choice);
		std::cin.clear();
	}*/
	 
	return choice;
}
