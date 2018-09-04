/***********************************************************************
** Program name: Langton's Ant
** Author:       Chen Zou
** Date:         8 April 2018
** Description:  This is the header file of inputValidation function for 
		 Langton's Ant program, the inputValidation function checks
		 if the input is an integer within a specified range, and 
		 assign the input to the receiving variables once an valid
		 input is entered by the user.
*************************************************************************/

#ifndef inputValidation_HPP
#define inputValidation_HPP

void getInt(int*);
void getIntWithMin(int*, int);
void getIntInRange(int*, int, int);

#endif  
