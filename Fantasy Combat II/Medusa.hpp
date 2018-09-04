/***********************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the Medusa class specification file, the 
		 class inherits the Character class, with overriding
		 functions of attack().  
***********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <string>
#include "Character.hpp"
#include "inputValidation.hpp"

class Medusa : public Character
{
	
	public:
		Medusa();
		~Medusa();
		int attack() override;
	
};
#endif

