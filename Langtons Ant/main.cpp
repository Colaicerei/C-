/****************************************************************************
** Program name: Langton's Ant
** Author:       Chen Zou
** Date:         8 April 2018        
** Description:  This program simulates the Langton's Ant movement. It promotes
		 the user to choose the size of the board, and the information
		 to run the simulation. It runs the simulation based on the 
		 user input and displays the board after each steps until all
		 steps run out.
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Menu.hpp"
#include "Board.hpp"
#include "Ant.hpp"
#include "inputValidation.hpp"  

int main()
{
	// create menus for the program and fill the items
	Menu startMenu;
	Menu replayMenu;
	startMenu.setTitle("LANGT'S ANT SIMULATION");
	startMenu.add("Start Langton's Ant Simulation");
	startMenu.add("Quit");
	replayMenu.add("Play again");
	replayMenu.add("Quit");


	// show title, instruction and menu items
	startMenu.showTitle();
	std::cout << "Welcome to the langton's Ant Simulation, the ant is\n"
		  << "placed on a board with white spaces, it will turn\n"
		  << "right 90 degrees if on a white space and change the\n"
		  << "space to black, and turn left 90 degrees if on a \n"
		  << "black space and change the space to white.\n\n" 
		  << "Please select from the following options:\n\n";
	startMenu.display();  

	// if user choice quit, exit the program
	int choice;
	choice = startMenu.getUserChoice();

	if(choice == 2)
	{
		std::cout << "\nYou have chosen to quit, bye!\n";
		return 1;
	}
	
	// declare the variables and get user input
	// for the information to run simulation
	int rows;
	int cols;
	int steps;
	int startRow;
	int startCol;
	int startDirection;
		
	while(choice == 1)
	{	
		std::cout << "\nPlease enter the number of rows for the board.\n";
		getIntWithMin(&rows, 2);

		std::cout << "\nPlease enter the number of columns for the board.\n";
		getIntWithMin(&cols, 2);

		std::cout << "\nPlease enter the total steps for the simulation.\n";
		getIntWithMin(&steps, 1);

		std::cout << "\nPlease enter a start direction(degree) for the ant.\n"
			  << "Please choose an integer from 0, 90, 180 and 270!\n";
		getInt(&startDirection);
		while(startDirection != 0 && startDirection != 90 &&
		      startDirection != 180 && startDirection !=270)
		{
			std::cout << "Error! Direction should be 0, 90, 180 or 270!\n";
			getInt(&startDirection);   
		}
  
		int randomStart;
		std::cout << "\nWe need a starting location for the ant, I can do\n"
			  << "a random one, or you can specify it if you wish.\n"
			  << "\nEnter 1 if you would like a random location.\n" 
			  << "Or, enter other number if you prefer to specify.\n ";

		getInt(&randomStart);
		if(randomStart != 1)
		{
			std::cout << "\nPlease enter the starting row of the ant.\n";
			getIntInRange(&startRow, 0, rows -1);

			std::cout << "\nPlease enter the starting column of the ant.\n";
			getIntInRange(&startCol, 0, cols - 1);  		
		}
		else
		{
			srand(time(0));
			startRow = std::rand() % rows;
			startCol = std::rand() % cols;
			std::cout << "\nRandom start location created!\n";
		}   

		// create an ant object with user input information
		Ant ant(rows, cols, steps, startRow, startCol, startDirection);

		ant.simulation();
		
		// promote user to replay or quit after simulation
		std::cout << "\nThe simulation is complete, please choose an option:\n\n";
		replayMenu.display();
		choice = replayMenu.getUserChoice();
		
	}

	std::cout << "\nYou have chosen not to play again, bye!\n";
  	
	return 0;
}

 
