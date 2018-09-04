/****************************************************************************
** Program name: Stack and Queue STL Containers
** Author:       Chen Zou
** Date:         30 May 2018  
** Description:  This is the implmentation file for functions using the Stack 
			and Queue STL, which includes a buffer simulation
			using Queue, and a palindrome creation using Stack.
**************************************************************************/

#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include "StackNQueue.hpp"


/*********************************************************************
**  This function takes percentage of chance to add and remove from 
	user, then add or remove a randomly generated number based on the
	specified percentage, and display the numbers in the queue and 
	the average length of the queue after each round, until the user 
	specified numbebr of rounds run out.	
*********************************************************************/   		
void buffer(int pctAdd, int pctRM, int rounds)
{
	std::queue<int> iQueue;
	int N; //random number to add
	int appendN; // random number to test if append
	int removeN; // random number to test if remove
	double averageL = 0; // average length of the queue
	for(int i = 0; i < rounds; i++)
	{
		N = rand() % 1000 + 1;
		appendN = rand() % 100 + 1;
		// add to the queue if appendN less or equal than user specified pct
		if(appendN <= pctAdd)
		{
			iQueue.push(N);
		}
		// remove the front if removeN <= user specified pct
		removeN = rand() % 100 + 1;
		if(removeN <= pctRM)
		{
			if(iQueue.empty())
			{
				std::cout << "No value to pop! The queue is empty!\n";
			}
			else
			{
				iQueue.pop();
			}	
		}

		// display the values in the buffer
		if(iQueue.empty())
		{
			std::cout << "After round " << i + 1 << ", there is no value in the queue!\n";
		}
		else
		{
			std::cout << "The values after round " << i + 1 << " are: ";
			// make a temp queue copying from iQueue
			std::queue<int> tempQueue;
			tempQueue = iQueue;
		
			while(!tempQueue.empty())
			{
				std::cout << tempQueue.front() << " ";
				tempQueue.pop();
			}
			std::cout << std::endl;
		}

		// display the average length
		int length = iQueue.size();
		averageL = static_cast<double>((averageL * (i + 1 - 1) + length) / (i + 1)); 
		std::cout <<"The average length of buffer is: " << averageL << "\n\n";
	}
}


/*********************************************************************
**  This function takes a string input from user, and returnSs a
	palindrome created with the string. 
*********************************************************************/
std::string palindrome(std::string inputStr)
{
	std::stack<char> cStack;
	std::string newStr = inputStr;

	// store the characters from string into stack
	for(unsigned int i = 0; i < inputStr.length(); i++)
	{
		cStack.push(inputStr[i]);
	}

	// display the original string
	// std::cout << "The palindrome created is: " << inputStr;

	// add the reversed string to original string 
	while(!cStack.empty())
	{
		newStr += cStack.top();
		cStack.pop();
	}

	// return updated string
	return newStr;
}
	

