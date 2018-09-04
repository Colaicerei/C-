/****************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function impliementation file of the class Game,
            which has data members of six spaces and one player,
			and days indicating time limits for the game. It also 
			has functions to set up the game and simulates activities
			of user choices.   
****************************************************************************/

#include <string>
#include <iostream>
#include "Game.hpp"
#include "Space.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"


// constructor
Game::Game()
{ 
	// set up and link spaces
	town = new Town("Town");
	forest = new Forest("Forest");
	mountain = new Mountain("Mountain");
	desert = new Desert("Desert");
	sea = new Sea("Sea");
	island = new Island("Island");
	player = new Player();

	town->setLeft(forest);
	forest->setRight(town);
	town->setTop(mountain);
	mountain->setBottom(town);
	town->setBottom(desert);
	desert->setTop(town);
	town->setRight(sea);
	sea->setLeft(town);
	sea->setRight(island);
	island->setLeft(sea);

	// set Player starting location
	player->setLocation(town);
}		

Game::~Game()
{
	delete town;
	delete forest;
	delete mountain;
	delete desert;
	delete sea;
	delete island;
	delete player;
}


/***************************************************************************
**  This function set up the game menu for actions and movements. it also 
	allows user to choose the time limit.
***************************************************************************/
void Game::setUp()
{
	// create menu for actions
	actionMenu.add("Check Map");
	actionMenu.add("Move");
	actionMenu.add("Interact");
	actionMenu.add("Check Bag");
	actionMenu.add("Exit");
	
	// create menu for movement
	moveMenu.add("Top/North");
	moveMenu.add("Bottom/South");
	moveMenu.add("Left/West");
	moveMenu.add("Right/East");
	
	//reset game status and player life status
	player->setLive(true);
	player->setGameWin(false);
	
	// prompt user to set up days
	days = promptPInt("\nFor TA - enter the days you need to complete the task (minimum 11, >20 for testing movements).\n");
}


/***************************************************************************
**  This function simulates the movement of user choice.
***************************************************************************/
void Game::move()
{
	// player.getLocation()->checkMap();
	
	std::cout << "\nWhich direction do you want to go?" << std::endl;
	moveMenu.display();
	int direction = moveMenu.getUserChoice();
	// cannot accross the sea to the island on the east without magic wood
	if(player->getLocation()->getType() == "Sea" && direction == 4)
	{
		if(!player->hasWood())
		{
			std::cout << "\nYou cannot across the sea without boat! You have to go back to find a boat!\n";
			return;
		}
		else
		{
			// player to leave the wood here to have enough room for necessary ingredients
			player->removeItem("Magic Wood");
			std::cout <<"\nLuckily, you already got magic woods that can become a boat once it touches water!\n";
			std::cout << "You put the Magic Wood on water and jumped onto it!\n";
			std::cout << "You do not have time to figure out how to shrink the boat back to wood. You decided to leave the boat here.\n";
		}
	}
	
	player->move(direction);
	player->getLocation()->checkMap();
	
}


/***************************************************************************
**  This function simulates the game with user selected actions of check map, 
	move, interact, check bag or quit the game.
***************************************************************************/
void Game::play()
{
	setUp();
	
	// loop until no time or player dead or gamewin
	while(days > 0 && player->isAlive() && !player->getGameWin())
	{
		std::cout << "\nPlease choose an action: \n";
		
		actionMenu.display();
		int choice = actionMenu.getUserChoice();

		switch(choice)
		{
			case 1: player->getLocation()->checkMap();
					break;
			case 2: move();
					days--; // one move per day
					std::cout << "\nYou have " << days << " days left!\n";
					break;
			case 3: interact();
					break;
			case 4: player->checkBag();
					break;
			case 5: std::cout << "You have chosen to exit, bye!";
					exit(0);							
		}
		
	}
	// show message if game win
	if(player->getGameWin())
	{
		std::cout << "\nCongratulation, you have saved all NPCs! Welcome to the real world!\n";
	}
	// show message if user is killed
	if(!player->isAlive())
	{
		std::cout << "\nOh no! You are killed for real! No one can save the world now!\n";
	}

	// show message for out of time if days == 0
	if(days == 0)
	{
		std::cout << "\nYou are out of time, the world is completely destroyed!\n";
	}
	
}


/***************************************************************************
**  This function simulates the interact happening at difference locations.
***************************************************************************/
void Game::interact()
{
	
	// interact in Mountain where you find Archangel Grace
	if (player->getLocation()->getType() == "Mountain")
	{
		mountain->interact(player);
				
	}

 	// interact in Desert where you eat one mushroom for each visit but only one magic wood
	if (player->getLocation()->getType() == "Forest")
	{
		forest->interact(player);
		
	}

	// interact in Desert where you need to find Fruit of Tree of Life
	if (player->getLocation()->getType() == "Desert")
	{
		desert->interact(player);
		
	}

	if (player->getLocation()->getType() == "Town")
	{
		town->interact(player);
		
	}

	// interact at sea 
	if (player->getLocation()->getType() == "Sea")
	{
		sea->interact(player);
		
	}

	// interact at island where you found seal of solomon for the first visit
	if (player->getLocation()->getType() == "Island")
	{
		island->interact(player);
		
	}
}

