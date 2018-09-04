/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Desert,
		 which inherits from class Space. The class has override
		 interact function. 
***************************************************************************/
#include "Desert.hpp"
#include <iostream>

// constructor
Desert::Desert(std::string type) : Space (type)
{

}


// destructor
Desert::~Desert()
{
	
}

/***************************************************************************
**  This function simulates the interact at Desert.
***************************************************************************/
void Desert::interact(Player* player)
{
	if(visited)
	{
		std::cout << "\nThe only fruit from Tree of Life has been taken by you! "
				  << "You decided not to touch the Tree of Death!\n";
		std::cout << "There is nothing to add to bag!\n";		  
	}
	else
	{
		std::cout << "You found two trees in the Desert, one is tree of life, the other is the tree of death.\n"
			  << "You die if you touch the tree of death, which tree would you choose?\n";
		visited = true;	  
		Menu menu;
		menu.add("Tree No.1");
		menu.add("Tree No.2");
		menu.display();
		int choice = menu.getUserChoice();

		int rightTree = rand() % 2 + 1;  // randomly generate right tree for your choice
		if(choice == rightTree)
		{
			std::cout << "\nCongratulations, you picked the right tree!\n";
			player->addToBag("Fruit from Tree of Life");
		}		  
		else
		{
			std::cout << "\nOops, you touched the Tree of Death!\n";
			// player use mushroom and back to life, and get fruit from the other tree
			if(player->getMushroom() > 0)
			{
				std::cout << "\nYou used one mushroom to go back to life.\n"
						  << "You picked up the fruit from the other tree.\n";	
				player->setMushroom(player->getMushroom() - 1);
				player->addToBag("Fruit from Tree of Life");
			}
			else
			{
				std::cout << "\nYou have no mushroom to restore your life.\n";
				player->setLive(false);
			}	
		}
	}
}


