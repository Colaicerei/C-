/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Implementation for the Critter parent class
**************************************************************************************/
#include "Critter.hpp"
#include "Debugger.hpp"
#include "Board.hpp"
#include "Game.hpp"

Critter::~Critter() {
}

/******************************************************************************
** Name:      	incrementAge
** Description: Ages critter by 1.
******************************************************************************/
void Critter::incrementAge() {
	age += 1;
}

/******************************************************************************
** Name:      	getCritterName
** Description: Returns string representation of a critter type.
** Return value: Returns string representation of a critter type.
******************************************************************************/
std::string Critter::getCritterName() {
	switch(critterType) {
		case(CT_Ant):
			return "Ant";
			break;
		case (CT_Doodlebug):
			return "Doodlebug";
			break;
		case (CT_All):
			return "All";
			break;
		default:
			return "Unknown";
	}
}

/******************************************************************************
** Name:      	breed
** Description: Determines the direction in which a critter can breed.
** Arguments:   currentSpace - int representing the doodlebug's current
**                             location on the board
**              adjacentSpaces - pointer to int array representing the
**                               occupants of the adjacent spaces
** Return value: Returns an int representing a direction of movement,
** 				 or int representing that the critter should stay put.
******************************************************************************/
int Critter::breed(int currentSpace, int* adjacentSpaces) {
	bool canBreed = false;       // can the ant breed in any direction?
	short int breedDirection;    // direction to move

	//Check if breeding interval has been met
	if (age % getBreedingInterval() == 0) {
		//no breeding if no empty adjacent cells
		if (adjacentSpaces[0] != empty
			&& adjacentSpaces[1] != empty
			&& adjacentSpaces[2] != empty
			&& adjacentSpaces[3] != empty) {
			dm(getCritterName() + " " + std::to_string(currentSpace)
			   + " could not breed, no empty adjacent");
			return stay;
		}
		else {
			//keep getting random adjacent cells until an empty one is found
			while (!canBreed) {
				// randomly determine direction to move
				breedDirection = rand() % 4;

				if (adjacentSpaces[breedDirection] == empty) {
					dm(getCritterName() + " " + std::to_string(currentSpace)
					   + " breeding to " + Game::getDirectionString(breedDirection));
					canBreed = true;
				}
			}

			return breedDirection;
		}
	}
	return stay;
}
