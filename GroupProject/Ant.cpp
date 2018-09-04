/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Implementation for the Ant derived class
**************************************************************************************/
#include <iostream>
#include "Ant.hpp"
#include "Debugger.hpp"
#include "Game.hpp"
#include "Board.hpp"


Ant::Ant() : Critter(CT_Ant) {
	breedingInterval = 3;
}

Ant::~Ant() {
}

/******************************************************************************
** Name:      	move
** Description: Determines the direction in which an ant can move.
** Arguments:   currentSpace - int representing the doodlebug's current
**                             location on the board
**              adjacentSpaces - pointer to int array representing the
**                               occupants of the adjacent spaces
** Return value: Returns an int representing a direction of movement,
** 				 or int representing that the ant should stay put.
******************************************************************************/
int Ant::move(int currentSpace, int* adjacentSpaces)
{
  short int movePosition = rand() % 4;

  if (adjacentSpaces[movePosition] == empty) {
    dm("ant " + std::to_string(currentSpace) + " moved " + Game::getDirectionString(movePosition));
    return movePosition;
  }

  else {
    dm("ant " + std::to_string(currentSpace) + " did not select an available square so didn't move");
    return stay;
  }
}
