/****************************************************************************
** Program name: Letter Counter 
** Author:       Chen Zou
** Date:         12 April 2018
** Description:  This is the count_letter function implmentation file, the 
		 function takes an input file stream and a pointer to an
		 array of int.  The function reads a user specified file 
		 filled with letters,  count the letter frequencies for each 
		 alphabet in the file for each paragraph,  save the results
		 to the array and output results by calling output_letters.
**i**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "count_letters.hpp"
#include "output_letters.hpp"



void count_letters(std::ifstream &inputFile, int* array)
{
	const int NUMBER_ALPHABET = 26;
	std::string fileName; //file to be opened
	char ch; // character read from the file
	
	std::cout << "Enter the file name for counting: ";
	std::getline(std::cin, fileName);
	
	// open input file
	inputFile.open(fileName);

	// check if file is sucessfully opened
	if(!inputFile)
	{	
		std::cout << fileName << " could not be opened!\n";
		exit(1);
	}	

	// read file one character at a time, loop until end of file 
	ch = inputFile.get();

	// check if file is empty
	if(ch == EOF)
	{
		std::cout << "File is empty!\n";
		exit(1);
	}
	
	
	while(ch != EOF)
	{ 
		std::cout << "\nStart reading new paragraph...\n\n";
		
		// reset array elements to 0 for new paragraph
		for(int i = 0; i < NUMBER_ALPHABET; i++)
		{
			array[i] = 0;
		}
		
		// check the input char against ASCII ascii code of alphabet,
		// case insenstive, increment the count accordingly if find match
		// loop until the end of paragraph 
		do
		{	
			for(int i = 0; i < NUMBER_ALPHABET; i++)
			{	
				if(ch == i + 97 || std::tolower(ch) == i + 97)
				{
					array[i] += 1 ;
				}
			}		
	 		
			// read next character in the file
			ch = inputFile.get();
		}while(ch != '\n' && ch != EOF);
		
		std::cout << "This paragraph is finished!\n"; 
 
		// output results by calling output function
		std::ofstream outputFile;
		output_letters(outputFile, array);
	}
	
	std::cout << "Finished counting the file!" << std::endl;
	inputFile.close(); //close input file
}


 
