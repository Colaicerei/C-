/*********************************************************************
** Program name: Final Project
** Author:       Chen Zou 
** Date:         10 June 2018
** Description:  This is the function implement file for class Player,
		which has attributes of a pointer to location, mushroom
		represents extra lives, a bag, bool variables indicating
		player alive or not, and if player win the game, setters 
		and getters and functions related to play activies.   
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
//#include "Space.hpp"
class Space;  // forward declaration

class Player
{
private:
	Space* location = nullptr;
	int mushroom; // mushroom to bring back the player to life
	std::vector<std::string> bag;
	bool alive;  // check if player is alive
	bool gameWin; // check if player has completed the task and won the game

public:
	Player();
	void setLocation(Space*);
	Space* getLocation();
	int getMushroom();		// check extra life player got from mushroom
	void setMushroom(int);	
	void eatMushroom();		// eat two mushroom maximum
	void setLive(bool alive);
	bool isAlive();
	void setGameWin(bool gameWin);
	bool getGameWin();
	void move(int);
	void checkBag();
	bool bagFull();
	void addToBag(std::string);		// add item to bag
	void removeItem(std::string);	// remove item from bag
	bool hasGrace();		// check if player has grace in bag	
	bool hasFruit();		// check if player has fruit in bag	
	bool hasSeal();			// check if player has seal in bag
	bool hasWood();			// check if player has wood in bag
	bool ingredientsGet();	// check if player has all ingredients
};

#endif 
