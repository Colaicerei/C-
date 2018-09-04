/****************************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the function impliementation file of the class Game,
             which has two data members: pointers to two fighter 
			 characters, and functions to creates the fighters of user
			 choice, and simulates the game until one fighter is dead.  
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
#include "Menu.hpp"
#include "inputValidation.hpp"


// constructor
Game::Game()
{ 
	fighter1 = NULL; // initialize the player pointers to null
	fighter2 = NULL;
}		

Game::~Game()
{
	delete fighter1;
	fighter1 = NULL;
	delete fighter2;
	fighter2 = NULL;
}

/***************************************************************************
** This function displays the instruction of the game.
***************************************************************************/
void Game::showInstruction()
{
	std::cout << "		Welcome to the Fantasy Combat Game! \n"
		  << "In this game, you will pick two characters to fight a combat. \n"
		  << "For each round, each fighters will attack twice, then continue to\n"
		  << "the next round until one of the characters dies.\n"
		  << "Please select two fighters from the following options:\n\n";
}


/***************************************************************************
** This function takes the game information from the user and creates 
   players for the game.
***************************************************************************/
void Game::setUp(int index1, int index2)
{
	
	// dynamically create fighter1	
	switch(index1)
	{
		case 1: fighter1 = new Vampire();
				break;
		case 2: fighter1 = new Barbarian();
				break;
		case 3: fighter1 = new BlueMen();
				break;
		case 4: fighter1 = new Medusa();
				break;
		case 5: fighter1 = new HarryPotter();
	}					
	
	// dynamically create fighter2
	switch(index2)
	{
		case 1: fighter2 = new Vampire();
				break;
		case 2: fighter2 = new Barbarian();
				break;
		case 3: fighter2 = new BlueMen();
				break;
		case 4: fighter2 = new Medusa();
				break;
		case 5: fighter2 = new HarryPotter();
	}

	if(index2 == index1)
	{
		fighter1->setType(fighter1->getType() + " I");
		fighter2->setType(fighter2->getType() + " II");
	}
		
}


/***************************************************************************
**  This function simulates the combat between two chosen characters, it 
	simulates fights and display results for each round until one character
	dies.
***************************************************************************/
void Game::play(int index1, int index2)
{
	setUp(index1, index2);
	
	int round = 0; // score for play 2
	std::cout << fighter1->getType() << " VS " << fighter2->getType() << std::endl;
		
	while(true)
	{
		round++;
		std::cout << "\nRound " << round << " results:\n"; 
		
		fight(fighter1, fighter2);
		if(!fighter2->isAlive())
		{
			std::cout << fighter2->getType() << " is killed!\n";
			break;
		}		

		fight(fighter2, fighter1);
		if(!fighter1->isAlive())
		{
			std::cout << fighter1->getType() << " is killed!\n";
			break;
		}

		// promote user to press enter to continue 
		std::cout << "Please press enter for next round...";
		std::string input;
		getline(std::cin, input);
    	std::cin.clear();
	}
}


/****************************************************************************
**  This function simulates one fight including one attack and one defense 
	between two characters.
****************************************************************************/
void Game::fight(Character* attacker, Character* defender)
{
	std::cout << "Attacker is " << attacker->getType() << ".\n"
			  << "Defender is " << defender->getType() << ": armor "
			  << defender->getArmor() << ", strength point " 
			  << defender->getStrength() << std::endl;
	// call attack and defense to get attack and defense point & damage
	int attackRoll = attacker->attack();
	defender->defense(attackRoll);
	
}			

