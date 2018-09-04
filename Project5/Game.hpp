/*********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the header file of the class Game, which has 
			data members of six spaces and one player, two menus, 
			and days indicating time limits for the game. It also 
			has functions to set up the game and simulates activities
			of user choices.      
**********************************************************************/

#ifndef Game_HPP
#define Game_HPP

#include <string>
#include <vector>
#include "Space.hpp"
#include "Desert.hpp"
#include "Sea.hpp"
#include "Forest.hpp"
#include "Island.hpp"
#include "Mountain.hpp"
#include "Town.hpp"
#include "Player.hpp"

class Game
{
	private:
		int days;
		Menu actionMenu;
		Menu moveMenu;
						
		Player* player;
		Space* town;
		Space* forest;
		Space* mountain;
		Space* desert;
		Space* sea;
		Space* island;
			
	public:
		Game();
		~Game();
		void setUp();	// set up the game before play 
		void checkMap();
		void move();
		void interact();
		void checkBag(); // check the items in the bag
		void play();	// play the game
	
};


#endif
