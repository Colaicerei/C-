/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Town,
		 which inherits from class Space. The class has override
		 interact function. 
***************************************************************************/
#include "Town.hpp"
#include <iostream>

// constructor
Town::Town(std::string type) : Space (type)
{

}


// destructor
Town::~Town()
{
	
}


/***************************************************************************
**  This function simulates the interact at Town.
***************************************************************************/
void Town::interact(Player* player)
{
	if(visited)
	{
		std::cout << "\nGlad to see you back, people want to know if you have found all ingredients?\n";
			
	}
	else
	{
		visited = true;
		std::cout << "\nEveryone in the town looked desperate. You met the oldest witch in the world, she said she "
				  << "need all necessary ingredients to cast the spell, nothing less will work!\n";
	}

	// check if player has got everthing 
	if(player->ingredientsGet())
	{
		std::cout << "You have found everthing required to cast the spell, everyone is in the church and waiting nervously.\n"
				  << "The witch put the ingredients into a holy Grail and casted the spell, after a flash, a rift slowly emerged.\n";
		player->setGameWin(true);		  
	}
	else
	{
		std::cout << "Since you have not got all ingredients, you need to look around!\n";
	}
	
}

			