/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou
** Date:         19 April 2018
** Description:  This is the Penguin class specification file, the Penguin
		 class inherits the Animal class, with its own member
		 variables: multipliers for cost, and an overriding
		 function getFoodCost. 
***********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP


#include "Animal.hpp"


class Penguin : public Animal
{
	private:
   		double mp_food; //multiplier of base food cost
		
				   		 
	public:
		Penguin();
		double getFoodCost();
		

};
#endif

