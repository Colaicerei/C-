/****************************************************************************
** Program name: Dice-rollong War Game 
** Author:       Chen Zou
** Date:         16 April 2018
** Description:  This is the function implmentation file for the class LoadedDie.
		 The LoadedDie class inherits the bahavior and elements of
		 Die class, except it has a override rolling runction which 
		 returns a biased results such that the average output of 
		 rolling is higher than that of a normal die with the same
		 number of sides.
**************************************************************************/
#include <string>
#include <cstdlib>
#include "LoadedDie.hpp"
		
int LoadedDie::roll()
{
	// get a random number between 1 and N+N/2, as minimum side is 3
	// so N/2 is definately greater than 0 
	int number = rand() % (N + N/2) + 1;
	// return N if generated a number > N, to increase the chance of N
	if(number > N)
	{
		return N;
	} 
	else
	{
		return number;
	}
}		


/***************************************************************************
** This function return the type of die objects from the class
***************************************************************************/
std::string LoadedDie::getType()
{
	return "loaded die";
}
 
