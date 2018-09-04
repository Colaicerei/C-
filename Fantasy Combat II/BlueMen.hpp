/***********************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the BlueMen class specification file, the 
		 class inherits the Character class, with overriding
		 functions of defense().  
***********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <string>
#include "Character.hpp"
#include "inputValidation.hpp"

class BlueMen : public Character
{
	
	public:
		BlueMen();
		~BlueMen();
		int defense(int) override;
	
};
#endif

