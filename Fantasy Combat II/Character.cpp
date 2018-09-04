/***************************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the function implement file for class Character,
		 which is an abstract class. The class has attributes of  
		 attack, defence, armo, and strenghth points. 
***************************************************************************/
#include <string>
#include <iostream>
#include "Character.hpp"

// constructor takes two parameters
Character::Character()
{
	totalDamage = 0;
}


// destructor
Character::~Character()
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
** Description: This function sets the name of the character.
************************************************************************/
void Character::setName(std::string name)
{
	this->name = name;
}


/************************************************************************
** Description: This function returns the name of the character. 
************************************************************************/
std::string Character::getName()
{
	return name;
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
	dm(getName() + " rolled " + std::to_string(attackOut) + "\n");
	return attackOut;
}


/************************************************************************
**  Description: This function randomly generates the defense points, 
	calculates the damage and subtract from the strengh points.
************************************************************************/
int Character::defense(int attackIn)
{
	// reset totalDamage for each round
	totalDamage = 0;
	
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

	// calculate the accumulated damage
	totalDamage += damage;

	dm(getName() + " rolled " + std::to_string(defense) + "\n" 
		+ getName() + " has " + std::to_string(damage) + " damage.\n"
		+ "Total damage is " + std::to_string(totalDamage));
	
	strength -= damage;
	dm(getName() + " has " + std::to_string(getStrength()) + " strength points left.\n\n");

	return defense;		  
}


/************************************************************************
**  Description: This function randomly generates the recovery percentage
	of damage, and applies the recovery to the strength of the character.
************************************************************************/
void Character::recovery()
{
	// generate recovery points between 0 to 100;
	double recoveryPoints = (rand() % 11) * 10;
	dm(getName() + " has total damage of " + std::to_string(totalDamage) + "\n");
	dm(getName() + " recovered " + std::to_string(recoveryPoints) + "% damage!\n");
	strength += totalDamage * (static_cast<double>(recoveryPoints / 100)); 

	dm("New strength is " + std::to_string(strength));			
}
