/***********************************************************************
** Program name: Fantasy Combat Game
** Author:       Chen Zou 
** Date:         2 May 2018
** Description:  This is the function implement file for class Character,
		 which is an abstract class. The class has attributes of  
		 attack, defence, armo, and strenghth points.
***********************************************************************/
#include <string>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
   
		int armor;  	//armor
		int strength;   //strength points
		std::string type; //type of character
		int attackSides;
		int attackRolls;
		int defenseSides;
		int defenseRolls;
						   		 
	public:
		Character();
		virtual ~Character() = default;
		int getArmor();
		int getStrength();
		virtual int attack();
		virtual int defense(int);
		bool isAlive();
		void setType(std::string);
		std::string getType();
	
};
#endif
