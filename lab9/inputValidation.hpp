/***********************************************************************
** Program name: Stack and Queue STL Containers
** Author:       Chen Zou
** Date:         30 May 2018   
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
int promptPInt(std::string);
int promptIntInRange(std::string, int, int);
int promptInt(std::string);
std::string promptString(std::string);

const bool DEBUG_MESSAGES = false;
void dm(std::string);

#endif  
