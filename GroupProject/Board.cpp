/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Implementation for the Board class which contains methods for 
** 				determining contents of the board and displaying the board
**************************************************************************************/
#include "Board.hpp"

/******************************************************************************
** Name:      	Board
** Description: Constructor initializes the board
** Arguments:   nRows - size of the board in rows
**              nColumns - size of the board in columns
** Return value: n/a
******************************************************************************/
Board::Board(short int nRows, short int nColumns)
{
	rows = nRows;
	columns = nColumns;
	short int numberSpaces = (rows * columns);
	
	// Create board as an array of pointers to critters per instructions
	boardSpaces = new Critter*[numberSpaces];

	// initially set each pointer to null (null also indicates board space
	// is empty)
	for (int critter = 0; critter < numberSpaces; critter++)
	{
		boardSpaces[critter] = nullptr;
	}
}

Board::~Board()
{
	// free dynamic memory allocated to board
	short int numberSpaces = (rows * columns);
	for (int critter = 0; critter < numberSpaces; critter++)
	{
		if (boardSpaces[critter] != nullptr)
		{
			delete boardSpaces[critter];
			boardSpaces[critter] = nullptr;
		}
	}

	// clean up array and reassign pointer
	delete [] boardSpaces;
	boardSpaces = nullptr;
}

/******************************************************************************
** Name:      	getBoardPosition
** Description: Returns the position in the board array based upon the x
**				and y coordinates provided
** Arguments:   nRows - the x coordinates (or column #)
**              nColumns - the y coordinates (or row #)
** Return value: a short int representing the array position
******************************************************************************/
short int Board::getBoardPosition(const short int row, const short int column) const
{
	return (((row - 1) * columns) + (column - 1));

}

/******************************************************************************
** Name:      	placeCritter
** Description: Attempts to place a critter at the selected position.  
** Arguments:   critter - pointer to a critter object
**              position - location in the board array to place the critter
** Return value: Returns true if critter successfully places, or false if not 
** 				 successfully placed.
******************************************************************************/
bool Board::placeCritter(Critter* critter, const short int position)
{
	// critter can only be placed if board position is empty (indicated by
	// nullptr)
	if (getBoardCritter(position) == nullptr)
	{
		boardSpaces[position] = critter;
		return true;
	}

	// otherwise, critter cannot be placed
	else
	{
		delete critter;
		return false;
	}
}

/******************************************************************************
** Name:      	moveCritter
** Description: Attempts to move a critter to the selected position.
** Arguments:   fromSpace - space where critter currently reasides
**              toSpace - space to move critter to
** Return value: Returns true if critter successfully moves, or false if not
** 				 successfully moved.
******************************************************************************/
void Board::moveCritter(short int fromSpace, short int toSpace)
{
	// if critter is staying in place, don't move it
	if (fromSpace != toSpace)
	{
		// if there is already an ant at the location being moved to, free 
		// the memory allocated to the ant
		Critter* tempCritter = nullptr;
		tempCritter = getBoardCritter(toSpace);
		if (tempCritter != nullptr)
		{
			delete tempCritter;
			tempCritter = nullptr;
		}
		boardSpaces[toSpace] = boardSpaces[fromSpace];
		boardSpaces[fromSpace] = nullptr;
	}
}

/******************************************************************************
** Name:      	removeCritter
** Description: Removes critter located at a specific location in the board
				array
** Arguments:   position - a location in the board array
** Return value: none
******************************************************************************/
void Board::removeCritter(const short int position)
{
	// free dynamically allocated critter at the board location and reset pointer
	delete boardSpaces[position];
	boardSpaces[position] = nullptr;
}

/******************************************************************************
** Name:      	getBoardCritter
** Description: Grabs pointer to critter located at a specific location in the
**				board array
** Arguments:   position - a location in the board array
** Return value: Returns a pointer to the critter object
******************************************************************************/
Critter* Board::getBoardCritter(short int position) const
{
	return boardSpaces[position];
}

