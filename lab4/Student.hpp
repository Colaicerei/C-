/***************************************************************
** Program name: OSU Information System
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the header file of class Student, which
		 inherits from Person class, with its own data 
		 member GPA. It also has a override do_work function
		 which returns the hours of the student spent on
		 homework.
**************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Person.hpp"

class Student : public Person
{
	private:
		double GPA;
		
	public:
		Student();
		Student(std::string);
		Student(std::string, int, double);
		~Student();
		double getGPA();
		void do_work() override;	// override do_work function 
		void print() override;	// override print function
		void saveInfo(std::ofstream&) override;
};

#endif
