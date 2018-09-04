/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the Medusa class specification file, the 
		 class inherits the Character class, with overriding
		 functions of attack().  
***********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <string>
#include "Character.hpp"

class Medusa : public Character
{
	
	public:
		Medusa();
		int attack() override;
	
};
#endif