/****************************************************************************
**  This function tests if character are rolling attack and defense points as 
	expected.
****************************************************************************/	
void Game::test()
{
	Vampire vampire;
	Barbarian barbarian;
	BlueMen bluemen;
	Medusa medusa;
	HarryPotter harrypotter;

	srand(time(0));
	
	int minRoll = 100000;
	int maxRoll = 0;
	int glare = 0;
	int charm = 0;
	
	// test for Vampire attack function
	std::cout << "\nnow testing for Vampire attack function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press enter to continue...";
	std::string input;
	getline(std::cin, input);
    std::cin.clear();

	for(int i = 0; i < 1000; i++)
	{
		int attackRoll = vampire.attack();
		if(attackRoll < 1 || attackRoll > 12)
		{
			std::cout << "Vampire attack function fail, please check!\n\n";
			exit(1);
				
		}
		else
		{
			if(attackRoll < minRoll)
				minRoll = attackRoll;
			if(attackRoll > maxRoll)
				maxRoll = attackRoll;	
		}
	}
	std::cout << "\nVampire attack ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";
			
		
	// test for Vampire defense function
	std::cout << "now testing for Vampire defense function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press enter to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int defenseRoll = vampire.defense(0);
		if(defenseRoll < 1 || defenseRoll > 6)
		{
			if(defenseRoll == -1)
			{
				charm ++;
			}	
			else
			{
				std::cout << "Vampire defense function fail, please check!\n\n";
				exit(1);
			}	
		}
		else
		{
			if(defenseRoll < minRoll)
				minRoll = defenseRoll;
			if(defenseRoll > maxRoll)
				maxRoll = defenseRoll;	
		}
	}	
	std::cout << "\nVampire defense ok, rolls between " << minRoll << " and " << maxRoll << "\n"
			    << "Vampire use " << charm << " times charm out of 1000 round!\n\n";
		
	// test for Barbarian attack function
	std::cout << "now testing for Barbarian attack function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int attackRoll = barbarian.attack();
		if(attackRoll < 2 || attackRoll > 12)
		{
			std::cout << "Barbarian attack function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(attackRoll < minRoll)
				minRoll = attackRoll;
			if(attackRoll > maxRoll)
				maxRoll = attackRoll;	
		}
	}
	std::cout << "\nBarbarian attack ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";
	

	// test for Barbarian defense function
	std::cout << "now testing for Barbarian defense function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press enter to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int defenseRoll = barbarian.defense(0);
		if(defenseRoll < 2 || defenseRoll > 12)
		{
			std::cout << "Barbarian defense function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(defenseRoll < minRoll)
				minRoll = defenseRoll;
			if(defenseRoll > maxRoll)
				maxRoll = defenseRoll;	
		}
	}
	std::cout << "\nBarbarian defense ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";

// test for BlueMen attack function
	std::cout << "now testing for BlueMen attack function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int attackRoll = bluemen.attack();
		if(attackRoll < 2 || attackRoll > 20)
		{
			std::cout << "BlueMen attack function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(attackRoll < minRoll)
				minRoll = attackRoll;
			if(attackRoll > maxRoll)
				maxRoll = attackRoll;	
		}
	}
	std::cout << "\nBlueMen attack ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";
	

	// test for BlueMen defense function
	std::cout << "now testing for BlueMen defense function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press enter to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int defenseRoll = bluemen.defense(0);
		if(defenseRoll < 3 || defenseRoll > 18)
		{
			std::cout << "BlueMen defense function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(defenseRoll < minRoll)
				minRoll = defenseRoll;
			if(defenseRoll > maxRoll)
				maxRoll = defenseRoll;	
		}
	}
	std::cout << "\nBlueMen defense ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";


// test for Medusa attack function
	std::cout << "now testing for Medusa attack function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int attackRoll = medusa.attack();
		if(attackRoll < 2 || attackRoll > 12)
		{
			if(attackRoll == 1000)
			{
				glare ++;
				maxRoll = 12;
			}
			else
			{
				std::cout << "Medusa attack function fail, please check!\n\n";
				exit(1);
			}	
		}
		else
		{
			if(attackRoll < minRoll)
				minRoll = attackRoll;
			if(attackRoll > maxRoll)
				maxRoll = attackRoll;	
		}
	}
	std::cout << "\nMedusa attack ok, rolls between " << minRoll << " and " << maxRoll << "\n\n"
			  << "Medusa used " << glare << " times Glare!\n\n";
	

	// test for Medusa defense function
	std::cout << "now testing for Medusa defense function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press enter to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int defenseRoll = medusa.defense(0);
		if(defenseRoll < 1 || defenseRoll > 6)
		{
			std::cout << "Medusa defense function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(defenseRoll < minRoll)
				minRoll = defenseRoll;
			if(defenseRoll > maxRoll)
				maxRoll = defenseRoll;	
		}
	}
	std::cout << "\nMedusa defense ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";
	  
// test for HarryPotter attack function
	std::cout << "now testing for HarryPotter attack function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int attackRoll = harrypotter.attack();
		if(attackRoll < 2 || attackRoll > 12)
		{
			std::cout << "HarryPotter attack function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(attackRoll < minRoll)
				minRoll = attackRoll;
			if(attackRoll > maxRoll)
				maxRoll = attackRoll;	
		}
	}
	std::cout << "\nHarryPotter attack ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";
	

	// test for HarryPotter defense function
	std::cout << "now testing for HarryPotter defense function...\n\n";
	// promote user to press enter to continue 
	std::cout << "Please press enter to continue...";
	getline(std::cin, input);
    std::cin.clear();

	minRoll = 10000;
	maxRoll = 0;
	for(int i = 0; i < 1000; i++)
	{
		int defenseRoll = harrypotter.defense(0);
		if(defenseRoll < 2 || defenseRoll > 12)
		{
			std::cout << "HarryPotter defense function fail, please check!\n\n";
			exit(1);
		}
		else
		{
			if(defenseRoll < minRoll)
				minRoll = defenseRoll;
			if(defenseRoll > maxRoll)
				maxRoll = defenseRoll;	
		}
	}
	std::cout << "\nHarryPotter defense ok, rolls between " << minRoll << " and " << maxRoll << "\n\n";

}	  