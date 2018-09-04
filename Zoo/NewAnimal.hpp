/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou
** Date:         19 April 2018
** Description:  This is the NewAnimal class specification file, the 
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost and an overriding
		 function getFoodCost.  
***********************************************************************/

#ifndef NEWANIMAL_HPP
#define NEWANIMAL_HPP

#include "Animal.hpp"

class NewAnimal : public Animal
{
	private:
   		double mp_food; //multiplier of base food cost
		
				   		 
	public:
		NewAnimal(double);
		double getFoodCost();
		
		

};
#endif

