/*********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
**Description:  This is the header file for class Game, the Game class
		has member variables of pointers to fighter characters, 
		and functions to creates the fighters from of user
		choice, and simulates the game untill one fighter
		is dead.      
**********************************************************************/

#ifndef Game_HPP
#define Game_HPP

#include <string>
#include <vector>
#include "Character.hpp"

class Game
{
	private:
		Character* fighter1;	// pointers to characters
		Character* fighter2;
				

	public:
		Game();
		~Game();
		void showInstruction();
		void setUp(int, int);	// set up the game before play 
		void fight(Character*, Character*);
		void play(int, int);	// play the game
		void test();			// test if characters are rolling as expected
};


#endif
