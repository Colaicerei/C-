/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the head file for class Town, which inherits 
		from class Space with override interact function. 
***********************************************************************/

#ifndef TOWN_HPP
#define TOWN_HPP

#include <vector>
#include <string>
#include"Space.hpp"


class Town : public Space
{
	   		 
	public:
		Town(std::string);
		~Town();
		void interact(Player*);
	
};
#endif
