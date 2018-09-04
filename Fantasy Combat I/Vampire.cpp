/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the source files for class Vampire, which
		 inherits the Character class. It has override fucntions
		 of defense().
***********************************************************************/
#include <iostream>
#include"Vampire.hpp"

// default constructor
Vampire::Vampire():Character()
{
	setType("Vampire");
	armor = 1;
	strength = 18;
	attackSides = 12;
	attackRolls = 1;
	defenseSides = 6;
	defenseRolls = 1;
}


/************************************************************************
**  Description: This function takes attack points from attacker, randomly 
	generates the defense points, calculate damage and subtract the damage
	from strength, if charm was successful, no attack points is taken and 
	no damage occurs.
************************************************************************/
int Vampire::defense(int attackIn)
{
	int defense = 0;
	int damage = 0;
	
	// randomly generates 0 or 1 to represent chrm
	// if charm sucessful, no damage from the attack
	if(rand() % 2)
	{
		std::cout << "Charm sucessful! " << getType() << " has 0 damage.\n";
		std::cout << getType() << " has " << getStrength() 
			  << " strength points left.\n\n";
		return -1; //return -1 indicating charm for testing purpose
	}
	
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

	return defense;		  
}


