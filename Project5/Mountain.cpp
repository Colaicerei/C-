/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Mountain,
		 which inherits from class Space. The class has override
		 interact function. 
***************************************************************************/
#include "Mountain.hpp"
#include <iostream>
#include "Player.hpp"

// constructor
Mountain::Mountain(std::string type) : Space (type)
{

}


// destructor
Mountain::~Mountain()
{
	
}


/***************************************************************************
**  This function simulates the interact at Mountain.
***************************************************************************/
void Mountain::interact(Player* player)
{
	// nothing happens at second visit
	if(visited)
	{
		std::cout << "\nThe mountain is detroyed after the Archangel's battle! "
				  << "There is nothing here!\n";
		std::cout << "There is nothing to add to bag!\n";		  
	}
	else
	{
		std::cout << "\nYou found Michael is fighting Lucifer on the top of mountain.\n"
			  << "What would you do?\n";
		visited = true;
		Menu menu;
		menu.add("Help Michael");
		menu.add("Help Lucifer");
		menu.add("Just sit and watch");
		menu.display();
		int choice = menu.getUserChoice();	
		
		int MichaelWin = rand() % 2; // random win between Michael or Lucifer
		if(MichaelWin)
		{
			// if Michael wins, he extract Lucifer's grace and give to you
			// regardless you helped him or not
			std::cout << "\nMichael defeated Lucifer and extracted the grace from Lucifer and gave to you.\n";
			player->addToBag("Archangel Grace");
		}
		else
		{
			// if Lucifer wins, you only get grace if you helped him, otherwise he will kill you
			if(choice == 2)			
			{
				std::cout << "\nLucifer won, because you helped him, he extracted Michael's grace and gave to you.\n";
				player->addToBag("Archangel Grace");
			}
			else
			{
				std::cout << "\nLucifer won, he found you and killed you!\n";
				// player use mushroom and back to life, and steal grace
				if(player->getMushroom() > 0)
				{
					std::cout << "\nYou are back to life because you ate one mushroom.\n"
							  << "Lucifer didnot know you were alive, you stolen the grace from Lucifer and escaped.\n";	
					player->setMushroom(player->getMushroom() - 1);
					player->addToBag("Archangel Grace");
				}
				else
				{
					std::cout << "\nYou have no mushroom to restore your life.\n";
					player->setLive(false);
				}	
				
			}	
		}
	}
}