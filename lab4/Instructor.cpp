/****************************************************************************
** Program name: OSU Information System 
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the function implmentation file for the class Student.
		 The Instructor class inherits from Person class, with its own 
		 data member of rating. It also has a override do_work function
		 which returns the hours of the instructor worked.
**************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Instructor.hpp"
		
// constructor
Instructor::Instructor()
{
	rating = (rand() % 51) / 10.0; //double between 0 to 5.0
}


// constructor takes name as parameter
Instructor::Instructor(std::string name) : Person(name)
{
	rating = (rand() % 51) / 10.0; //double between 0 to 4.0
}


// constructor takes three parameter
Instructor::Instructor(std::string name, int age, double score) : Person(name)
{
	this->age = age;
	rating = score; //double between 0 to 4.0
}


// destructor
Instructor::~Instructor()
{
}

/**************************************************************************
** This function returns the GPA of the student.
**************************************************************************/ 
double Instructor::getRating()
{
	return rating;
}


/**************************************************************************
** This function displays the information of the student.
**************************************************************************/ 
void Instructor::print()
{
	std::cout << "Name:   " << getName() << "\n"
			  << "Age:    " << getAge() << "\n"
			  << "Rating: " << getRating() << "\n\n";
}

 
/*********************************************************************
** This function generates a random number between 0 and 70 to represent
   hours the instructor will do work for.
*********************************************************************/
void Instructor::do_work()
{
	// generate a random number between 0 and 50 
	int hours = rand() % 51;
	std::cout << getName() << " graded papers for " << hours << " hours.\n";
}		


 void Instructor::saveInfo(std::ofstream &outputFile)
{
	outputFile << getName() << "\n" << getAge() << "\n"
			   << getRating() << "\nInstructor" << "\n";
}
