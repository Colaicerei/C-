/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Implementation for the Game class which contains methods for running 
** the game
**************************************************************************************/
#include <chrono>
#include <thread>
#include "Game.hpp"
#include "Board.hpp"
#include "Critter.hpp"
#include "Debugger.hpp"

/******************************************************************************
** Name:      	Game
** Description: Constructor initializes the various parameters of the game
** Arguments:   nSteps - the number of steps to run the game for
**				nRows, nColumns - the number of rows/colums in the board
**				numAntsStart - the number of ants to start the game with
**				numDoodlebugsstart - the number of doodlebugs to start
** Return value: none
******************************************************************************/
Game::Game(short int nSteps, short int nCols, short int nRows, short int numAntsStart,
		 short int numDoodlebugsStart, short int nRunMode, short int nSleep)
{
	this->numAntsStart = numAntsStart;
	this->numDoodlebugsStart = numDoodlebugsStart;
	currentStep = 1;
	numberSteps = nSteps;
	runMode = nRunMode;
	continualModeSleep = nSleep;

	board = new Board(nRows, nCols);	// create new board
	// seed the rand() function
	srand(time(0));
}

Game::~Game()
{
	// free memory allocated to board and reassign pointer
	delete board;
	board = nullptr;
}

/******************************************************************************
** Name:      	 init
** Description:  Places the initial number of ants and doodlebugs on the board
**				 at the start of the game
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::init()
{
	placeCritter(CritterType::CT_Ant, numAntsStart);
	placeCritter(CritterType::CT_Doodlebug, numDoodlebugsStart);
	//Display Initial Board State
	std::cout << "\nInitial state of the board:\n";
	board->displayBoard();	// display the contents of the board
}

/******************************************************************************
** Name:      	 run
** Description:  Contains the main game loop
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::run()
{
	do
	{
		std::cout << std::endl;	// print extra space between turns of the game
		runTurn();
		currentStep++;

		// if turn limit has been reached
		if (currentStep-1 == numberSteps)
		{
			short int extraTurns;
			std::cout << "\nYou have simulated " << currentStep-1 << " turns." << std::endl;
			std::cout << "Enter the number of turns to continue the simulation for ";
			extraTurns = promptShort ("(or 0 to quit): ", 0, 25000);
			if (extraTurns > 0)
			{
				std::cout << "Ok, the simulation will continue for another " << extraTurns
					  	  << " turns.\n";
				promptEnter("\nPress enter to continue the simulation...");
				numberSteps = extraTurns + currentStep-1;
			}
		}
		else if (runMode == step)
		{
			promptEnter("\nPress enter to continue the simulation...");
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(continualModeSleep));
		}

	} while (currentStep <= numberSteps);
}

/******************************************************************************
** Name:      	 runTurn
** Description:  Runs a turn of the game
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::runTurn()
{
    int numAnts = 0, numDoodlebugs = 0;
    std::cout << "Step " << currentStep << std::endl; // display the current step number
    ageCritters();			// advance the age of all critters by 1 day */
	moveCritters();			// move all of the critters
	breedCritters();		// breed critters that reach correct age
	handleStarvation();
	board->getCritterCount(numAnts, numDoodlebugs);
	std::cout << " " << ANT_SPACE << " Ants: " << numAnts << std::endl;
	std::cout << " " << DOODLEBUG_SPACE << " Doodlebugs: " << numDoodlebugs << std::endl;
	board->displayBoard();	// display the contents of the board
}


