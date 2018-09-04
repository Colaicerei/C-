/****************************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018       
** Description:  This program simulates a combat between two fantasy
		characters. it allows user to test if characters are fightling
		as expected, and prompt user to select teo fighters, run 
		combat until one fighter is dead.
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Team.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"  

int main()
{
	int choice;
	// create menus for the replay and fill the items
	Menu mainMenu;
	
	Menu replayMenu;
	// fill main menu
	mainMenu.add("Play");
	mainMenu.add("Exit");	
	
	// fill replay menu
	replayMenu.add("Play again");
	replayMenu.add("Exit");
	
	// display instruction
	std::cout << "			\nWelcome to the Fantasy Combat Tournament!\n"
		  << "In this game, you will run a tournament between two teams of " 
		  << "fighters. You will choose the size and player for each team.\n"
		  << "The fighers from each team will fight in lineup order, the "
		  << "winner goes back to their team and recover, while loser goes to "
		  << "the loser container.\n"
		  << "The tournament finishes when one of the team does not have any "
		  << "fighters left.\n\n";
		
	srand(time(0));
	
	mainMenu.display();
	getInt(&choice);
	
	while(choice == 1)
	{	
		Game game;
		game.play();
				
		//show replay menu at end of tournament and get user choice
		std::cout << "\nThe tournament is over, please choose an option:\n\n";
		replayMenu.display();
		choice = replayMenu.getUserChoice();

	}
	
	// quit if user choose to exit
	std::cout << "\nYou have chosen to end the game, bye!\n";
	
	return 0;
}	


