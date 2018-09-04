/****************************************************************************
** Program name: OSU Information System 
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the function implmentation file for the class University.
			The University class has data members of name(OSU), and vectors
			of buildings and people. It has functions to add building and
			people, display detailed information about building and people, 
			and print people's name and get a person to work.  
****************************************************************************/

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "University.hpp"
#include "Person.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"


// constructor
University::University()
{ 
	name = "Oregon State University"; 
	addBuilding("Adams Hall", 11168, "606 SW 15th St");
	addBuilding("Bates Hall", 16134, "110 SW 26th St");
	std::cout << "Now adding people from file..." << std::endl;
	addPeople("OSUPeople.txt");
}		


// destructor

/**************************************************************************
** This function adds new building to building list.
**************************************************************************/ 
void University::addBuilding(std::string name, double size, std::string address)
{
	buildings.push_back(std::make_shared<Building>(name, size, address));
}


/**************************************************************************
** This function adds new person to people list.
**************************************************************************/ 
void University::addPerson(std::string name, std::string type)
{
	if(type == "student" || type == "Student")
	{
		people.push_back(std::make_shared<Student>(name));
	} 
	else if(type == "Instructor" || type == "instructor")
	{
		people.push_back(std::make_shared<Instructor>(name));
	}
	else
	{
		std::cout << "Unable to add the person to the system! Please "
				  << "check the category of the person!\n";
	}	
}

/***************************************************************************
** This function displays the information of all the buildings.
***************************************************************************/
void University::printBuilding()
{
	for(int i = 0; i < buildings.size(); i++)
	{
		std::cout << "Building " << i+1 << ":\n"
				  << "Name: " << buildings[i]->getName() << "\n"
				  << "Address: " << buildings[i]->getAddress() << "\n"
				  << "Size: " << buildings[i]->getSize() << " sqft\n\n";
	}
}


/**************************************************************************
** This function displays the information of all the people.
**************************************************************************/ 
void University::printPeople()
{
	for(int i = 0; i < people.size(); i++)
	{
		std::cout << "Person " << i+1 << ":\n";
		people[i]->print();
	}
}


/**************************************************************************
** This function displays the name of all the people.
**************************************************************************/ 
void University::printName()
{
	for(int i = 0; i < people.size(); i++)
	{
		std::cout << people[i]->getName() << "\n";
	}
}


/**************************************************************************
** This function takes a persons name as parameter and make them to work.
**************************************************************************/ 
void University::makeWork(std::string nameIn)
{
	for(int i = 0; i < people.size(); i++)
	{
		if(people[i]->getName() == nameIn)
		{
			people[i]->do_work();
			return;
		}
	}
	std::cout << "Person not found!\n";
}



/***************************************************************************
 ** This function outputs people information to file
***************************************************************************/ 
void University::saveFile(std::string fileName)
{
	std::ofstream outputFile;
	
	// open file
	outputFile.open(fileName);

	// check if file is sucessfully opened
	if(!outputFile)
	{	
		std::cout << fileName << " could not be opened!\n";
		exit(1);
	}	

	for(int i = 0; i < people.size(); i++)
	{
		people[i]->saveInfo(outputFile);
	}

	outputFile.close();
}


/***************************************************************************
 ** This function gets people information from file and create persons
***************************************************************************/  
void University::addPeople(std::string fileName)
{
	std::ifstream inputFile;
	std::string name, age, score, type; // information read from the file
		
	// open input file
	inputFile.open(fileName);

	// check if file is sucessfully opened
	if(!inputFile)
	{	
		std::cout << fileName << " could not be opened!\n";
		return;
	}	
	else
	{
		// read file one line at a time, loop until end of file 
		while(getline(inputFile, name))
		{
			getline(inputFile, age);
			getline(inputFile, score);
			getline(inputFile, type);
			addPerson(name, std::stoi(age), std::stod(score), type);
		}

		inputFile.close();	
	}	
}


/**************************************************************************
** This function adds person to people list
**************************************************************************/ 
void University::addPerson(std::string name, int age, double score, std::string type)
{
	if(type == "student" || type == "Student")
	{
		people.push_back(std::make_shared<Student>(name, age, score));
	} 
	else if(type == "Instructor" || type == "instructor")
	{
		people.push_back(std::make_shared<Instructor>(name, age, score));
	}
	else
	{
		std::cout << "Unable to add the person to the system! Please "
				  << "check the category of the person!\n";
	}	
}
