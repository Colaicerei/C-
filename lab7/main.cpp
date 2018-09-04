/****************************************************************************
** Program name: Queue with Circular Linked List
** Author:       Chen Zou
** Date:         15 May 2018        
** Description:  This program prompts user to choose an option to add value 
			to the back of the queue, remove the front node of the 
			queue, and display the front node value or the whole 
			queue's content.			
****************************************************************************/

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "Queue.hpp"
#include "inputValidation.hpp"  


int main()
{
	Menu menu;
	Queue intQueue;

	// create menu
	menu.add("Enter a value to be added to the back of queue");
	menu.add("Display the first node (front) value");
	menu.add("Remove the first node (front) value");
	menu.add("Display the queue contents");
	menu.add("Exit");
		
	int choice;
	std::cout << "\nWelcome to my Queue!\n\n";

	menu.display();
	choice = menu.getUserChoice();

	int number;		
	
	while(choice != 5)
	{
		switch(choice)
		{
		case 1: number = menu.promptInt("Please enter an integer you would like to add. ");
				intQueue.addBack(number);
				break;
		case 2: try
				{
					int headVal = intQueue.getFront();
					std::cout << "\nThe first node value is: " << headVal << "\n";
				}
				catch(std::string exceptionString)
				{
					std::cout << exceptionString;
				}	
				break;
		case 3: intQueue.removeFront();
				break;
		case 4: intQueue.printQueue();
				break;
		case 5: std::cout << "\nYou have chosen to quit the program, bye!\n";		 		
				return 1;
		}
		
		menu.display();
		choice = menu.getUserChoice();
		
	}	
		
	return 0;
}	

