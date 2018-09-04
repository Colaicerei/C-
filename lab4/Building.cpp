/****************************************************************************
* Program name: OSU Information System 
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the function implmentation file for the class Building.
		 The building class has data members including the name as string, 
		 the size as double, and the address as string. It has get 
		 functions for the data members.
**************************************************************************/

#include <string>
#include <cstdlib>
#include "Building.hpp"

// default constructor
Building::Building()
{
	name =  "";
	size = 0;
	address = "";	
}


Building::Building(std::string name, double size, std::string address)
{
	this->name =  name;
	this->size = size;
	this->address = address;	
}

Building::~Building()
{

}

/*********************************************************************
** This function returns the name of the building.
*********************************************************************/   		
std::string Building::getName()
{
	return name;
}		


/*********************************************************************
** This function returns the the size of the building in sqft.
*********************************************************************/
double Building::getSize()
{
	return size;
}   


/*********************************************************************
** This function returns the the address of the building.
*********************************************************************/
std::string Building::getAddress()
{
	return address;
}   

