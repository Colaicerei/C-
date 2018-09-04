/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Game class which contains methods for running the
** game
**************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <ctime>
#include <cstdlib>
#include <thread>
#include "Board.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Validations.hpp"

// enum for 4 cardinal directions + staying in place; used to move critters
enum direction {north = 0, south, east, west, stay};
enum runMode {continual = 1, step};

const bool BOARD_AFTER_EACH_ACTION = false;

class Game
{
private:
	Board* board;					// pointer to the game board
	Critter** doodlebugs;			// array of pointers to all ants
	Critter** ants;					// array to pointers to all doodlebugs
	short int numberSteps;			// number of steps game should run for
	short int currentStep = 1;		// the current step
	short int numAntsStart;			// the starting number of ants
	short int numDoodlebugsStart;	// the starting number of doodlegus
	short int runMode;				// 1=Run continuously, 2=Run step-by-step
	short int continualModeSleep;	// Time to sleep during each continuous iteration

public:
	Game(short int nSteps, short int nCols, short int nRows, short int numAntsStart,
		 short int numDoodlebugsStart, short int nRunMode, short int nContinualModeSleep);
	~Game();

	void init();		
	void run();			
	void runTurn();		
	void moveCritters();
	void breedCritters();
	void ageCritters();
	void handleStarvation();
	void placeCritter(CritterType type, short int numberToPlace);
	static int calculateMovement(Board* board, int currentSpace, int moveDirection);
	static std::string getDirectionString(int direction);
    void displayBoardAfterEachAction();
};

#endif // !GAME_HPP