/****************************************************************************
** Program name: Efficiency of recursive Vs itertion
** Author:       Chen Zou
** Date:         2 Jun 2018        
** Description:  This program compares efficiency of Fibonacci algorithm using 
			recursive and iteration. by running the functions for a 
			certain times to get noticable results.
			modified from source:
			en.cppreference.com/w/c/chrono/clock 
****************************************************************************/

#include <iostream>
#include <string>
#include "Fib.hpp"
#include <cstdlib>
#include <time.h>

int main()
{
		
	timespec start, end; // start and end timespec
	double timeNR; // time for nor-recursive function
	double timeR;  // time for recursive function
	
	int N = 30;
	int f; // fibonacci number
	int rounds = 10000; // rounds for running functions

	// calculate time for non-recursive function 
	std::cout << "\nNow calculating Fibonacci numbers for " << rounds << " times using iteration function....\n";
	for(int i = 10; i <= N; i+=2)
	{
		// get start time
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
		for(int j = 0; j < rounds; j++)
		{
			f = FibonacciNR(i);
		}
		std::cout << i << "th Fibonacci number is " << f;
		// get end time and calculate time used
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
		timeNR = 1000 * (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_nsec - start.tv_nsec);
		std::cout << ". Running for " << rounds << " times, CPU used " << timeNR << " ms.\n";
	}

	// calculate time for recursive function 
	std::cout << "\nNow calculating Fibonacci numbers for " << rounds << " times usingrecursive function....\n";
	for(int i = 10; i <= N; i+=2)
	{
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
		for(int j = 0; j < rounds; j++)
		{
			f = FibonacciR(i);
		}
		std::cout << i << "th Fibonacci number is " << f;
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
		timeR = 1000 * (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_nsec - start.tv_nsec);
		std::cout << ". Running for " << rounds << " times, CPU used " << timeR << " ms.\n";
	}

	return 0;

}	

