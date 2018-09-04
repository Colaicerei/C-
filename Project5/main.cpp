/****************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018      
** Description:  This is the main program for the Apocalypse game, the player
		needs to find three ingredients to open a path to an 
		alternate world to save people in the Apocalypse world.
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Space.hpp"
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
	std::cout << "\nApocalypse has arrived, the word is coming to its end. There are only hundreds of people left and they\n"
		  << "are all gathered in this last town on the earth, where the ancient prophets recorded as “last hope for human”.\n" 
		  << "The Dead Sea Scroll which was discovered a thousand years ago were interpreted, it shows the only way\n"
		  << "to survive is to open a path to an alternate universe – the Real World (you do not know what it is.\n"
		  << "You will need to collect the ingredients needed to cast the spell to open the path.\n"
		  << "The ingredients are: Fruit from the Tree of Life, Grace of Archangel, Seal of Solomon.\n\n"
		  << "You need to explore the town and surrounding area to find the three ingredients.\n"
		  << "You have limited days till the end of the world, you will only be able to make one move each day.\n\n"
		  << "Game Win: complete all tasks before the world ends\n"
		  << "Game Lose: The world ends before you complete task or you get killed\n\n"
		  << "TA HINT – Go to Forest first to get extra life and useful tool for future tasks to avoid having to come back.\n\n";
		  //<< "Leave items in the town after you get them, to avoid bag full.\n\n"
		
	srand(time(0));
	
	mainMenu.display();
	choice = mainMenu.getUserChoice();
	
	while(choice == 1)
	{	
		Game game;
		game.play();
				
		//show replay menu at end of game and get user choice
		std::cout << "\nGame Over! Would you like to play again?\n\n";
		replayMenu.display();
		choice = replayMenu.getUserChoice();

	}
	
	// quit if user choose to exit
	std::cout << "\nYou have chosen to quit the game, bye!\n";
	
	return 0;
}	


