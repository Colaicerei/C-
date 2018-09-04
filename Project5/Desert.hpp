/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the head file for class Desert, which inherits 
		from class Space with override interact function. 
***********************************************************************/
#ifndef DESERT_HPP
#define DESERT_HPP

#include <vector>
#include <string>
#include"Space.hpp"

class Desert : public Space
{
	   		 
	public:
		Desert(std::string);
		~Desert();
		void interact(Player*);
	
};
#endif
