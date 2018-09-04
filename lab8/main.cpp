/****************************************************************************
** Program name: Searching and Sorting
** Author:       Chen Zou
** Date:         23 May 2018        
** Description:  This program provides user the options of simple search,
			sorting and binary search, and use algorithms to search 
			data from input file and sort data and save to output
			file. 
****************************************************************************/

#include <iostream>
#include <string>
#include "SearchSort.hpp"
#include "Menu.hpp"
#include <fstream>
#include <vector>
#include "inputValidation.hpp"  

int main()
{
		
	// create menu
	Menu menu;
	int choice;
	
	
	menu.add("Simple Search");
	menu.add("Sorting");
	menu.add("Binary Search");
	menu.add("Exit");
	menu.display();

	choice = menu.getUserChoice();

	int target; // target number to search
	std::string sortedNum;
	std::string sortedEarly;
	std::string sortedMiddle;
	std::string sortedEnd;
	while(true)
	{
		switch(choice)
		{	
			case 1:	target = promptInt("What is the target value? ");
					simpleSearch("num.txt", target);
					simpleSearch("early.txt", target);
					simpleSearch("middle.txt", target);
					simpleSearch("end.txt", target);
					break;
			case 2: sortedNum = promptString("Please enter the file name for the sorted array: ");
					sorting("num.txt", sortedNum);
					sortedEarly = promptString("Please enter the file name for the sorted array: ");
					sorting("early.txt", sortedEarly);
					sortedMiddle = promptString("Please enter the file name for the sorted array: ");
					sorting("middle.txt", sortedMiddle);
					sortedEnd = promptString("Please enter the file name for the sorted array: ");					
					sorting("end.txt", sortedEnd);
					break;
			case 3: target = promptInt("What is the target value? ");
					binarySearch(sortedNum, target);
					binarySearch(sortedEarly, target);
					binarySearch(sortedMiddle, target);
					binarySearch(sortedEnd, target);
					break;
			case 4: std::cout << "You have chosen to exit the program, bye!\n";
					return 1;
		}
	
		std::cout << "\nWould you like to make another choice?\n";
		menu.display();
		choice = menu.getUserChoice();
	}	
		
	return 0;

}	

