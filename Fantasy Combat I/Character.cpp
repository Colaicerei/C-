/***************************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the function implement file for class Character,
		 which is an abstract class. The class has attributes of  
		 attack, defence, armo, and strenghth points. 
***************************************************************************/
#include <string>
#include <iostream>
#include "Character.hpp"

// constructor takes two parameters
Character::Character()//int armor, int strength)
{
}


/***************************************************************************
** Description: This function returns the armor of the character. 
***************************************************************************/ 
int Character::getArmor()
{
	return armor;
} 


/***************************************************************************
**  Description: This function returns the strength point of the character. 
***************************************************************************/ 
int Character::getStrength()
{
	return strength;
} 


/***************************************************************************
**  Description: This function checks if the character has positive strength
	points, and returns true if so, otherwise returns false. 
***************************************************************************/ 
bool Character::isAlive()
{
	if(getStrength() > 0)
	{
		return true;
	}
	return false;
}


/************************************************************************
** Description: This function sets the type of the character.
************************************************************************/
void Character::setType(std::string type)
{
	this->type = type;
}


/************************************************************************
** Description: This function returns the type of the character. 
************************************************************************/
std::string Character::getType()
{
	return type;
}


/************************************************************************
**  Description: This function generates random dice rolling results 
	based on the number of rolls and dice sides, and returns the sum of 
	all rolls to represent the attack points. 
************************************************************************/
int Character::attack()
{
	int attackOut = 0;
	// for each attack dices, generate random number between 1 and side
	// added up to represent attack points
	for(int i = 0; i < attackRolls; i++)
	{
		attackOut += rand() % attackSides + 1;
	}
	std::cout << getType() << " rolled " << attackOut << "\n";
	return attackOut;
}


/************************************************************************
**  Description: This function randomly generates the defense points, 
	calculates the damage and subtract from the strengh points.
************************************************************************/
int Character::defense(int attackIn)
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

	return defense;		  
}
