/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Forest,
		 which inherits from class Space. The class has override
		 interact function. 
***************************************************************************/
#include "Forest.hpp"
#include <iostream>

// constructor
Forest::Forest(std::string type) : Space (type)
{
	//item = new Item("Magic Wood";

}

// destructor
Forest::~Forest()
{
	
}


/***************************************************************************
**  This function simulates the interact at Forest.
***************************************************************************/
void Forest::interact(Player* player)
{
	// no wood taken at second visit but get one mushroom to eat for each visit
	if(visited)
	{
		std::cout << "\nThe magicwood were taken by you on your previous visit! But you found another mushroom!\n"
				  << "You donot want to fill your bag with other nnecessary things becasue of its limited capacity.\n";
		player->eatMushroom();
	}
	else
	{
		std::cout << "\nYou have found a Magic Wood which might be useful.\n"
				  << "You also found and ate a magic mushroom which can give you an extra life.\n";
		visited = true;
		player->addToBag("Magic Wood");
		player->eatMushroom();
	}

}