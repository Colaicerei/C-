/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Sea,
		 which inherits from class Space. The class has override
		 interact function. 
***************************************************************************/
#include "Sea.hpp"
#include <iostream>
#include "Player.hpp"

// constructor
Sea::Sea(std::string type) : Space (type)
{

}


// destructor
Sea::~Sea()
{
	
}


/***************************************************************************
**  This function simulates the interact at Sea.
***************************************************************************/
void Sea::interact(Player* player)
{
	if(visited)
	{
		std::cout << "\nYou are at the sea again, kind reminder if you have taken the seal, "
				  << "there is nothing else on the island!\n";
	}
	else
	{
		std::cout << "\nThe sea is too deep and you cannot swim across it! "
				  << "You need to find Magaic Wood to get to the island!\n";
		visited = true;		  
	}
	
}

