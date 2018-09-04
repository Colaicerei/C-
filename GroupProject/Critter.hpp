/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Critter parent class
**************************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <string>

enum CritterType {CT_Ant=0, CT_Doodlebug, CT_All};

class Critter
{
protected:
	const CritterType critterType;	// holds the name of critter type (Ant or Doodlebug)
	short int age = 0;				    // all critters start with age of 0 steps
	short int breedingInterval;		// how often does critter reproduce

public:
	Critter(CritterType critterT) : critterType(critterT) { };
	virtual ~Critter();

	// getter and setter methods
	CritterType getCritterType() { return critterType; };
	short int getAge() { return age; };
	void setAge (short int age) { this->age = age; };
	short int getBreedingInterval() { return breedingInterval; }

	virtual int move(int pos, int* adjacentSpaces) = 0;
	int breed(int currentSpace, int* adjacentSpaces);
	void incrementAge();
	std::string getCritterName();
};

#endif // !CRITTER_HPP