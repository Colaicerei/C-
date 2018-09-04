/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Doodlebug derived class
**************************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug :
	public Critter
{
private:
	int starvingDay;	// the continuously starving day of doodlebug

public:
	Doodlebug();
	~Doodlebug();

	void setStarvingDay(int);
	int getStarvingDay();
	
	int move(int currentSpace, int* adjacentSpaces);
};

#endif // !DOODLEBUG_HPP
