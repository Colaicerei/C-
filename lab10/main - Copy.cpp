/****************************************************************************
** Program name: Efficiency of recursive Vs itertion
** Author:       Chen Zou
** Date:         2 Jun 2018        
** Description:  This program compares efficiency of Fibonacci algorithm using 
			recursive and iteration. by running the functions for a 
			certain times to get noticable results.
****************************************************************************/

#include <iostream>
#include <string>
#include "Fib.hpp"
#include <cstdlib>
#include <ctime>
 

int main()
{
		
	clock_t timeNR; // clock time for nor-recursive function
	clock_t timeR;  // clock time for recursive function
	
	int N = 40;
	int f; // fibonacci number
	int rounds = 10000; // rounds for running functions

	// calculate time for non-recursive function 
	std::cout << "\nNow calculating Fibonacci for" << rounds << " times using iteration function....\n";
	for(int i = 10; i <= N; i+=2)
	{
		timeNR = clock();
		for(int j = 0; j < rounds; j++)
		{
			f = FibonacciNR(i);
		}
		std::cout << "Fibonacci number for " << i << "= " << f;
		timeNR = clock() - timeNR;
		std::cout << std::scientific << ". Running for 10000 times took " << timeNR << " clicks ("
				  << ((double)timeNR)/CLOCKS_PER_SEC << " seconds).\n";
	}

	// calculate time for recursive function 
	std::cout << "\nNow calculating Fibonacci for" << rounds << " times usingrecursive function....\n";
	for(int i = 10; i <= N; i+=2)
	{
		timeR = clock();
		for(int j = 0; j < rounds; j++)
		{
			f = FibonacciR(i);
		}
		std::cout << "Fibonacci number for " << i << "= " << f;
		timeR = clock() - timeR;
		std::cout << std::scientific << ". Running for 10000 times took " << timeR << " clicks ("
				  << ((double)timeR)/CLOCKS_PER_SEC << " seconds).\n";
	}

	return 0;

}	

