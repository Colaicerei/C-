/***************************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou 
** Date:         10 April 2018
** Description:  This is the function implement file for class Animal
		 which has five data members: ost to purchase, 
		 number of babies, base food cost, and payoff. it also 
		 has get and set functions for the variables. 
***************************************************************************/

#include "Animal.hpp"

const int BASEFOOD = 10;

// default constructor
Animal::Animal(int costIn, int babiesIn, double payoffIn)
{
	age = 0;
	setCost(costIn);
	setBabies(babiesIn);
	baseFoodCost = BASEFOOD;
	setPayoff(payoffIn);
}


// destructor
Animal::~Animal()
{
}

/****************************************************************************
** Description: This function sets the age of the animal. 
****************************************************************************/ 
void Animal::setAge(int ageIn)
{
	age = ageIn;
}	


/************************************************************************
** Description: This function returns the age of the animal. 
************************************************************************/ 
int Animal::getAge()
{
	return age;
} 


/************************************************************************
** Description: This function sets the purchase cost. 
************************************************************************/
void Animal::setCost(int costIn)
{
	cost = costIn;
} 


/************************************************************************
** Description: This function returns the purchase cost. 
************************************************************************/
int Animal::getCost()
{
	return cost;
}


/************************************************************************
** Description: This function ses the multiplier for food cost. 
************************************************************************/
//void NewAnimal::setFoodMP(double foodIn)
//{
	
//}


/************************************************************************
** Description: This function returns the food cost. 
************************************************************************/
double Animal::getFoodCost()
{
	return baseFoodCost;
}


/************************************************************************
** Description: This function sets the number of babies. 
************************************************************************/		
void Animal::setBabies(int babiesIn)
{
	numberOfBabies = babiesIn;
}


/************************************************************************
** Description: This function returns the number of babies. 
************************************************************************/
int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}


/************************************************************************
** Description: This function sets the payoff rate. 
************************************************************************/
void Animal::setPayoff(double payoffIn)
{
	payoff = payoffIn;
}


/************************************************************************
** Description: This function returns the payoff rate. 
************************************************************************/
int Animal::getPayoff()
{
	return payoff * cost;
}


/************************************************************************
** Description: This function increases the animal's age by one day. 
************************************************************************/
void Animal::getOld()
{
	age++;
}



