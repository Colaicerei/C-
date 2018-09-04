/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Island,
		 which inherits from class Space. The class has override
		 interact function. 
***************************************************************************/
#include "Island.hpp"
#include "Player.hpp"
#include <iostream>


// constructor
Island::Island(std::string type) : Space (type)
{

}


// destructor
Island::~Island()
{
	
}

/***************************************************************************
**  This function simulates the interact at Island.
***************************************************************************/
void Island::interact(Player* player)
{
	
	// nothing happens at second visit, for first visit you found and took the seal
	if(visited)
	{
		std::cout << "\nYou have taken the Seal of Solomon! "
				  << "There is nothing else here to take!\n";
		std::cout << "There is nothing to add to bag!\n";		  
	}
	else
	{
		std::cout << "\nYou arrived the island sucessfully, you found the Seal of Solomon is protected by a sleeping python.\n"
				  << "You decided to steal the Seal before it is waken up. Now you are walking slowly towards the Seal...\n";
		visited = true;
		int awake = rand() % 2 + 1;  // randomly generate chance for the python to be waken up
		if(!awake)	// steal the seal quietly if python is not awake
		{
			std::cout << "\nYou are lucky, the python is in deep sleep and didnot wake up!\n";
			player->addToBag("Seal of Solomon");
		}		  
		else
		{
			std::cout << "Oh no, you stepped onto it tail and the python is now awake!\n";
			Menu menu;
			menu.add("Fight it");
			menu.add("Talk to it");
			menu.display();
			int choice = menu.getUserChoice();
			if(choice == 1) //simulates fight with python
			{
				int playerDice = rand() % 2;  // python attacks more powerful than player
				int pythonDice = rand() % 3;

				if(playerDice > pythonDice)
				{
					std::cout << "\nPython tossed you up high, you dropped onto its head, it is knocked out because of your weight!\n";
					player->addToBag("Seal of Solomon");
				}
				else if(pythonDice > playerDice)
				{
					std::cout << "\nThe Python is too strong, you are killed by the Python!\n";
					// player use mushroom and back to life, and get fruit from the other tree
					if(player->getMushroom() > 0)
					{
						std::cout << "\nYou used one mushroom to go back to life.\n"
								  << "Python went back to sleep after the fight, you get the Seal of Solomon.\n";	
						player->setMushroom(player->getMushroom() - 1);
						player->addToBag("Seal of Solomon");
					}
					else
					{
						std::cout << "\nYou have no mushroom to restore your life.\n";
						player->setLive(false);
					}

				}
				else // if dice same
				{
					std::cout << "\nThe python swallowed you too fast and choked to death because you are too fat.\n";
					// player use mushroom and back to life, and get fruit from the other tree
					if(player->getMushroom() > 0)
					{
						std::cout << "\nYou used one mushroom to go back to life.\n"
								  << "You climbed out from the python's mouth and get the Seal of Solomon.\n";	
						player->setMushroom(player->getMushroom() - 1);
						player->addToBag("Seal of Solomon");
					}
					else
					{
						std::cout << "\nYou have no mushroom to restore your life.\n";
						player->setLive(false);
					}
				}
			}
			else // talk to python
			{
				std::cout << "\nYou asked the python to give the human race one last chance, "
						  << "He talked to the Seal of Solomon with language you donot know, you are waiting nervously.\n"
						  << "Finally, the python nodded his head to the Seal and gave it to you.\n";
				player->addToBag("Seal of Solomon");		  
			}

		}

		

	}	

}