/******************************************************************************
** Name:      	 Move
** Description:  Move ants and doodlebugs
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::moveCritters()
{
	int* adjacentSpaces;		// holds pointer to array of contents of 4 adjacent spaces
	int currentSpace;			// current location of ant
	int moveDirection;			// direction ant will move 
	short int newSpace;			// space on the board critter will move to
	short int pos = 0;			// index for navigating the arrays
	short int totalSpaces;		// stores total number of spaces containing ants or dbugs

	//-- MOVE DOODLEBUGS
	// get pointer to array containing locations of all doodlebugs
	short int* doodlebugSpaces = board->getCritterSpaces(CT_Doodlebug, totalSpaces);

	while (pos < totalSpaces)
	{
		currentSpace = doodlebugSpaces[pos];
		adjacentSpaces = board->getAdjacentSpaces(currentSpace);
		moveDirection = board->getBoardCritter(currentSpace)->move(currentSpace, adjacentSpaces);
		newSpace = calculateMovement(board, currentSpace, moveDirection);
		board->moveCritter(currentSpace, newSpace);
        displayBoardAfterEachAction();
		pos++;
	}

	//-- MOVE ANTS
	// get pointer to array containing locations of all ants
	short int* antSpaces = board->getCritterSpaces(CT_Ant, totalSpaces);

	pos = 0;		// reset to reflect start of ants array
	while (pos < totalSpaces)
	{
		currentSpace = antSpaces[pos];
		adjacentSpaces = board->getAdjacentSpaces(currentSpace);
		moveDirection = board->getBoardCritter(currentSpace)->move(currentSpace, adjacentSpaces);
		newSpace = calculateMovement(board, currentSpace, moveDirection);
		board->moveCritter(currentSpace, newSpace);
        displayBoardAfterEachAction();
		pos++;
	}

	// free dynamically allocated memory and reset pointers
	delete [] antSpaces;
	antSpaces = nullptr;
	delete [] doodlebugSpaces;
	doodlebugSpaces = nullptr;
}

/******************************************************************************
** Name:      	 breedCritters()
** Description:  Breed ants and doodlebugs
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::breedCritters()
{
	int *adjacentSpaces;		//
	int currentSpace;			// current location of ant
	int breedDirection;			//
	int breedSpace;				// space to place new critter
	short int pos = 0;			// index for navigating the arrays
	short int totalSpaces;		// stores total number of spaces containing ants or dbugs

	//-- BREED DOODLEBUGS
	// get pointer to array containing locations of all doodlebugs
	short int* doodlebugSpaces = board->getCritterSpaces(CT_Doodlebug, totalSpaces);

	while (pos < totalSpaces)
	{
		currentSpace = doodlebugSpaces[pos];
		adjacentSpaces = board->getAdjacentSpaces(currentSpace);
		breedDirection = board->getBoardCritter(currentSpace)->breed(currentSpace, adjacentSpaces);
		breedSpace = Game::calculateMovement(board, currentSpace, breedDirection);
		Doodlebug *doodlebug = new Doodlebug();
		board->placeCritter(doodlebug, breedSpace);
        displayBoardAfterEachAction();
		pos++;
	}

	// free dynamically allocated memory and reset pointers
	delete [] doodlebugSpaces;
	doodlebugSpaces = nullptr;

	//-- BREED ANTS
	// get pointer to array containing locations of all ants
	short int* antSpaces = board->getCritterSpaces(CT_Ant, totalSpaces);
	pos = 0;		// reset to reflect start of ants array

	while (pos < totalSpaces)
	{
		currentSpace = antSpaces[pos];
		adjacentSpaces = board->getAdjacentSpaces(currentSpace);
		breedDirection = board->getBoardCritter(currentSpace)->breed(currentSpace, adjacentSpaces);
		breedSpace = Game::calculateMovement(board, currentSpace, breedDirection);
		Ant *ant = new Ant();
		board->placeCritter(ant, breedSpace);
        displayBoardAfterEachAction();
		pos++;
	}

	// free dynamically allocated memory and reset pointers
	delete [] antSpaces;
	antSpaces = nullptr;
}

/******************************************************************************
** Name:      	 ageCritters
** Description:  Age ants and doodlebugs
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::ageCritters() {
	short int pos = 0;			// iterator count
	short int totalSpaces;

	// get pointer to array containing locations of all doodlebugs
	short int* critterSpaces = board->getCritterSpaces(CT_All, totalSpaces);

	dm("** Run aging function");
	while (pos < totalSpaces)
	{
		//dm(board->getBoardCritter(critterSpaces[pos])->getCritterName() + " at " + std::to_string(critterSpaces[pos]) + " age " + std::to_string(board->getBoardCritter(critterSpaces[pos])->getAge()));
		board->getBoardCritter(critterSpaces[pos])->incrementAge();
		//dm(board->getBoardCritter(critterSpaces[pos])->getCritterName() + " at " + std::to_string(critterSpaces[pos]) + " now age " + std::to_string(board->getBoardCritter(critterSpaces[pos])->getAge()));
		pos++;
	}

	delete [] critterSpaces;
	critterSpaces = nullptr;
}

/******************************************************************************
** Name:      	 handleStarvation
** Description:  Kill off any doodlebugs that have qualified for starvation event
** Arguments:    none
** Return value: none
******************************************************************************/
void Game::handleStarvation() 
{
	Doodlebug* tempCritter;		// temporarily hold pointer to doodlebug object
	short int pos = 0;			// index for navigating the arrays
	int currentSpace;			// current location of ant
	short int totalSpaces;		// stores total number of spaces containing ants or dbugs
	
	// get pointer to array containing locations of all doodlebugs
	short int* doodlebugSpaces = board->getCritterSpaces(CT_Doodlebug, totalSpaces);
	dm("** Run starvation function");

	// iterate over the locations in the array
	while (pos < totalSpaces)
	{
		currentSpace = doodlebugSpaces[pos];

		//since getBoardCritter returns a Critter object, but we need a Doodlebug
		// so that we can call the getStarvingday function, we need to cast
		// the Critter object as a Doodlebug object
		tempCritter = dynamic_cast<Doodlebug*>(board->getBoardCritter(currentSpace));

		if(tempCritter->getStarvingDay() == 3)
		{
			dm("Starving for " + std::to_string(tempCritter->getStarvingDay()) + " days. \n");
			dm(tempCritter->getCritterName() + " at " + std::to_string(currentSpace) + " removed\n");
			board->removeCritter(currentSpace);
		}
		tempCritter = nullptr;
        displayBoardAfterEachAction();
		pos ++;
	}	

	delete [] doodlebugSpaces;
	doodlebugSpaces = nullptr;			
}


