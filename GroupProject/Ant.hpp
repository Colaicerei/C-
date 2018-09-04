/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Ant derived class
**************************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include <ctime>
#include "Critter.hpp"

class Ant :
	public Critter
{
public:
	Ant();
	~Ant();

	int move(int currentSpace, int* adjacentSpaces);
};

#endif // !ANT_HPP