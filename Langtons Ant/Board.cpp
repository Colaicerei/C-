/***********************************************************************
** Program name: Langton's Ant 
** Author:       Chen Zou 
** Date:         9 April 2018
** Description:  This is the source files for class Board, the Board class
		 is a 2D array indicating ant's movement. The class has 
		 two member variables: a char indicating the color of the
		 space, and a bool value indicating if the space has an ant
		 on it. It has set and get functions for the members.
***********************************************************************/

#include"Board.hpp"

Board::Board()
{
	color = ' ';
	hasAnt = false;
}
/************************************************************************
** Description: This function returns the color of the board's spaces,
                in the format of char. 
************************************************************************/

char Board::getColor()
{
	return color;
}


/***********************************************************************
** Description: This function takes a parameter of input color, and sets 
                it to the color of the board's spaces.
***********************************************************************/
void Board::setColor(char colorIn)
{
	color = colorIn;
} 

/***********************************************************************
** Description: This function 

***********************************************************************/
bool Board::getHasAnt()
{
	return hasAnt;
}

/***********************************************************************
** Description: This function displays the current board after move.
***********************************************************************/   

void Board::setHasAnt(bool hasAntIn)
{
	hasAnt = hasAntIn;
}
