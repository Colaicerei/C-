/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the source files for class BlueMen, which
		 inherits the Character class. It has override fucntions
		 of defense().
***********************************************************************/
#include <iostream>
#include"BlueMen.hpp"

// default constructor
BlueMen::BlueMen():Character()
{
	setType("BlueMen");
	armor = 3;
	strength = 12;
	attackSides = 10;
	attackRolls = 2;
	defenseSides = 6;
	defenseRolls = 3;
}


/************************************************************************
**  Description: This function randomly generates the defense points, and 
	returns the defense points. The defense points are based on the 
	number of strength points left.
************************************************************************/
int BlueMen::defense(int attackIn)
{
	if(strength <= 4)
	{
		defenseRolls = 1;
		std::cout << getType() << " has " << defenseRolls << " defense rolls.\n";
	}
	else if(strength <= 8)
	{
		defenseRolls = 2;
		std::cout << getType() << " has " << defenseRolls << " defense rolls.\n";	
	}
	
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

	return defense;		  

}


