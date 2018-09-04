/***********************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the Vampire class specification file, the 
		 class inherits the Character class, with overriding
		 functions of defense().  
***********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"
#include "inputValidation.hpp"

class Vampire: public Character
{
			   		 
	public:
		Vampire();
		virtual ~Vampire();
		int defense(int) override;
			
};
#endif

