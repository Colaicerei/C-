/****************************************************************************
**Program name:  Fantasy Combat Game
**Author:        Chen Zou
**Date: 		 2 May 2018        
** Description:  This program simulates a combat between two fantasy
		characters. it allows user to test if characters are fightling
		as expected, and prompt user to select teo fighters, run 
		combat until one fighter is dead.
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"  

int main()
{
	Game game;
	int fighter1, fighter2;	
	int choice;
	// create menus for the replay and fill the items
	Menu mainMenu;
	Menu replayMenu;
	mainMenu.add("Vampire");
	mainMenu.add("Barbarian");
	mainMenu.add("Blue Men");
	mainMenu.add("Medusa");
	mainMenu.add("Harry Potter");
	replayMenu.add("Play again");
	replayMenu.add("End the game");
	
	std::cout << "This game includes five fantasy characters. \n"
			  << "Press 1 to have a quick inspection about the characters, 2 to skip. \n";
	getInt(&choice);
	if(choice == 1)
	{
		game.test();
		std::cout << "Good news, seems like no one is cheating! The game can start now!\n\n";
	}
	
	// diaplay instruction
	game.showInstruction();
	
	srand(time(0));
	do
	{	
		mainMenu.display();
		std::cout << "Please pick fighter 1 for the combat. ";
		fighter1 = mainMenu.getUserChoice();
		std::cout << "Please pick fighter 2 for the combat. ";
		fighter2 = mainMenu.getUserChoice();
		game.play(fighter1, fighter2);
				
		//show replay menu at end of combat and get user choice
		std::cout << "\nThe combat is over, please choose an option:\n\n";
		replayMenu.display();
		choice = replayMenu.getUserChoice();

		// delete character for previous combat
		game.~Game();
		
	}while(choice == 1);
	
	// quit if user choose to exit
	std::cout << "\nYou have chosen to end the game, bye!\n";
	
	return 0;
}	


