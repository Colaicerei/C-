/****************************************************************************
** Program name: Dice-rolling War Game
** Author:       Chen Zou 
** Date:         16 April 2018
** Description:  This is the function impliementation file of the class Game,
                 which has four data members: a string vector of menu items,
		 an integer rounds for play, and pointers to dice to reprensent
		 players. The class has functions to create and display the menu,
		 takes input from user and create players, simulation the game 
		 and output the results for each round and for the final.  
****************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "inputValidation.hpp"


// constructor
Game::Game()
{ 
	rounds = 0;     //initialize the total rounds to 0
	player1 = NULL; // initialize the player pointers to null
	player2 = NULL;
}		


/***************************************************************************
** This function adds user specified item to the item list.
***************************************************************************/
void Game::addMenuItem(std::string newItem)
{
	menuList.push_back(newItem);
}


/**************************************************************************
** This function removes item of user specified index from the menu.
**************************************************************************/ 
void Game::removeMenuItem(int itemNumber)
{
	menuList.erase(menuList.begin() + itemNumber - 1);
}


/***************************************************************************
** This function displays the instruction and the menu for the game.
***************************************************************************/
void Game::showMenu()
{
	std::cout << "Welcome to the Dice-rolling War Game, it is a\n"
		  << "2-player game played through dice. The player who\n"
		  << "rolls higher number gets one point. If both players\n"
		  << "roll the same number, it is considered a draw and no\n"
		  << "one gets a point.\n\n" 
		  << "Please select from the following options:\n\n";

	for(int i = 0; i < menuList.size(); i++)
	{
		std::cout << i+1 << ". " << menuList[i] << "\n";
	}	
}


/***************************************************************************
** This function takes the game information from the user and creates 
   players for the game.
***************************************************************************/
void Game::setUp()
{
	int type1, type2;   // type of die for each player
	int sides1, sides2; // number of sides of dice for each player

	// promote user and get rounds to play 
	std::cout << "Enter the total rounds to play. ";
	getIntWithMax(&rounds, 1000);

	// promote and get type of dice from user 
	std::cout << "Enter the type of die for player 1.\n"
		  << "Enter 1 for normal die, 2 for loaded die: ";
	getIntFromTwo(&type1, 1, 2);

	std::cout << "Enter the type of die for player 2.\n"
		  << "Enter 1 for normal die, 2 for loaded die: ";
	getIntFromTwo(&type2, 1, 2);
	
	// promote and get number of sides from user
	std::cout << "Enter the number of sides for player 1. ";
	getIntWithMin(&sides1, 3);
	
	std::cout << "Enter the number of sides for player 2. ";
	getIntWithMin(&sides2, 3);

	// dynamically create die object for player1	
	if(type1 == 1)
	{
		player1 = new Die;
		player1->setSides(sides1);
	}
	else
	{
		player1 = new LoadedDie;
		player1->setSides(sides1);
	}

	// dynamically create die object for player2
	if(type2 == 1)
	{
		player2 = new Die;
		player2->setSides(sides2);
	}
	else
	{
		player2 = new LoadedDie;
		player2->setSides(sides2);
	}
	
}


/***************************************************************************
** This function simulates dice-rolling for the user specified rounds, and 
   output the detailed results of each rounds. The function also displays
   the final score count and final winner at the end of the game.
***************************************************************************/
void Game::play()
{
	int score1 = 0; // score for player 1
	int score2 = 0; // score for play 2
	int draw = 0;   // number of draws 
	int n1, n2;     // number of sides each player rolled 
	
	for(int i = 0; i < rounds; i++)
	{
		n1 = player1->roll();
		n2 = player2->roll();

		std::cout << "\nRound " << i+1 << " results:\n" << "Player 1 rolled " 
			  << n1 << " with " << player1->getType() << ", Player 2 rolled " 
			  << n2 << " with " << player2->getType() << "\n";
		
		if(n1 > n2)
		{
			std::cout << "The winner for this round is Player 1.\n";
			score1 ++;		  
		}
		else if(n1 < n2)
		{
			std::cout << "The winner for this round is Player 2.\n";
			score2 ++;
		}
		else
		{
			std::cout << "We have a draw this round!\n";
			draw++;
		}
	}

	std::cout << "\nGame Over! The final scores are: " << "Player 1: " << score1 
			  << ", Player 2: " << score2 << ", " << draw << " draws.\n"; 

	if(score1 > score2)
	{
		std::cout << "The winner is Player 1.\n";
	}
	else if(score1 < score2)
	{
		std::cout << "The winner is Player 2.\n";
	}	
	else
	{
		std::cout << "It's a draw.\n";
	}	   

	// delete player pointers to free memory
	delete player1;
	delete player2;
}


/***************************************************************************
** This function asks user for choices, then validates and returns the choice
   until a valid input is entered.
***************************************************************************/ 	  
int Game::getUserChoice()
{
	std::cout <<  "\nPlease enter your choice.\n";
	int choice;
	getInt(&choice);

	while(choice < 1 || choice > menuList.size())
	{
		std::cout << "\nChoices must be between 1 and " << menuList.size()
			  << ". " << "Please re-enter choice.\n";
		getInt(&choice);
		std::cin.clear();
	}
	 
	return choice;
}
