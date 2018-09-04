/*****************************************************************
** Program name: OSU Information System
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the header file of  the class Building. 
		 The building class has data members including the name
		 as string, the size as double, and the address as string. 
		 It has get functions for the data members, but no 
		 additional function required for this class.
*****************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP
#include <string>

class Building
{
	protected:
		std::string name;
		double size;
		std::string address;
	
	public:
		Building();
		Building(std::string, double, std::string);
		~Building();
		std::string getName();
		double getSize();
		std::string getAddress();
};

#endif
