/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
**Description:  This is the header file for class Game, the Game class
		has member variables of two teams and one loser container,
		and integer scores for each team. It also hasfunctions 
		to creates the team of fighters from user choice, and 
		simulates the game until one team has no fighter left.      
**********************************************************************/

#ifndef Game_HPP
#define Game_HPP

#include <string>
#include <vector>
#include "Character.hpp"
#include "Team.hpp"

class Game
{
	private:
		Team TeamA, TeamB;
		Team loser;
		int scoreA, scoreB;
		
	public:
		Game();
		~Game();
		void showInstruction();
		void setUp();	// set up the game before play 
		void fight(Character*, Character*);
		void battle(Character*, Character*);
		void play();	// play the game
};


#endif
