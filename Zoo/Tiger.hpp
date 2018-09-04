/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou
** Date:         19 April 2018
** Description:  This is the Tiger class specification file, the Tiger
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost, food, babies and payoff  
***********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{
	private:
   		double mp_food; //multiplier of base food cost
		
				   		 
	public:
		Tiger();
		double getFoodCost();
		

};
#endif

