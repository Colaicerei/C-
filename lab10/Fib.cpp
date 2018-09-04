/****************************************************************************
** Program name: Efficiency of recursive Vs itertion
** Author:       Chen Zou
** Date:         2 Jun 2018   
** Description:  This is the implmentation file for two Fibonacci functions,
			one with recursive algorithm and one with
			iteration. Source: Julian @codeproject.com.
**************************************************************************/

#include <string>
#include <iostream>
#include "Fib.hpp"


/*********************************************************************
**  This function implements Fibonacci series using iteration algorithm.
*********************************************************************/   		
int FibonacciNR(int n)
{
	int first = 0;
	int second = 1;
	int counter = 2;
	while(counter < n)
	{
		int temp = second;
		second = first + second;
		first = temp;
		++counter;
	}

	if(n == 0)
		return 0;
	else
		return first + second;	
}


/*********************************************************************
** This function implements Fibonacci series using recursive.
*********************************************************************/
int FibonacciR(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	return FibonacciR(n-1) + FibonacciR(n-2);
}
	

