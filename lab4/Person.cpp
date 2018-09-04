/****************************************************************************
* Program name: OSU Information System 
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the function implmentation file for the class Person.
		 The Person class has two data member: a string name and int age. It
		 has get functions for name and age, it also has a function do_work 
		 which returns the hours of the person worked.
**************************************************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include "Person.hpp"

// default constructor
Person::Person()
{
	name =  "";
	age = rand() % (81-15) + 15;	
}


Person::Person(std::string name)
{
	setName(name);
	age = rand() % (81-15) + 15;
}

// destructor
Person::~Person()
{
}

		
/*********************************************************************
** This function returns a random integer between 1 and N as the result 
   of rolling the die once
*********************************************************************/   		
int Person::getAge()
{
	return age;
}		


/*********************************************************************
** This function returns the the name of the person.
*********************************************************************/
std::string Person::getName()
{
	return name;
}   


/*********************************************************************
** This function sets the the name of the person.
*********************************************************************/
void Person::setName(std::string name)
{
	this->name = name;
}   
