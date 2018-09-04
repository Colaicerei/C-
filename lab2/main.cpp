/***********************************************************************
** Program name: Letter Counter
** Author:       Chen Zou
** Date:         12 April 2018
** Description:  This is the main file for program letter counter, the 
		 program counts the frequencies of each alphabet for 
		 each paragrah in a file specified by user, and exports
		 the results to the output files specified by user.
***********************************************************************/

#include <iostream>
#include <fstream>
#include "count_letters.hpp"

int main()
{
	const int NUMBER_ALPHABET = 26;
	int array[NUMBER_ALPHABET] = {0};
	
	std::ifstream inputFile;
	std::ofstream outPutFile;

	// count the number of each alphabet
	count_letters(inputFile, array);

	// export results to output files
	//output_letters(&outputFile, array);

	return 0;
}

