/****************************************************************************
** Program name: OSU Information System
** Author:       Chen Zou
** Date:         27 April 2018        
** Description:  This program is a simple representation for Oregon State
			University which contains information about building and 
			people. It allows user to add people to the system, print
			information about building and people, and allow user to
			pick person to work.
****************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "University.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"  


int main()
{
	University osu;
	std::string newPersonName;
	std::string newPersonType;
	
	int choice;
	std::cout << "\nWelcome to OSU information system. Below is the list "
			  << "of current people's information:\n\n";

	osu.printPeople();
	
	std::cout <<"\nWould you like to add more people to the system? "
			  << "Enter 1 for yes, 2 for no.\n";

	getInt(&choice);
	while(choice == 1)
	{
		// promote user to add more people
		std::cout << "Please enter the person's name you would like to add.\n";
		getString(&newPersonName);

		std::cout << "Please enter the person's type, student or instructor?\n";
		getString(&newPersonType);

		osu.addPerson(newPersonName, newPersonType);

		std::cout << "Would you like to add more people to the system? "
				  << "Enter 1 for yes, 2 for no.\n";
		getInt(&choice);		
	}

	// save updated people information to file
	osu.saveFile("OSUPeople.txt");
	
	// create the main menu and fill the items
	Menu mainMenu;
	mainMenu.add("Prints information about all the buildings");
	mainMenu.add("Prints information of everybody at the university");
	mainMenu.add("Choose a person to do work");
	mainMenu.add("Exit the program");

	// create menu for option 3
	Menu option3Menu;
	std::string person2Work;

	srand(time(0));

	mainMenu.display();
	// get user choice for main menu
	choice = mainMenu.getUserChoice();

	while(true)
	{
		switch(choice)
	{	
		case 1: osu.printBuilding();
				break;
		case 2: osu.printPeople();
				break;
		case 3: option3Menu.pickWorker();//display all names and ask user to pick
				osu.printName();
				getString(&person2Work); //get user choice of person
				osu.makeWork(person2Work);   //make theselected person work
				break;
		case 4: std::cout << "You have chosen to exit the program, bye!\n";
				return 1;
	}
		std::cout << "\nWould you like to make another choice?\n";
		mainMenu.display();
		choice = mainMenu.getUserChoice();
	}	
		
	return 0;
}	
