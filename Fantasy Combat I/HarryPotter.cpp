/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the source files for class HarryPotter, which
		 inherits the Character class. It has override fucntions
		 of defense().
***********************************************************************/
#include <iostream>
#include"HarryPotter.hpp"

// default constructor
HarryPotter::HarryPotter():Character()
{
	setType("Harry Potter");
	armor = 0;
	strength = 10;  //initialize to 10
	attackSides = 6;
	attackRolls = 2;
	defenseSides = 6;
	defenseRolls = 2;
	hogwarts = 1;  // one hogwarts to get back to life
}


/************************************************************************
**  Description: This function takes attack points from attacker, randomly 
	generates the defense points, calculate damage and subtract the damage
	from strength, if strength reached 0 or below for the first time, Harry
	Potter will use hogwarts to recover strength to 20.
************************************************************************/
int HarryPotter::defense(int attackIn)
{
	int defense = 0;
	int damage = 0;
	
	for(int i = 0; i < defenseRolls; i++)
	{
		defense += rand() % defenseSides + 1;
	}
	// calculate damage, convert to 0 if it is negative
	damage = attackIn - defense - getArmor();
	if(damage < 0)
	{
		damage = 0;
	}
	std::cout << getType() << " rolled " << defense << "\n"
			  << getType() << " has " << damage << " damage.\n";
	
	strength -= damage;
	std::cout << getType() << " has " << getStrength() 
			  << " strength points left.\n\n";
	
	// if strength reached 0 or below for the first time, use the only
	// hogwarts to recover to 20
	if(strength <= 0 && hogwarts == 1)
	{
		strength = 20;
		hogwarts = 0;
		std::cout << getType() << " used Hogwarts, his strength points are "
				  << getStrength() << " now.\n\n";
	}	

	return defense;	  
}