/******************************************************************************
** Name:      	getRemainingSpaceCount
** Description: Calculates the number of available positions in the board array
**				that are not occupied by a critter
** Return value: Returns an int representing the number of empty board spaces.
******************************************************************************/
short int Board::getRemainingSpaceCount() const
{
	int totalSpaces = 0;

	// iterate through the rows and columns
	for (short int row = 1; row <= rows; row++)
	{
		for (short int column = 1; column <= columns; column++)
		{
			// grab the pointer located at the specific location in the board
			// array
			short int position = getBoardPosition(row, column);
			// if pointer is null, the location is empty
			if (getBoardCritter(position) == nullptr)
			{
				totalSpaces++;
			}
		}
	}

	return totalSpaces;
}

/******************************************************************************
** Name:      	getCritterCount
** Description: Count number of ants and doodlebugs on the board
** Arguments:	byRef int Number of Ants on board
** 				byRef int Number of Doodlebugs on board
******************************************************************************/
void Board::getCritterCount(int &numAnts, int &numDoodlebugs) {
	Critter* tempCritter;

	// iterate through the rows and columns
	for (short int row = 1; row <= rows; row++)
	{
		for (short int column = 1; column <= columns; column++)
		{
			// grab the board position
			short int position = getBoardPosition(row, column);

			// get pointer to object at that position
			tempCritter = getBoardCritter(position);

			// test to see if location is occupied by a doodlebug
			if (tempCritter != nullptr)
			{
				if (tempCritter->getCritterType() == CT_Ant)
				{
					numAnts++;
				}
				else if (tempCritter->getCritterType() == CT_Doodlebug)
				{
					numDoodlebugs++;
				}
			}
		}
	}
}

/******************************************************************************
** Name:      	getRemainingSpaces
** Description: Calculates an array of all positions in the board array
**				that are not occupied by a critter
** Arguments:   totalSpaces - the size of the game board which contains a value
**				of zero when it is passed to this function. Argument is passed
**				by reference because the board size is calculated within this
**				method
** Return value: Returns a pointer to an array containing all of the empty
**				 board spaces
******************************************************************************/
short int* Board::getRemainingSpaces(short int & totalSpaces) const
{
	totalSpaces = getRemainingSpaceCount();

	// create the array of available locations
	short int currentSpace = 0;
	short int* availableSpaces = new short int[totalSpaces];

	for (short int row = 1; row <= rows; row++)
	{
		for (short int column = 1; column <= columns; column++)
		{
			short int position = getBoardPosition(row, column);
			if (getBoardCritter(position) == nullptr)
			{
				// assign pointer to specific empty location
				availableSpaces[currentSpace] = position;
				currentSpace++;
			}
		}
	}

	// return pointer to array of all empty board spaces
	return availableSpaces;
}

/******************************************************************************
** Name:      	getCritterSpaces
** Description: Calculates an array of all positions occupied by ANY critter
** Arguments:   enum CritterType
** 				byRef int totalsSpaces
** Return value: Returns a pointer to an array containing the location of
**				 all of the critters
******************************************************************************/
short int* Board::getCritterSpaces(CritterType critType, short int & totalSpaces) const
{
	totalSpaces = 0;
	Critter* tempCritter;

	// iterate through the rows and columns
	for (short int row = 1; row <= rows; row++)
	{
		for (short int column = 1; column <= columns; column++)
		{
			// grab the board position
			short int position = getBoardPosition(row, column);
			// get pointer to object at that position
			tempCritter = getBoardCritter(position);
			// test to see if location is occupied by a doodlebug
			if (tempCritter != nullptr)
			{
				if (tempCritter->getCritterType() == critType || critType == CT_All)
				{
					totalSpaces++;
				}
			}
		}
	}

	short int currentSpace = 0;

	// create dynamic array of doodlebug locations
	short int* critterSpaces = new short int[totalSpaces];

	// add doodlebug positions to the array
	for (short int row = 1; row <= rows; row++)
	{
		for (short int column = 1; column <= columns; column++)
		{
			short int position = getBoardPosition(row, column);
			if (getBoardCritter(position) != nullptr)
			{
				if (getBoardCritter(position)->getCritterType()== critType || critType == CT_All)
				{
					critterSpaces[currentSpace] = position;
					currentSpace++;
				}
			}
		}
	}
	return critterSpaces;
}

