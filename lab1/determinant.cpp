/***********************************************************************
** Program name: Matrix Calculator
** Author:       Chen Zou 
** Date:         4 April 2018
** Description:  This function has two parameters: a pointer to a 2D array,
                 and an integer as the size of the matrix. The function 
                 takes in the 2D array with the value inside the matrix,
                 and calculates and returns the determinant.    
***********************************************************************/

#include "determinant.hpp"

int determinant(int** array, int size) 
{
	int result = 0;
	if(size == 2)
	{	//determinant calculation for 2D matrix
		result = array[0][0]*array[1][1] - array[0][1]*array[1][0];
	}
	else
	{	//determinant calculation for 3D matrix   
		result = array[0][0]*(array[1][1]*array[2][2]-array[1][2]*array[2][1]) - 
			 array[0][1]*(array[1][0]*array[2][2]-array[1][2]*array[2][0]) +
			 array[0][2]*(array[1][0]*array[2][1]-array[1][1]*array[2][0]);
	}

	return result;
}  
