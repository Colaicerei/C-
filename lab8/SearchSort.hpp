/********************************************************************
** Program name: Searching and Sorting
** Author:       Chen Zou
** Date:         23 May 2018 
** Description:  This is the header file of the searching and sorting
			functions, which includes simpleSearch, sorting, and 
			binarySearch functions.
********************************************************************/

#ifndef SEARCHSORT_HPP
#define SEARCHSORT_HPP
#include <vector>
#include <string>


void simpleSearch(std::string, int);
void sorting(std::string, std::string);
void binarySearch(std::string, int);
std::vector<int> createArray(std::string);
void quickSort(std::vector<int> &, int, int);
int partition(std::vector<int> &, int, int);

#endif
