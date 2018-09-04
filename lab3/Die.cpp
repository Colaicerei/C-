/****************************************************************************
** Program name: Dice-rollong War Game 
** Author:       Chen Zou
** Date:         16 April 2018
** Description:  This is the function implmentation file for the class Die.
		 The Die class has a member variable N that represents the number
		 of  sides on the individual die. The class also has a member 
		 function that returns a random integer between 1 and N as the 
		 result of rolling the die once.
**************************************************************************/

#include <string>
#include <cstdlib>
#include "Die.hpp"

// default constructor, initialize sides to 6
Die::Die()
{
	N = 6;	
}

/*********************************************************************
** This function sets the sides of the die
*********************************************************************/
void Die::setSides(int sidesIn)
{
	N = sidesIn;
}

		
/*********************************************************************
** This function returns a random integer between 1 and N as the result 
   of rolling the die once
*********************************************************************/   		
int Die::roll()
{
	return rand() % N + 1;
}		


/*********************************************************************
** This function returns the the type of the die objects from the class.
*********************************************************************/
std::string Die::getType()
{
	return "normal die";
}   
