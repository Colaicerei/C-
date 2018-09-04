/****************************************************************************
** Program name: OSU Information System 
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the function implmentation file for the class Student.
		 The Student class inherits from Person class, with its own 
		 data member of GPA. It also has a override do_work function
		 which returns the hours of the student spent on homework.
**************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Student.hpp"
		
// constructor
Student::Student()
{
	GPA = (rand() % 41) / 10.0; //double between 0 to 4.0
}


// constructor takes name as parameter
Student::Student(std::string name) : Person(name)
{
	GPA = (rand() % 41) / 10.0; //double between 0 to 4.0
}


// constructor takes three parameter
Student::Student(std::string name, int age, double score) : Person(name)
{
	this->age = age;
	GPA = score; //double between 0 to 4.0
}


// destructor
Student::~Student()
{
}


/*********************************************************************
** This function generates a random number between 0 and 70 to represent
   hours the student will do work for.
*********************************************************************/
void Student::do_work()
{
	// generate a random number between 0 and 70 
	int hours = rand() % 71;
	std::cout << getName() << " did " << hours << " hours of homework.\n";
}		


/**************************************************************************
** This function returns the GPA of the student.
**************************************************************************/ 
double Student::getGPA()
{
	return GPA;
}


/**************************************************************************
** This function displays the information of the student.
**************************************************************************/ 
void Student::print()
{
	std::cout << "Name: " << getName() << "\n"
			  << "Age:  " << getAge() << "\n"
			  << "GPA:  " << getGPA() << "\n\n";
}

 
void Student::saveInfo(std::ofstream &outputFile)
{
	outputFile << getName() << "\n" << getAge() << "\n"
			   << getGPA() << "\nStudent" << "\n";
}