/**************************************************************************
** Program name: Matrix Calculator
** Author:       Chen Zou
** Date:         4 April 2018        
** Description:  This program asks the user to choose the size of the matrix
                 between 2x2 or 3x3, then dynamically acclocate the memory
                 space for the matrix. It then calculates the determinant of
                 the matrix and display both the matrix and the determinant
                 to the user.
**************************************************************************/


#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"  

int main()
{
	int size = 0, //declare and initialize size of matrix
            det = 0;  //declare and initialize determinant of matrix
        
	// promote user for the size of the matrix
	std::cout << "Please enter 2 or 3 as the size for the 2D array:\n";
        std::cin >> size;

	while(size != 2 && size != 3)
	{
		// if invalid input, ask user to enter again 	
		std::cout << "Wrong input! the size should be 2 or 3!\n"
			  << "Please enter 2 or 3 as the size for the 2D array:\n";
		std::cin >> size;
	}
	
	// dynamically create a new 2D array of user input size
	int** array = new int*[size];
	for(int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}

		// fill the array using readMatrix function
		readMatrix(array, size);

	// calculate the determinant
	det = determinant(array, size);  

	
// display array and determinant
	std::cout << "Below is the matrix you entered:\n";
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << "\n";
	} 		
	std::cout << "The determinant of the matrix is "
		  << det << ".\n";
 
	// delete the array
	for(int i = 0; i < size; i++) 
	{
		delete [] array[i];
	}
	delete [] array;
	
	return 0;
}  
