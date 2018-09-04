/*********************************************************************
** Program name: OSU Information System 
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the function implmentation file for the class 
			University, which has a default name of OSU, and vectors
			of buildings and people. It has functions to add building
			and people, display detailed information about building 
			and people, and print people's name and get a person to
			work.    
**********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>
#include <memory>
#include "Person.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

class University
{
	private:
		std::string name;
		std::vector<std::shared_ptr<Building>> buildings;
		std::vector<std::shared_ptr<Person>> people;
	
	public:
		University();
		//~University();
		void addBuilding(std::string, double, std::string);
		void addPerson(std::string, std::string);
		void addPerson(std::string, int, double, std::string);
		void printBuilding();
		void printPeople();
		void printName();
		void makeWork(std::string);
		void saveFile(std::string);
		void addPeople(std::string);
};


#endif
