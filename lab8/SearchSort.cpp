/****************************************************************************
** Program name: Searching and Sorting
** Author:       Chen Zou
** Date:         23 May 2018 
** Description:  This is the implmentation file for searching and sorting
			functions, which includes simpleSearch, sorting, and 
			binarySearch functions.
**************************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "SearchSort.hpp"


/*********************************************************************
**  This function searchs a target number through an array and displays 
	message with position if the target is found in the array.
*********************************************************************/   		
void simpleSearch(std::string fileName, int target)
{
	std::vector<int> numbers;
	numbers = createArray(fileName);
	
	for(unsigned int i = 0; i < numbers.size(); i++)
	{
		if(numbers[i] == target)
		{
			std::cout << "\n" << fileName << ": target value found at position "
					  << i << "!\n";
			return;
		}
	}
	std::cout << "\n" << fileName << ": target value not found!\n";
}


/*********************************************************************
**  This function sorts an array of int from input file and export the
	sorted value to an output file. The function using quickSort 
	algorithm from textbook chapter 14. 
*********************************************************************/
void sorting(std::string infileName, std::string outfileName)
{
	std::vector<int> numbers;
	numbers = createArray(infileName);
	std::cout << "Now sorting numbers in " << infileName << "...\n";
	quickSort(numbers, 0, numbers.size()-1);
	// print and export sorted array
	std::ofstream outputFile;
	outputFile.open(outfileName);

	// check if file is sucessfully opened
	if(!outputFile)
	{	
		std::cout << outfileName << " could not be opened!\n";
		exit(1);
	}	
	else
	{
		std::cout << "The sorted numbers are: ";
		for(unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << " ";
			outputFile << numbers[i] << "\n";
		}
		std::cout << std::endl;
		outputFile.close();
	}
}
	


/*********************************************************************
**  This function searchs a target number through an array using
	binary serach algorithm from text book chapter 9, and displays 
	message with postion if the target is found in the array.
*********************************************************************/
void binarySearch(std::string fileName, int target)  
{
	std::vector<int> numbers;
	numbers = createArray(fileName);
	int first = 0, last = numbers.size()-1, 
		middle, position = -1;

	while(first <= last)
	{
		middle = (first + last) / 2;
		if(numbers[middle] == target)
		{
			position = middle;
			std::cout << "\n" << fileName << ": Target value found at position " 
					  << position << "!\n";
			return;
		}
		else if(numbers[middle] > target)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	std::cout << "\n" << fileName << ": Target value not found!\n";
}



/*********************************************************************
** This function reads data from file and creates an array with data.
*********************************************************************/
std::vector<int> createArray(std::string fileName)
{
	std::ifstream inputFile;
	std::vector<int> numbers;
	int value; // value to be read from the file
		
	// open input file
	inputFile.open(fileName);

	// check if file is sucessfully opened
	if(!inputFile)
	{	
		std::cout << fileName << " could not be opened!\n";
		exit(1);
	}	
	else
	{
		// read file one line at a time, loop until end of file 
		while(inputFile >> value)
		{
			numbers.push_back(value);
		}

		inputFile.close();	
	}	

	return numbers;
}
	

/*********************************************************************
**  This function uses the quicksort algorithm to sort array from start
	to end.
*********************************************************************/
void quickSort(std::vector<int> &numbers, int start, int end)
{
	if(start < end)
	{
		int p = partition(numbers, start, end);
		quickSort(numbers, start, p - 1);
		quickSort(numbers, p + 1, end);
	}
}	


/********************************************************************
**  This function rearranges the entry array from start ot end so all 
	value less than the pivot are on the left and others are on the 
	right.
*********************************************************************/
int partition(std::vector<int> &numbers, int start, int end)
{
	int pivot = numbers[start];
	int pivotPos = start;

	for(int pos = start + 1; pos <= end; pos++) 
	{
		if(numbers[pos] < pivot)
		{
			// swap the current item with the item to the right of the pivot,
			// then swap with pivot
			int temp = numbers[pos];
			numbers[pos] = numbers[pivotPos + 1];
			numbers[pivotPos + 1] = numbers[pivotPos];
			numbers[pivotPos] = temp;
			// adjust the pivot position
			pivotPos ++;
		}
	}
	
	return pivotPos;
}
