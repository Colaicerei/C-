/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the source files for class Medusa, which
		 inherits the Character class. It has an override fucntion
		 of attack().
***********************************************************************/
#include <iostream>
#include"Medusa.hpp"

// default constructor
Medusa::Medusa():Character()
{
	setType("Medusa");
	armor = 3;
	strength = 8;
	attackSides = 6;
	attackRolls = 2;
	defenseSides = 6;
	defenseRolls = 1;
}


/************************************************************************
**  Description: This function generates and returns random dice rolling
	results to represent the attack points. If the point is 12, it becomes 
	1000 to kill the defender instantly. 
************************************************************************/
int Medusa::attack()
{
	int attackOut = 0;
	for(int i = 0; i < attackRolls; i++)
	{
		attackOut += rand() % attackSides + 1;
	}
	// if rolled 12, make the attack point to 1000 so any defender would die instantly
	if(attackOut == 12)
	{
		std::cout << getType() << "rolled " << attackOut 
				  << " and used Glare this round!\n";
		attackOut = 1000;		  
	}
	else
	{
		std::cout << getType() << " rolled " << attackOut << "\n";
	}	
	return attackOut;
}




