/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the head file for class Mountain, which inherits 
		from class Space with override interact function. 
***********************************************************************/

#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include <vector>
#include <string>
#include "Space.hpp"

class Player;

class Mountain : public Space
{
	   		 
	public:
		Mountain(std::string);
		~Mountain();
		void interact(Player*);
	
};
#endif
