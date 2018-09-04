/****************************************************************************
** Program name: Letter Counter 
** Author:       Chen Zou
** Date:         12 April 2018
** Description:  This is the output_letters function implmentation file, the 
		 function takes an output file stream and a pointer to an
		 array of int that contains frequencies of letters. It asks
		 user for theh filename to export to, then outputs the
		 frequencies of letters to the user specifies file.
**i**************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "output_letters.hpp"


void output_letters(std::ofstream &outputFile, int* array)
{
	const int NUMBER_ALPHABET = 26;
 	std::string fileName;

	// promote and get filename to export to
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
 
