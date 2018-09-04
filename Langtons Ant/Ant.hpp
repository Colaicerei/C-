/***********************************************************************
** Program name: Langton's Ant Simulation
** Author:       Chen Zou
** Date:         9 April 2018
** Description:  This is the Ant class specification file, the Ant class
                 simulates the ants movement of user specified steps 
		 following Langton's Ant Rule.
***********************************************************************/

#ifndef Ant_HPP
#define Ant_HPP

#include "Board.hpp" 
class Ant
{
	private:
   
		Board** board;  //double pointer to 2D array
		int rows;       //rows and columns of board
		int cols;
		int steps;	//total steps for ants movement
		int row;	//location row index
		int col;	//location column index
		int direction;  //ants direction
   		 
	public:
		Ant(int, int, int, int, int, int);
		~Ant();
		int getDirection();
		void setDirection(int);
		void updateDirection();
		void simulation();
		void move(int);
		void print();

};
#endif
