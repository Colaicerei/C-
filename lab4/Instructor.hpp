/***************************************************************
** Program name: OSU Information System
** Author:       Chen Zou
** Date:         26 April 2018
** Description:  This is the header file of class Instructor, which
		 inherits from Person class, with its own data member
		 rating. It also has a override do_work function
		 which returns the hours of the instructor worked.
**************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include "Person.hpp"

class Instructor : public Person
{
	private:
		double rating;
		
	public:
		Instructor();
		Instructor(std::string);
		Instructor(std::string, int, double);
		~Instructor();
		double getRating();
		void print() override;
		void do_work() override;	// override function in base
		void saveInfo(std::ofstream&) override;
};

#endif
