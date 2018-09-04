/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou
** Date:         19 April 2018
** Description:  This is the Turtle class specification file, the Turtle 
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost and an overriding
		 function getFoodCost.  
***********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal
{
	private:
   		double mp_food; //multiplier of base food cost
		
				   		 
	public:
		Turtle();
		double getFoodCost();

};
#endif

