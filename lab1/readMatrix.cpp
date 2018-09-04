/***********************************************************************
** Program name: Matrix Calculator
** Author:       Chen Zou 
** Date:         4 April 2018
** Description:  This function has two parameters: a pointer to a 2D array,
                 and an integer as the size of the matrix. The function 
                 rpromotes the user for all the numbers within the matrix.
***********************************************************************/
#include<iostream>
#include"readMatrix.hpp"

void readMatrix(int** array, int size) 
{
	//loop each elements of the 2D array and promote user to fill it   
	for(int i = 0; i < size; i++)        
	{                                   
 		for(int j = 0; j < size; j++)
		{
			std::cout << "Please enter an integer for array[" 
				  << i << "][" << j << "]:" << std::endl;
			std::cin >> array[i][j];
		}
	}
           
}




