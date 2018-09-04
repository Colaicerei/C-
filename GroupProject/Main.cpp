/******************************************************************************
** Program Name: Group Project - Doodlebugs
** Names: Group 35
** Date: April 27 2018
** Description: Doodlebugs is a 2D predator - prety simulation
******************************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "Validations.hpp"

int main()
{
    std::string tempInput;

    // display welcome message
    std::cout << "*********************************************************\n";
    std::cout << "** Group Project - Doodlebugs                          **\n";
    std::cout << "** By Group 35                                         **\n";
    std::cout << "** - Solomon Deutsch                                   **\n";
    std::cout << "** - Eric Morgan                                       **\n";
    std::cout << "** - Steve Perreault                                   **\n";
    std::cout << "** - Bret Swalberg                                     **\n";
    std::cout << "** - Chen Zou                                          **\n";
    std::cout << "**                                                     **\n";
    std::cout << "** TA Note:                                            **\n";
    std::cout << "** Our group completed the extra credit                **\n";
    std::cout << "*********************************************************\n\n";

    // create menu object and display main menu
    Menu main;
    main.mainMenu();
    
    // prompt before exiting the program
    promptEnter("Press enter to quit the game...");

    return 0;
}