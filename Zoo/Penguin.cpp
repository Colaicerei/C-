/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou 
** Date:         20 April 2018
** Description:  This is the source files for class Penguin, the Penguin
				 class inherits the Animal class, with its own member
				 variables: multipliers for cost and an overriding
				 function getFoodCost.
***********************************************************************/
#include"Penguin.hpp"

// default constructor
Penguin::Penguin():Animal(1000, 5, 0.1)
		{
			mp_food = 1;
		}



/************************************************************************
** Description: This function returns the food cost. 
************************************************************************/
double Penguin::getFoodCost()
{
	return baseFoodCost*mp_food;
}