/******************************************************************************
** Name:      	displayBoard
** Description: Displays the contents of the game board on the screen
** Arguments:   none
** Return value: none
******************************************************************************/
void Board::displayBoard() const
{	
	Critter* tempCritter;		// pointer to hold critter being drawn on board
	short int pos;				// stores the current board position

	// display top border 
	for (int i = 0; i < columns+2; i++)
	{
		std::cout << BORDER;
	}
	std::cout << std::endl;
	// iterate over board and display contents
	for (int i = 1; i <= rows; i++)
	{
		std::cout << BORDER;
		for (int j = 1; j <= columns; j++)
		{
			// get location of board array associated with x/y coords
			pos = getBoardPosition(i, j);

			// if there is a critter in the space
			if (boardSpaces[pos] != nullptr)
			{
				// get pointer to critter
				tempCritter = getBoardCritter(pos);
				
				// draw character depending on type of critter
				if (tempCritter->getCritterType() == CT_Ant)
				{
					std::cout << ANT_SPACE;
				}
				else if (tempCritter->getCritterType() == CT_Doodlebug)
				{
					std::cout << DOODLEBUG_SPACE;
				}
			}
			else
			{
				std::cout << EMPTY_SPACE;
			}
		}
		std::cout << BORDER;
		std::cout << std::endl;
	}
	// draw bottom border
	for (int i = 0; i < columns+2; i++)
	{
		std::cout << "*";
	}

	std::cout << std::endl;
}

/******************************************************************************
** Name:      	getAdjacentSpaces
** Description: Calculates an array of locations in the board array that are
**				adjacent to the location passed as an argument
** Arguments:   position - a location in the board array
** Return value: a pointer to an array of spaces in the cardinal directions
**				 relateive to the location passed as an argument. array
**				 is ordered north, south, east, west
******************************************************************************/
int* Board::getAdjacentSpaces(int position)
{
	// temporary pointer to critter object
	Critter* tempCritter;

	// clear the array
	for (int i = 0; i < 4; i++)
	{
		adjacentSpaces[i] = empty;
	}

	// get contents of northern adjacent space by testing if space
	// is border, ant, doodlebug, or empty. add contents to array
	if (position < columns)
	{
		adjacentSpaces[0] = border;
	}
	else
	{
		tempCritter = getBoardCritter(position - columns);
		if (tempCritter == nullptr)
		{
			adjacentSpaces[0] = empty;
		}
		else if (tempCritter->getCritterType() == CT_Ant)
		{
			adjacentSpaces[0] = ant;
		}
		else if (tempCritter->getCritterType() == CT_Doodlebug)
		{
			adjacentSpaces[0] = doodlebug;
		}
	}

	// get contents of southern adjacent space
	if (position >= (columns * rows - columns) && position < (columns * rows))
	{
		adjacentSpaces[1] = border;
	}
	else
	{
		tempCritter = getBoardCritter(position + columns);
		if (tempCritter == nullptr)
		{
			adjacentSpaces[1] = empty;
		}
		else if (tempCritter->getCritterType() == CT_Ant)
		{
			adjacentSpaces[1] = ant;
		}
		else if (tempCritter->getCritterType() == CT_Doodlebug)
		{
			adjacentSpaces[1] = doodlebug;
		}
	}

	// get contents of eastern adjacent space
	for (int i = (columns-1); i < rows * columns; i += (columns))
	{
		if (position == i)
		{
			adjacentSpaces[2] = border;
		}
	}
	if (adjacentSpaces[2] != border)
	{
		tempCritter = getBoardCritter(position + 1);
		if (tempCritter == nullptr)
		{
			adjacentSpaces[2] = empty;
		}
		else if (tempCritter->getCritterType() == CT_Ant)
		{
			adjacentSpaces[2] = ant;
		}
		else if (tempCritter->getCritterType() == CT_Doodlebug)
		{
			adjacentSpaces[2] = doodlebug;
		}
	}

	// get contents of western adjacent space
	for (int i = 0; i <= (rows * columns) - columns; i += (columns))
	{
		if (position == i)
		{
			adjacentSpaces[3] = border;
		}
	}
	if (adjacentSpaces[3] != border)
	{
		tempCritter = getBoardCritter(position - 1);
		if (tempCritter == nullptr)
		{
			adjacentSpaces[3] = empty;
		}
		else if (tempCritter->getCritterType() == CT_Ant)
		{
			adjacentSpaces[3] = ant;
		}
		else if (tempCritter->getCritterType() == CT_Doodlebug)
		{
			adjacentSpaces[3] = doodlebug;
		}
	}

	return adjacentSpaces;
}
