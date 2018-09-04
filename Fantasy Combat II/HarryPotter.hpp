/***********************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the HarryPotter class specification file, the 
		 class inherits the Character class, with overriding
		 functions of defense().  
***********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"
#include "inputValidation.hpp"

class HarryPotter: public Character
{
	private:
		int hogwarts;	// HarryPotter has one hogwarts to revive himself	   		 
	public:
		HarryPotter();
		~HarryPotter();
		int defense(int) override;
			
};
#endif

