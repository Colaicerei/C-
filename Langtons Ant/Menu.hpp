/*********************************************************************
**Program name: Langton's Ant Simulation
**Author:       Chen Zou
**Date: 	12 April 2018
**Description:  This is the header file for class Menu, the Menu class
		has functions to validate and take user choice, add
		or remove user specified menu items, and display and 
		clear the menu,      
**********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

class Menu
{
	private:
		std::vector<std::string> list; // list of menu items
		std::string title; 	       // menu title	
		

	public:
		Menu();
		void setTitle(std::string);
		std::string getTitle();
		void showTitle();
		void add(std::string);
		void remove(int);
		void clear();
		void display(); 
		int getUserChoice();
};


#endif
