/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Implementation for the Doodlebug derived class
**************************************************************************************/
#include "Doodlebug.hpp"
#include "Debugger.hpp"
#include "Game.hpp"
#include "Board.hpp"

Doodlebug::Doodlebug() : Critter(CT_Doodlebug) {
	breedingInterval = 8;
    starvingDay = 0;
}

Doodlebug::~Doodlebug() {
}


void Doodlebug::setStarvingDay(int days)
{
    starvingDay = days;
}


int Doodlebug::getStarvingDay()
{
    return starvingDay;
}


/******************************************************************************
** Name:      	move
** Description: Determines the space the doodlebug should move to
** Arguments:   currentSpace - int representing the doodlebug's current
**                             location on the board
**              adjacentSpaces - pointer to int array representing the 
**                               occupants of the adjacent spaces
** Return value: int enum representing direction doodlebug should move
******************************************************************************/
int Doodlebug::move(int currentSpace, int* adjacentSpaces)
{
    short int movePosition;

	// if adjacent has ant, move to ant location
    for(int i = 0; i < 4; i ++)
    {
        if(adjacentSpaces[i] == ant)
        {
			dm ("db " + std::to_string(currentSpace) + " eats ant");
            movePosition = i;
			setStarvingDay(0);
            return movePosition;
        } 
    }

	//didn't eat ant, so increment starving days
	starvingDay += 1;

    movePosition = rand() % 4;

    // if the randomly selected position is empty, doodlebug moves
    if (adjacentSpaces[movePosition] == empty) {
      dm("db " + std::to_string(currentSpace) + " moved " + Game::getDirectionString(movePosition));
      return movePosition;
    }

    // if the randomly selected position is occupied (would be by a doodlebug since we would have already 
    // checked and moved to an ant square, if it was available). 
    else {
      dm("db " + std::to_string(currentSpace) + " did not select an available square so didn't move");
      return stay;
    }
}
