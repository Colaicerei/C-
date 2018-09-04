/**************************************************************************************
** Name: Group 35
** Date: April 27 2018
** Description: Interface for the Menu class which contains methods for working with
** the program's main menu
**************************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"
#include "Validations.hpp"

class Menu
{
public:
	Menu();
	~Menu();
	void mainMenu();
};

#endif // !MENU_HPP
