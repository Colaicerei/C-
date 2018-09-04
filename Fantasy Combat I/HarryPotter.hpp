/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the HarryPotter class specification file, the 
		 class inherits the Character class, with overriding
		 functions of defense().  
***********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter: public Character
{
	private:
		int hogwarts;	// HarryPotter has one hogwarts to revive himself	   		 
	public:
		HarryPotter();
		int defense(int) override;
			
};
#endif

