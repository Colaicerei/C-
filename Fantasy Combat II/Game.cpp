/****************************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the function impliementation file of the class Game,
            which has data members of two teams and one loser container,
			and integer scores for each team. It also hasfunctions 
			to creates the team of fighters from user choice, and 
			simulates the game until one team has no fighter left.   
****************************************************************************/

#include <string>
#include <iostream>
#include "Game.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Team.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"


// constructor
Game::Game()
{ 
	scoreA = 0;
	scoreB = 0;
}		

Game::~Game()
{
}

/***************************************************************************
** This function displays the instruction of the game.
***************************************************************************/
void Game::showInstruction()
{
}


/***************************************************************************
**  This function takes the game information from the user and creates two 
	teams with user specified number and type of players for the game.
***************************************************************************/
void Game::setUp()
{
	// create and fill fighters list
	Menu fighters;
	int choice;
	fighters.add("Vampire");
	fighters.add("Barbarian");
	fighters.add("Blue Men");
	fighters.add("Medusa");
	fighters.add("Harry Potter");

	int teamASize, teamBSize;
	Character* fighter = nullptr;	
	std::string name;

	// prompt user for the number of fighters for each team
	teamASize = promptPInt("Please enter the number of fighters for Team A. ");
	teamBSize = promptPInt("Please enter the number of fighters for Team B. ");
	
	// prompt user for the type and name for the fighters for Team A
	for(int i = 0; i < teamASize; i++)
	{
		std::cout << "Please choose the type for Team A fighter " << i+1 << ":\n";
		fighters.display();
		choice = fighters.getUserChoice();
		// dynamically create fighter	
		switch(choice)
		{
			case 1: fighter = new Vampire();
					break;
			case 2: fighter = new Barbarian();
					break;
			case 3: fighter = new BlueMen();
					break;
			case 4: fighter = new Medusa();
					break;
			case 5: fighter = new HarryPotter();
		}		
		std::cout << "Please give Team A fighter " << i+1 << " a name: ";			
		// get name inpupt fron user and postfix with lineup ID
		std::getline(std::cin, name);
		name = "Team A Fighter No." + std::to_string(i+1) + " " + name;
		fighter->setName(name);
		// add fighter to TeamA
		TeamA.addBack(fighter);
	}

	// prompt user for the type and name for the fighters for Team B
	for(int i = 0; i < teamBSize; i++)
	{
		std::cout << "Please choose the type for Team B fighter " << i+1 << ":\n";
		fighters.display();
		choice = fighters.getUserChoice();
		// dynamically create fighter	
		switch(choice)
		{
			case 1: fighter = new Vampire();
					break;
			case 2: fighter = new Barbarian();
					break;
			case 3: fighter = new BlueMen();
					break;
			case 4: fighter = new Medusa();
					break;
			case 5: fighter = new HarryPotter();
		}		
		std::cout << "Please give Team B fighter " << i+1 << " a name: ";			
		// get name fron user and add team info and line up ID to the name
		std::getline(std::cin, name);
		name = "Team B Fighter No." + std::to_string(i+1) + " " + name;
		fighter->setName(name);
		// add fighter to TeamB
		TeamB.addBack(fighter);
	}
}


/***************************************************************************
**  This function simulates the tournament between two teams, the front 
	fighters of each team fights until one fighter is dead, the winner goes
	back to the end of the team and loser goes to loser pile. winner gets 
	two points while loser loses one point. 
***************************************************************************/
void Game::play()
{
	setUp();
	Character* fighterA;
	Character* fighterB;
	int round = 0; 
	while(!TeamA.isEmpty() && !TeamB.isEmpty())
	{
		round++;
		// get the fighters from the front of each team to fight
		fighterA = TeamA.getFront();
		fighterB = TeamB.getFront();
		std::cout << "\nRound " << round << ": " << fighterA->getName() 
				  << " VS " << fighterB->getName() << std::endl;
		battle(fighterA, fighterB);
		
		// prompt user to press enter to continue 
		std::cout << "Please press enter for next round...";
		std::string input;
		getline(std::cin, input);
    	std::cin.clear();
	}

	// display game results
	std::cout << "The game is finished, Team A score: " << scoreA
			  << ", Team B score: " << scoreB << std::endl;
	if(scoreA > scoreB)
	{
		std::cout << "The winner is Team A!\n";  
	}
	else if(scoreA < scoreB)
	{
		std::cout << "The winnner is Team B!\n";
	}
	else
	{
		std::cout << "It is a tie!\n";
	}

	// prompt user to choose to display loser pile
	int choice = promptInt("Enter 1 if you would like to check the loser pile. Other integer to pass.");
	if(choice == 1)
	{
		std::cout << "The loser pile has: ";
		loser.printQueue();
	}
}


/***************************************************************************
**  This function simulates the combat between two chosen characters, it 
	simulates fights until one character dies, calculate scores and display
	results of winner. 
***************************************************************************/
void Game::battle(Character* fighterA, Character* fighterB)
{
	while(true)
	{
		fight(fighterA, fighterB);
		if(!fighterB->isAlive())
		{
			std::cout << fighterB->getName() << " is killed!\n";
			// remove fighter B from Team B to loser container
			TeamB.removeFront();
			loser.addFront(fighterB);
			// show winner message and winner recover
			std::cout << fighterA->getName() << " won!\n";
			fighterA->recovery();
			TeamA.removeFront();
			TeamA.addBack(fighterA);
			// apply scores
			scoreA += 2;
			scoreB -= 1;
			return;
		}		

		fight(fighterB, fighterA);
		if(!fighterA->isAlive())
		{
			std::cout << fighterA->getName() << " is killed!\n";
			// remove fighter A from Team A to loser container
			TeamA.removeFront();
			loser.addFront(fighterA);
			// show winner message and winner recover
			std::cout << fighterB->getName() << " won!\n";
			fighterB->recovery();
			TeamB.removeFront();
			TeamB.addBack(fighterB);
			// apply scores
			scoreB += 2;
			scoreA -= 1;
			return;
		}
	}
}


/****************************************************************************
**  This function simulates one fight including one attack and one defense 
	between two characters.
****************************************************************************/
void Game::fight(Character* attacker, Character* defender)
{
	/*std::cout << "Attacker is " << attacker->getType() << ".\n"
			  << "Defender is " << defender->getType() << ": armor "
			  << defender->getArmor() << ", strength point " 
			  << defender->getStrength() << std::endl;*/
	// call attack and defense to get attack and defense point & damage
	int attackRoll = attacker->attack();
	defender->defense(attackRoll);
	
}			


