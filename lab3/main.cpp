/****************************************************************************
** Program name: Dice-rolling War Game
** Author:       Chen Zou
** Date:         16 April 2018        
** Description:  This program simulates a dice rolling game. The game is a 
		 2-player game played through dice. The player who rolls higher
		 number gets a point. The program will create players with a 
		 normal die or a loaded die, as specified by user, then play
		 the game for user specified number of rounds. It displays 
		 results for each rounds and final results after all rounds
		 are finished.
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "inputValidation.hpp"  

int main()
{
	// create menus for the program and fill the items
	Game game;
	game.addMenuItem("Play Game");
	game.addMenuItem("Exit Game");
	
	// diaplay instruction and menu items
	game.showMenu();  

	// get user choice
	int choice;
	choice = game.getUserChoice();

	// quit if user choose to exit
	if(choice == 2)
	{
		std::cout << "\nYou have chosen to quit, bye!\n";
		return 0;
	}
	
	// if user choose to play, set up and play the game			
	else	
	{	
		srand(time(0));
		game.setUp();
		game.play();
		
	}

	return 0;
}	