/******************************************************************************
** Name:      	 placeCritter
** Description:  Places new critters on the game board
** Arguments:    numberToPlace - the number of critters to place on the board
**				 type - the type of critter to place
** Return value: none
******************************************************************************/
void Game::placeCritter(CritterType type, short int numberToPlace)
{
	{
		// to hold the total number of empty spaces
		short int totalSpacesAvailable = board->getRemainingSpaceCount();

		// Limit number to place to total spaces available or given number
		short int maxNumberToPlace = numberToPlace;
		if (totalSpacesAvailable < numberToPlace)
		{
			maxNumberToPlace = totalSpacesAvailable;
		}

		// Place the defined number of critters
		for (short int critter = 0; critter < maxNumberToPlace; critter++)
		{
			// get pointer to array of empty spaces. totalSpacesAvailable is passed
			// as a reference so is modified within the getRemainingSpaces method
			short int* availableSpaces = board->getRemainingSpaces(totalSpacesAvailable);

			//Get random number representing random position at which to place critter 
			short int searchPosition = rand() % totalSpacesAvailable;
			short int placePosition = availableSpaces[searchPosition];

			Critter* newCritter = nullptr;
			if (type == CritterType::CT_Ant)
			{
				newCritter = new Ant();
			}
			else
			{
				newCritter = new Doodlebug();
			}

			bool placed = false;
			placed = board->placeCritter(newCritter, placePosition);
			if (placed)
			{
				dm("** " + newCritter->getCritterName() + " placed at " + std::to_string(placePosition));
			}

			delete[] availableSpaces;
			availableSpaces = nullptr;
            displayBoardAfterEachAction();
		}
	}
}

/******************************************************************************
** Name:      	 calculateMovement
** Description:  Given a space and a move direction, return the space to move to
** Arguments:    inBoard - instance of board to calc movement on
 * 				 currentSpace - location of critter
 * 				 moveDirection - enum value representing N, S, E, or W
** Return value: none
******************************************************************************/
int Game::calculateMovement(Board* inBoard, int currentSpace, int moveDirection) {
	int newSpace;

	switch (moveDirection) {
		case north:
			newSpace = currentSpace - inBoard->getColumns();
			break;
		case south:
			newSpace = currentSpace + inBoard->getColumns();
			break;
		case east:
			newSpace = currentSpace + 1;
			break;
		case west:
			newSpace = currentSpace - 1;
			break;
		case stay:
			newSpace = currentSpace;
			break;
	}

	return newSpace;
}

/******************************************************************************
** Name:      	 getDirectionString
** Description:  Translate an enum direction to a string. Used for displaying
**               debugging messages.
** Arguments:    direction - an enum value representing N, S, E, or W
** Return value: the direction as a string
******************************************************************************/
std::string Game::getDirectionString(int direction) {
	switch(direction) {
		case north:
			return "north";
			break;
		case south:
			return "south";
			break;
		case east:
			return "east";
			break;
		case west:
			return "west";
			break;
		case stay:
			return "no move";
			break;
		default:
			return "unknown";
	}
}

/******************************************************************************
** Name:      	 displayBoardAfterEachAction
** Description:  Display board after each move attempt, breed attempt, or 
**               when there is a check to see if an animal starved.               
******************************************************************************/
void Game::displayBoardAfterEachAction()
{
  if (BOARD_AFTER_EACH_ACTION)
  {
    board->displayBoard();
  }
}
