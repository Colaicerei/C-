/***********************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the function implement file for class Character,
		 which is an abstract class. The class has attributes of  
		 attack, defence, armo, damage and strenghth points.
***********************************************************************/
#include <string>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "inputValidation.hpp"

class Character
{
	protected:
   
		int armor;  	//armor
		int strength;   //strength points
		std::string name; //name of character
		int attackSides;
		int attackRolls;
		int defenseSides;
		int defenseRolls;
		int totalDamage; //total damage taken in a battle
						   		 
	public:
		Character();
		virtual ~Character() = 0;
		int getArmor();
		int getStrength();
		virtual int attack();
		virtual int defense(int);
		bool isAlive();
		void setName(std::string);
		std::string getName();
		void recovery();
	
};
#endif
