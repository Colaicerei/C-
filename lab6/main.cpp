/****************************************************************************
** Program name: Doubly-linked List
** Author:       Chen Zou
** Date:         9 May 2018        
** Description:  This program prompts user to choose an option to create a 
			list from file at the very beginning, add or remove the 
			nodes the head or tail pointer is pointing to, remove 
			nodes at head or tail, print node the head or tail 
			pointing to, and print the list in ordinary or reverse 
			order.
****************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Menu.hpp"
#include "DList.hpp"
#include "inputValidation.hpp"  


int main()
{
	std::cout << "\n\nI did both extra credits, thank you!!!\n\n";
	
	Menu menu;
	DList numberList;

	// create file with numbers
	std::fstream numberFile("numberFile.txt", std::ios::out);
	if(!numberFile)
	{
		std::cout << "Error creating file!";
		return 0;
	}
	std::cout << "Now writing numbers to file...\n";
	numberFile << "2 5 8 3 6 9" << std::endl;
	numberFile.close();

	// create menu
	menu.add("Add a new node to the head");
	menu.add("Add a new node to the tail");
	menu.add("Delete from head");
	menu.add("Delete from tail");
	menu.add("Traverse the list reversely");
	menu.add("Print the value of the Node the head is pointing to");
	menu.add("Print the value of the Node the tail is pointing to");
	menu.add("Exit");
	menu.add("Create a linked list with data from file");
	
	int choice;
	std::cout << "\nWelcome to my linked list!\n\n";

	menu.display();
	choice = menu.getUserChoice();

	int number;		
	
	// create list from number file if user choose option 9
	if(choice == 9)
	{
		numberFile.open("numberFile.txt", std::ios::in);
		if(!numberFile)
		{
			std::cout << "Error opening the file.";
			return 0;
		}
		while(numberFile >> number)
		{
			numberList.addTail(number);
		}
		numberFile.close();
		std::cout << "\nNumbers from file added to the list!\n\n";

		// remove option 9 to prevent user from pulling numbers from file again
		menu.remove(9);
		menu.display();
		choice = menu.getUserChoice();
	}	
	
	// remove option 9 to prevent user from pulling numbers from file again
	menu.remove(9);
	
	while(choice != 8)
	{
		switch(choice)
		{
		case 1: number = menu.promptPInt("Please enter a positive integer. ");
				numberList.addHead(number);
				break;
		case 2: number = menu.promptPInt("Please enter a positive integer. ");
				numberList.addTail(number);
				break;
		case 3: numberList.removeHead();
				break;
		case 4: numberList.removeTail();
				break;
		case 5: numberList.reverse();
				break;
		case 6: numberList.printHead();
				break;
		case 7: numberList.printTail();	
				break;			
		case 8: std::cout << "You have chosen to quit the program, bye!\n";		 		
				return 1;
		}
		
		menu.display();
		choice = menu.getUserChoice();
		
	}	
		
	return 0;
}	

