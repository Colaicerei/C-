/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the head file for class Island, which inherits 
		from class Space with override interact function. 
***********************************************************************/

#ifndef ISLAND_HPP
#define ISLAND_HPP

#include <vector>
#include <string>
#include "Space.hpp"


class Island : public Space
{
	   		 
	public:
		Island(std::string);
		~Island();
		void interact(Player*);
	
};
#endif
