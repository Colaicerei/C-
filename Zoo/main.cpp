/****************************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou
** Date:         19 April 2018        
** Description:  This program simulates a zoo business game, the game starts 
		by asking user to purchase 1 or 2 animal types to start the 
		business, it also allows user to buy and set new animal type
		in addition to tiger, penguin and turtle. It will let user to 
		run the zoo on daily basis, including feeding animals, having 
		random events, then calculate the profit for the day. It then
		promotes user to continue for next day or exit. The game is 
		over if user has no money.
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Menu.hpp"
//#include "inputValidation.hpp"  

int main()
{
	std::cout << "\nFor the assignment I did all extra credits\n";
	Game game;
	int choice;	
	int d = 0;  // days of running business
	// create menus for the replay and fill the items
	Menu replayMenu;
	replayMenu.add("Keep playing");
	replayMenu.add("End the game");
	// diaplay instruction
	game.showInstruction();  

	srand(time(0));
	
	// start business by purchasing animals
	game.startZoo();
		
	do
	{	
		// start game if user has money, game over if no money
		if(!game.hasMoney())
		{
			std::cout << "You are out of money, the game is over!"
					  << "Good luck next time!" << std::endl;
			return 1;		  
		}
		else
		{
			d++;
			std::cout << "Today is day " << d << std::endl;
			game.play();
				
			//show replay menu at end of daya and get user choice
			std::cout << "\nToday's work is completed, please choose an option:\n\n";
			replayMenu.display();
			choice = replayMenu.getUserChoice();
		}
	}while(choice == 1);
	
	// quit if user choose to exit
	std::cout << "\nYou have chosen to end the game, bye!\n";
	
	return 0;
}	

