/***************************************************************
** Program name: Dice-rolling War game
** Author:       Chen Zou
** Date:         16 April 2018
** Description:  This is the header file of class LoadedDie, which
		 inherits the Die class. it has a override function
		 which returns a biased results of rolling so that
		 the average output of rolling is higher than a 
		 normal die of same number of sides.
**************************************************************/

#ifndef LoadedDie_HPP
#define LoadedDie_HPP

#include <string>
#include "Die.hpp"

class LoadedDie : public Die
{
	public:
		
		int roll();	// override roll function 
		std::string getType(); // override getType
};

#endif
