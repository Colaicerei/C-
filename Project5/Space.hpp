/***********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Space,
		which is an abstract class. The class has attributes of
		four pointers to other spaces in four direction,
		the type of the space, and a bool value indicating 
		if it is visited. It has getter and setter functions,
		and functions to checkMap and interact with player. 
***********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "Menu.hpp"
#include "Player.hpp"


//class Player;

class Space
{
	protected:
   
		Space* top;
		Space* bottom;
		Space* left;
        Space* right;
            
        std::string type;
	    bool visited;
						   		 
	public:
		Space(std::string);
		virtual ~Space();
		void setTop(Space*);
		Space* getTop();
		void setBottom(Space*);
		Space* getBottom();
		void setLeft(Space *);
		Space* getLeft();
		void setRight(Space*);
		Space* getRight();
		std::string getType();
		void checkMap();
		virtual void interact(Player*) = 0;
};
#endif
