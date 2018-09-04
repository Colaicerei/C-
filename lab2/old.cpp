/****************************************************************************
** Program name: Letter Counter 
** Author:       Chen Zou
** Date:         12 April 2018
** Description:  This is the letterCounter function implmentation file, the 
		 function takes two parameters: a file stream and an array.
		 The function reads a user specified file filled with letters,
		 count the letter frequencies for each alphabet in the file, 
		 and write the results to a new file.
**i**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "count_letter.hpp"
#include "output_letter.hpp"


/****************************************************************************
** Description: This function takes an input file stream, and a pointer to 
		array of int. It first reads and counts the letter frequencies
		of each paragraph and outputs the results to user specified
		files by calling function output_letters.  
****************************************************************************/ 
const int NUMBER_ALPHABET = 26;

void count_letters(std::ifstream &inputFile, int* array)
{

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
		
		// check the input char against each ascii code, case insenstive, 
		// increment the count accordingly if find match 
		do
		{	
			// count until the end of paragraph 
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


/***************************************************************************
** Description: this function takes an output file stream and a pointer to
		an array of int that contains frequencies of letters. It 
		asks user for the filename to export to, then outputs the 	
		frequencies of letters to the user specified file.
***************************************************************************/
void output_letters(std::ofstream &outputFile, int* array)
{
	std::string fileName;

	std::cout << "Please enter a file name you would like to export to: ";	
	std::getline(std::cin, fileName);
	outputFile.open(fileName);

	// output frequencies followed by char of alphabet
	for(int i = 0; i < NUMBER_ALPHABET; i++)
	{
		outputFile << (char)(97 + i) << ": " << array[i] << "\n";
	}
	outputFile.close();
}
 
