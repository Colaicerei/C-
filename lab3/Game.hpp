/*********************************************************************
**Program name: Dice-rolling War Game
**Author:       Chen Zou
**Date: 	16 April 2018
**Description:  This is the header file for class Game, the Game class
		has functions to create and display menu, takes user
		input with validation, then creates the players and 
		simulates the game for user specified round and output 
		results and winner for each round and final.      
**********************************************************************/

#ifndef Game_HPP
#define Game_HPP

#include <string>
#include <vector>
#include "Die.hpp"

class Game
{
	private:
		std::vector<std::string> menuList; 
		int choice;	// user choice	
		int rounds;	// round to play 
		Die* player1;	// pointers to die object
		Die* player2;
				

	public:
		Game();
		void addMenuItem(std::string);
		void removeMenuItem(int);
		void showMenu();
		void setUp();	// set up the game before play 
		void play();	// play the game
		int getUserChoice();
		
};


#endif
