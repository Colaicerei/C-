/***********************************************************************
** Program name: Langton's Ant
** Author:       Chen Zou
** Date:         9 April 2018
** Description:  This is the Board class header file, the Board class is
		 a 2D array of white space and black space indicating 
		 movement of the ant. It has a char member for space color
		 and a bool member indicating ant's location, and set and 
		 get functions for the member variables.
***********************************************************************/

#ifndef Board_HPP
#define Board_HPP

class Board
{
	private:
   
		char color;  // '#' for black space, ' ' for white space 
		bool hasAnt; // if it's ant's current location
   		 
	public:
		Board();
		char getColor();
		void setColor(char);
		bool getHasAnt();
		void setHasAnt(bool);

};
#endif
