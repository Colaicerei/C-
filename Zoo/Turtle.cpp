/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou 
** Date:         20 April 2018
** Description:  This is the source files for class Turtle, the Turtle 
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost and an overriding
		 function getFoodCost.
***********************************************************************/
#include"Turtle.hpp"

Turtle::Turtle():Animal(100, 10, 0.05)
		{
			mp_food = 0.5;
		}


/************************************************************************
** Description: This function returns the food cost. 
************************************************************************/
double Turtle::getFoodCost()
{
	return baseFoodCost*mp_food;
}


