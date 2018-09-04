/***********************************************************************
** Program name: Zoo Tycoon 
** Author:       Chen Zou 
** Date:         9 April 2018
** Description:  This is the source files for class NewAnimal, the NewAnimal
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost and an overriding
		 function getFoodCost.
***********************************************************************/
#include"NewAnimal.hpp"

// default constructor
NewAnimal::NewAnimal(double foodIn):Animal(0, 0, 0)
		{
			mp_food = foodIn;
		}


/************************************************************************
** Description: This function returns the food cost. 
************************************************************************/
double NewAnimal::getFoodCost()
{
	return baseFoodCost*mp_food;
}



		

