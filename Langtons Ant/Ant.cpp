/***************************************************************************
** Program name: Langton's Ant
** Author:       Chen Zou 
** Date:         10 April 2018
** Description:  This is the function implement file for class Ant for the
		 Langton's Ant program, it takes six parameters: rows and 
	 	 columns to create a board, total steps of movement, starting
		 row and column, and starting direction.
                 The langton's ant turns right 90 degree if on a white space, 
		 and left 90 degree if on black space, the color of space will
		 be switched after the ant moved to the next location. The ant
		 moves around the board until the specfied steps reached. 
***************************************************************************/

#include <iostream>
#include "Board.hpp"
#include "Ant.hpp"

// Ant class constructor, which takes six parameters
Ant::Ant(int rowsIn, int colsIn, int stepsIn, int startRow, int startCol, int directionIn)
{
	// Dynamically create the board as 2D array with user specified size
	
	rows = rowsIn;
	cols = colsIn;
	board = new Board*[rows];
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++);
		{
			board[i] = new Board[cols];
		} 
	}

	steps = stepsIn;
	row = startRow;
	col = startCol;	
	setDirection(directionIn);
}

//Ant class destructor
Ant::~Ant()
{
	// remove the Board object to free memory
	for(int i = 0; i < rows; i++)
	{
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
}

/****************************************************************************
** Description: This function takes a direction as parameter and moves the ant
		based on its direction, also change the color after the ant 
		left the space.   
****************************************************************************/ 
void Ant::move(int direction)
{
	// swith color at current ant location
	if(board[row][col].getColor() == '#')
	{
		board[row][col].setColor(' ');
	}
	else
	{
		board[row][col].setColor('#'); 

	}

	// remove ant location mark
	board[row][col].setHasAnt(false);

	// if direction equals 270 degree(turn south), row index add one, 
	// move ant to the top edge (row 0) if it went outside of the board  
	if(direction == 270)
	{
		if(row < rows - 1)
		{
			row += 1;
		}
		else
		{
			row = 0;
		}

	}
	// if direction equals 180 degree (turn west), column index minus one,
	// move ant to the right edge(cols-1) if went outside of the board
	else if(direction == 180)
	{
		if(col > 0)
		{
			col -= 1;
		}
		else
		{
			col = cols - 1;
		}
	}
	// if direction equals 90 degree (turn north), row index minus one,
	// move ant to the bottom edge (rows-1) if went outside
	else if(direction == 90)
	{
		if(row > 0)
		{
			row -= 1;
		}
		else
		{
			row = rows - 1;
		}
	}
	// if direction equals 0 degree (turn east), coloum index plus one,
	// move ant to the left edge(col 0) if went outside
	else 
	{
		if(col < cols -1)
		{
			col += 1;
		} 
		else
		{
			col = 0;
		}
	}

	// mark s ant location
	board[row][col].setHasAnt(true);  
}	

 
 
/***************************************************************************
** Description: This function displays the board.
****************************************************************************/  
void Ant::print()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{ 
			if(board[i][j].getHasAnt())
			{
				std::cout << '*';
			}
			else
			{
				std::cout << board[i][j].getColor();
			}
		}
		std::cout << std::endl;
	}
}



/***************************************************************************
** Description: This function simulates ants movement until the specified 
		steps is reached. 
***************************************************************************/
void Ant::simulation()
{
	// mark the start location as ant's location
	board[row][col].setHasAnt(true);  

	// continue moves until running out all steps
	for(int i = 0; i < steps; i++)
	{
		std::cout<< "\nBefore move, Location: " << row << " " << col 
			 << " Direction: " << direction << " Color: " 
			 << board[row][col].getColor() << "\n";

		move(getDirection());
		
		// display current board
		std::cout << "After step " << i+1 << ", Location: " << row 
			  << " " << col << " Direction : " << direction 
			  << " Board display as below: \n";  
		print();
		updateDirection();
	}
}



/****************************************************************************
** Description: This function sets the direction of ant's next step, the ant
		turns right 90 degree if on white space, and turns left 90
		degree if on black space.
****************************************************************************/
void Ant::updateDirection()
{
	// turn anti-clockwise if color is '#', reset 360 to 0 to avoid
	// continuous increase of degree   
	if(board[row][col].getColor() == '#')
	{
		setDirection(getDirection()+90);
		if(getDirection() == 360)
		{
			setDirection(0);
		}
	}
	// turn clockwise if color is ' ', correct -90 to 270 to avoid
	// continuous decrease of degree 
	else
	{
		setDirection(getDirection()-90);
		if(getDirection() == -90)
		{
			setDirection(270);
		}

	}

}



/****************************************************************************
** Description: This function returns the current direction of ant's move. 
****************************************************************************/
int Ant::getDirection()
{
	return direction;
}


/***************************************************************************
** Descripton: This function sets the direction for ant to move.
***************************************************************************/  
void Ant::setDirection(int directionIn)
{
	direction = directionIn;
}
