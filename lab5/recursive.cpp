/****************************************************************************
** Program name: Recursive functions
** Author:       Chen Zou
** Date:         5 May 2018
** Description:  This is the function implmentation file for three recursive
		functions, including printing an input string in reverse,
		calculating the sum of an input array, and triangular of a  
		number.
**************************************************************************/

#include <string>
#include <iostream>
#include "recursive.hpp"


/****************************************************************************
**  This function takes an input string and prints the input string in reverse
	order without reverse the string.
****************************************************************************/
void printReverse(std::string inputString)
{
	if(inputString.empty())
	{
		std::cout << "\n";
	}
	else
	{
		std::cout << inputString[inputString.length()-1];
		std::string newStr = inputString;
		newStr.pop_back();
		printReverse(newStr);
	}
}


/****************************************************************************
**  This function takes an array and size, then calculates and returns the 
	sum of the array.
****************************************************************************/
int sumArray(int* array, int size)
{
	if(size > 1)
	{
		return array[size-1] + sumArray(array, size-1);
	}
	return array[0];
}


/****************************************************************************
**  This function takes a number and calculates and returns the triangular of 
	the number.
****************************************************************************/
int triangular(int N)
{
	if(N > 0)
	{
		return N + triangular(N - 1);
	}
	return 0;	 
}