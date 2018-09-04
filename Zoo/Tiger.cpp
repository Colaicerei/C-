/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou 
** Date:         20 April 2018
** Description:  This is the source files for class Tiger, the Tiger
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost and an overriding
		 function getFoodCost.
***********************************************************************/
#include"Tiger.hpp"

Tiger::Tiger():Animal(10000, 1, 0.2)
		{
			mp_food = 5;
		}


/************************************************************************
** Description: This function returns the food cost. 
************************************************************************/
double Tiger::getFoodCost()
{
	return baseFoodCost*mp_food;
}


		
