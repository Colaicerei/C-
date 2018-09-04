/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the head file for class Sea, which inherits 
		from class Space with override interact function. 
***********************************************************************/

#ifndef SEA_HPP
#define SEA_HPP

#include <vector>
#include <string>
#include"Space.hpp"


class Sea : public Space
{
	   		 
	public:
		Sea(std::string);
		~Sea();
		void interact(Player*);
	
};
#endif
