/*****************************************************************
** Program name: OSU Information System
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the header file of  the class Person. 
		 The Person class has two data member: a string name 
		 and int age. It has get functions for name and age, 
		 it also has a function do_work which returns the 
		 hours of the person worked.
*****************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person
{
	protected:
		std::string name;
		int age;
	
	public:
		Person();
		Person(std::string);
		virtual ~Person();
		std::string getName();
		void setName(std::string);
		int getAge();
		virtual void do_work() = 0;
		virtual void print() = 0;
		virtual void saveInfo(std::ofstream&) = 0;
};

#endif
