/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Board class which contains methods for determining
** contents of the board and displaying the board
**************************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "Critter.hpp"

// enum for possible occupants of a board space
enum spaces {ant = 0, doodlebug, empty, border};

// characters that represent the various occupants of the board spaces
const char ANT_SPACE = 'O';
const char DOODLEBUG_SPACE = 'X';
const char EMPTY_SPACE = ' ';

// border does not occupy any space on the board, instead it is drawn
// around the board by the displayBoard() method
const char BORDER = '*';

class Board
{
private:
	short int rows;			// size of the board in rows
	short int columns;		// size of the board in arrays
	int adjacentSpaces[4];	// array which holds the content of the adjacent
							// spaces relative to a given location
							// 0 = north, 1 = south, 2 = east, 3 = west

	Critter** boardSpaces;	// pointer to an array of pointers to critter objects

public:
	Board(short int nRows, short int nColumns);
	~Board();

	// getter and setter methods
	short int getRows() { return rows; };
	short int getColumns() { return columns; };

	// other methods needed for working with the game board
	short int getBoardPosition(short int row, short int column) const;
	bool placeCritter(Critter* critter, short int position);
	void moveCritter(short int fromSpace, short int toSpace);
	void removeCritter(short int position);
	Critter* getBoardCritter(short int position) const;
	short int getRemainingSpaceCount() const;
	void getCritterCount(int &ants, int &doodlebugs);
	short int* getRemainingSpaces(short int & totalSpaces) const;
	short int* getCritterSpaces(CritterType, short int &) const;
	int* getAdjacentSpaces(int position);
	void displayBoard() const;	
};

#endif // !BOARD_HPP