/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Menu class which contains methods for working with
** the program's main menu
**************************************************************************************/
#include "Menu.hpp"

const int MAX_ROWS = 100;
const int MAX_COLUMS = 100;
const int MAX_STEPS = 25000;
const int MAX_NUM_ANTS = 10000;
const int MAX_NUM_DOODLEBUGS = 10000;

Menu::Menu()
{
}

Menu::~Menu()
{
}

/******************************************************************************
** Name:         mainMenu
** Description:  Prompts user for all of the custom parameters required to
**				 set up the game. 
** Arguments:    none
** Return value: none
******************************************************************************/
void Menu::mainMenu()
{
	short int numCols, numRows, numSteps, maxAntsForBoard, numAnts, maxDoodlebugsForBoard,
      numDoodlebugs, runMode, sleep;

 	numCols = promptShort("Enter the number of columns", 1, MAX_COLUMS);
	numRows = promptShort("Enter the number of rows", 1, MAX_ROWS);
	numSteps = promptShort("Enter the number of steps", 1, MAX_STEPS);

    maxAntsForBoard = numCols*numRows;
    if (maxAntsForBoard > MAX_NUM_ANTS)
    {
      numAnts = promptShort("Enter the number of ants to place", 0, MAX_NUM_ANTS);
    }
    else
    {
      numAnts = promptShort("Enter the number of ants to place", 0, maxAntsForBoard);
    }

    maxDoodlebugsForBoard = numCols*numRows - numAnts;

    if (maxDoodlebugsForBoard > MAX_NUM_DOODLEBUGS)
    {
      numDoodlebugs = promptShort("Enter the number of doodlebugs to place", 0, MAX_NUM_DOODLEBUGS);
    }
    else
    {
      numDoodlebugs = promptShort("Enter the number of doodlebugs to place", 0, maxDoodlebugsForBoard);
    }
    
	runMode = promptShort("Run Mode: 1=Run continually  2=Run one step at a time", 1, 2, false);
	sleep = 0;

	if (runMode == 1) {
		sleep = promptShort("How long to pause between iterations (milliseconds): ", 0, 5000);
	}

	//TODO: Bret - I hard-coded these values for now for easier debugging, but we
	// need to restore the random entry options above to get the extra credit.
	//numCols = 20;
	//numRows = 20;
	//numAnts = 100;
	//numDoodlebugs = 5;

	// instantiate game class using custom parameters
	Game game(numSteps, numCols, numRows, numAnts, numDoodlebugs, runMode, sleep);

	// initialize the game board with starting settings
	game.init();

	// run the game
	game.run();
}