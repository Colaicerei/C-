/***************************************************************
** Program name: Dice-rolling War Game
** Author:       Chen Zou
** Date:         16 April 2018
** Description:  This is the header file of Class Die, which has
		 member variable of an integer N as the number
		 of sides on the individual die. it also has a 
		 function what returns a random integer as the 
		 result of rolling the die once.
***************************************************************/

#ifndef DIE_HPP
#define DIE_HPP
#include <string>

class Die
{
	protected:
		int N; // number of sides of die
	
	public:
		Die();
		//virtual ~Die();
		virtual std::string getType();
		void setSides(int);
		virtual int roll();
};

#endif
