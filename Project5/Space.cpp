/***************************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Space,
		which is an abstract class. The class has attributes of
		four pointers to other spaces in four direction,
		the type of the space, and a bool value indicating 
		if it is visited. It has getter and setter functions,
		and functions to checkMap and interact with player.
***************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include "Space.hpp"
#include "Player.hpp"

// constructor
Space::Space(std::string type)
{
	top = nullptr;
	left = nullptr;
	right = nullptr;
	bottom = nullptr;
	this->type = type;
	visited = false;
	//item = nullptr;

}


// destructor
Space::~Space()
{
	
}



/*********************************************************************
** Description: Return pointer to the space above this space.
*********************************************************************/
Space* Space::getTop()
{
	return top;
}

/*********************************************************************
** Description: Set the top pointer to the input space.
*********************************************************************/
void Space::setTop(Space* top)
{
	this->top = top;
}

/*********************************************************************
** Description: Return pointer to the space right of this space.
*********************************************************************/
Space* Space::getRight()
{
	return right;
}

/*********************************************************************
** Description: Set the right pointer to the input space.
*********************************************************************/
void Space::setRight(Space* right)
{
	this->right = right;
}

/*********************************************************************
** Description: Return pointer to the space left of this space.
*********************************************************************/
Space* Space::getLeft()
{
	return left;
}

/*********************************************************************
** Description: Set the left pointer to the input space.
*********************************************************************/
void Space::setLeft(Space* left)
{
	this->left = left;
}

/*********************************************************************
** Description: Return pointer to the space below this space.
*********************************************************************/
Space* Space::getBottom()
{
	return bottom;
}

/*********************************************************************
** Description: Set the bottom pointer to the input space.
*********************************************************************/
void Space::setBottom(Space* bottom)
{
	this->bottom = bottom;
}


/************************************************************************
** Description: This function returns the type of the Space. 
************************************************************************/
std::string Space::getType()
{
	return type;
}


/************************************************************************
**  Description: This function opens map for the current location.
************************************************************************/
void Space::checkMap()
{
	std::ifstream inputFile;
	inputFile.open(getType() + "Map.txt");
		
	// check if file is sucessfully opened
	if(!inputFile)
	{	
		std::cout << "Map is lost!\n";
		exit(1);
	}	
	else
	{
		// read file one line at a time, loop until end of file 
		char ch = inputFile.get();
		std::cout << std::endl;
		while(ch != EOF)
		{ 
			std::cout << ch;
			ch = inputFile.get();
		}
		std::cout << std::endl;

		inputFile.close();	
	}	
}


/***************************************************************************
**  This function is a pure virtual function.
***************************************************************************/
void Space::interact(Player* player)
{
	
}