/***********************************************************************
** Program name: Doubly-linked List
** Author:       Chen Zou
** Date:         9 May 2018 
** Description:  This is the header file of inputValidation function. The
		 inputValidation functions check if the input is an integer
		 which meets a specified value requirements, then assign
		 the input value to the receiving variables once an valid
		 input is entered by the user.
*************************************************************************/

#include <string>
#ifndef inputValidation_HPP
#define inputValidation_HPP

void getInt(int*);
void getIntWithMin(int*, int);
void getIntInRange(int*, int, int);
void getIntWithMax(int*, int);
void getIntFromTwo(int*, int, int);
void getDouble(double*);
void getWord(std::string*);

#endif  
