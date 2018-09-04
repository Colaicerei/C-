/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the head file for class Forest, which inherits 
		from class Space with override interact function. 
***********************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include <vector>
#include <string>
#include "Space.hpp"


class Forest : public Space
{
	   		 
	public:
		Forest(std::string);
		~Forest();
		void interact(Player*);
	
};
#endif
