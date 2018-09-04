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

#include <iostream>
#include "Player.hpp"
#include "Space.hpp"


/*********************************************************************
** Description: Constructor.
*********************************************************************/
Player::Player()
{
	setMushroom(0);
}


/***************************************************************************
**  This function set the number of mushroom player has eaten
***************************************************************************/
void Player::setMushroom(int mushroom)
{
	this->mushroom = mushroom;
	
}


/***************************************************************************
**  This function returns mushroom player ate which represents extra life.
***************************************************************************/
int Player::getMushroom()
{
	return mushroom;
	
}


/***************************************************************************
**  This function simulates eating mushroom and returns number of mushroom, 
	player cannot have more than 2 mushroom.
***************************************************************************/
void Player::eatMushroom()
{
	if(getMushroom() >= 2)
	{
		std::cout << "You cannot eat any more mushrooms!";
	}
	else
	{
		setMushroom(getMushroom() + 1);
		std::cout << "You have " << getMushroom() << " mushrooms in your stomach!\n"; 
	}
}


/***************************************************************************
**  This function check if player is alive.
***************************************************************************/
bool Player::isAlive()
{
	return alive;
}


/***************************************************************************
**  This function sets life status of player.
***************************************************************************/
void Player::setLive(bool alive)
{
	this->alive = alive; 
}


/***************************************************************************
**  This function set win status of player.
***************************************************************************/
void Player::setGameWin(bool gameWin)
{
	this->gameWin = gameWin;
}


/***************************************************************************
**  This function returns if player win.
***************************************************************************/
bool Player::getGameWin()
{
	return gameWin;
}


/*********************************************************************
** Description: Set the player's location.
*********************************************************************/
void Player::setLocation(Space* location)
{
	
	this->location = location;
}


/*********************************************************************
** Description: Return the player's current location.
*********************************************************************/
Space* Player::getLocation()
{
	return location;
}


/***************************************************************************
**  This function simulates the movement of player.
***************************************************************************/
void Player::move(int direction)
{
	
	switch (direction)
	{
		case 1: // move north
		{
			if(location->getTop() == nullptr)
			{
				std::cout << "You went to the wrong direction. There is no way out!\n"
						  << "You had to come all the way back and wasted a day!";
			}
			else
			{
				location = location->getTop();
			}	
			break;
		}
		
		case 2: // move south
		{
			if(location->getBottom() == nullptr)
			{
				std::cout << "You went to the wrong direction. There is no way out!\n"
						  << "You had to come all the way back and wasted a day!";
			}
			else
			{
				location = location->getBottom();
			}
			break;
		}

		case 3: // move west
		{
			if(location->getLeft() == nullptr)
			{
				std::cout << "You went to the wrong direction. There is no way out!\n"
						  << "You had to come all the way back and wasted a day!";
			}
			else
			{
				location = location->getLeft();
			}
			break;
		}

		case 4: // move east
		{
			if(location->getRight() == nullptr)
			{
				std::cout << "You went to the wrong direction. There is no way out!\n"
						  << "You had to come all the way back and wasted a day!";
			}
			else
			{
				location = location->getRight();
			}
			break;
		}
	}
}	


/***************************************************************************
**  This function returns the items player has taken so far.
***************************************************************************/
void Player::checkBag()
{
	std::cout << "Your bag contains\n";

	for(unsigned int i = 0; i < bag.size(); i++)
		std::cout << i+1 << ". " << bag[i] << "\n";
}


/***************************************************************************
**  This function returns if player's bag is full.
***************************************************************************/
bool Player::bagFull()
{
	if(bag.size() >= 3)
	{
		return true;
	}
	return false;
}


/***************************************************************************
**  This function adds item to the bag.
***************************************************************************/
void Player::addToBag(std::string item)
{
	if(bagFull())
	{
		std::cout << "You bag is full, you need to remove magic wood if you no longer need it.\n";
	
	}
	else
	{	
		bag.push_back(item);
		std::cout << "You have added " << item << " to your bag!\n";
		
	}	
}

/*void Player::hideItem(std::string item)
{
	underGround.push_back(item);
	std::cout << "You have hidden " << item << " to the ground!\n";
}


void Player::fetchHide(std::string item)
{

}
*/


/***************************************************************************
**  This function removes the given item from bag.
***************************************************************************/
void Player::removeItem(std::string itemName)
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag[i] == itemName)
		{
			bag.erase(bag.begin() + i);
		}	
	}	
}


/***************************************************************************
**  This function returns if player has got Grace in his bag.
***************************************************************************/
bool Player::hasGrace()
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag[i] == "Archangel Grace")
		{
			return true;
		}
	}
	return false;	
}


/***************************************************************************
**  This function returns if player has got Fruit in his bag.
***************************************************************************/
bool Player::hasFruit()
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag[i] == "Fruit from Tree of Life")
		{
			return true;
		}
	}
	return false;	
}


/***************************************************************************
**  This function returns if player has got Magic Wood in his bag.
***************************************************************************/
bool Player::hasWood()
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag[i] == "Magic Wood")
		{
			return true;
		}
	}
	return false;	
}


/***************************************************************************
**  This function returns if player has got Seal of Solomon in his bag.
***************************************************************************/
bool Player::hasSeal()
{
	for(unsigned int i = 0; i < bag.size(); i++)
	{
		if(bag[i] == "Seal of Solomon")
		{
			return true;
		}
	}
	return false;	
}


/***************************************************************************
**  This function returns if player has got all ingredients in his bag.
***************************************************************************/
bool Player::ingredientsGet()
{
	if(hasSeal() && hasFruit() && hasGrace())
	{
		return true;
	}
	else
	{
		return false;	
	}
}