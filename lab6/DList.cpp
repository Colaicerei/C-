/****************************************************************************
** Program name: Doubly-linked List
** Author:       Chen Zou
** Date:         10 May 2018
** Description:  This is the function implmentation file for the Dlist
		class, wincludes three data members: a struct Node containing
		value and prev/next pointers, and pointers to the head and 
		tail of the list., the class also has functions to add node
		to head/tail, remove node from head/tail, print head or tail,
		and traverse the list in order or reverse order.
**************************************************************************/

#include <string>
#include <iostream>
#include "DList.hpp"


// destructor
DList::~DList()
{
	Node* nodePtr = head;
	while(nodePtr != NULL)
	{
		Node* garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}	


/****************************************************************************
**  This function takes an int, creates a new node with the value and add the
	node to the head of the list.
****************************************************************************/
void DList::addHead(int number)
{
	// if list is empty, add value to head
	if(!head)
	{
		head = new Node(number);
		head->next = NULL;
		head->prev = NULL;
		// tail also points to the only node
		tail = head;
	}	
	else
	{	
		Node* n = new Node(number);
		n->next = head;
		head->prev = n;
		head = n;
		head->prev = NULL;
	}

	// traverse print the list
	traverse();
}


/****************************************************************************
**  This function takes an int, creates a new node with the value and add the
	node to the tail of the list.
****************************************************************************/
void DList::addTail(int number)
{
	// if list is empty, add to head
	if(!head)
	{
		head = new Node(number);
		head->next = NULL;
		head->prev = NULL;
		// tail also points to the only node
		tail = head;
	}
	else
	{
		Node* n = new Node(number);
		n->prev = tail;
		tail->next = n;
		tail = n;
		tail->next = NULL;
	}

	// traverse print the list
	traverse();
}


/****************************************************************************
**  This function checks if the list is empty and removes the head node if it
	is not empty.
****************************************************************************/
void DList::removeHead()
{
	// if empty, show message do nothing
	if(!head)
	{
		std::cout << "\nThe list is empty!\n";
		return;
	}
	// if there is only one node, delete it and set head and tail to null
	else if(!head->next)
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	// otherwise delete the head and reassign head to the next node
	else
	{
		Node* n = head;
		head = head->next;
		head->prev = NULL;
		delete n;
	}
	// traverse print the list
	traverse();
}
	

/****************************************************************************
**  This function checks if the list is empty and removes the head node if it
	is not empty.
****************************************************************************/
void DList::removeTail()
{
	// if empty, show message and do nothing
	if(!tail)
	{
		std::cout << "\nThe list is empty!\n";
		return;
	}
	// if there is only one node, delete it and set head and tail to null
	else if(!tail->prev)
	{
		delete tail;
		tail = NULL;
		head = NULL;
	}
	// otherwise delete the tail and reassign tail to the previous node
	else
	{
		Node* n = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete n;
	}
	// traverse print the list
	traverse();
}


/****************************************************************************
**  This function checks if the list is empty, if not, prints the list in 
	reverse order.
****************************************************************************/
void DList::reverse()
{
	// if empty, show message and do nothing
	if(!tail)
	{
		std::cout << "\nThe list is empty!\n";
		return;
	}
	else
	{
	
	Node* n = tail;
	while(n)
	{
		std::cout << n->val << " ";
		n = n->prev;
	}
	std::cout << std::endl;
	}
}
	

/****************************************************************************
**  This function checks if the list is empty, and prints the list from head
	to tail, if it is not empty.
****************************************************************************/
void DList::traverse()
{
	// if empty, do nothing
	if(!head)
	{
		std::cout << "\nThe list is empty!\n";
		return;
	}
	else
	{
		Node* n = head;
	std::cout << "\nYour linked list is: ";
	while(n)
	{
		
		std::cout << n->val << " ";
		n = n->next;
	}
	std::cout << std::endl; 
	}	
}


/****************************************************************************
**  This function checks if the list is empty, if not, prints the value of 
	the Node the head is pointing to.
****************************************************************************/
void DList::printHead()
{
	if(!head)
	{
		std::cout << "\nno number in the list\n";
	}	
	else
	{
		std::cout << "\nThe value the head node is pointing to is: ";
		std::cout << head->val;
	}
}	


/****************************************************************************
**  This function checks if the list is empty, if not, prints the value of 
	the Node the tail is pointing to.
****************************************************************************/
void DList::printTail()
{
	if(!tail)
	{
		std::cout << "\nno number in the list\n";
	}
	else
	{	
		std::cout << "\nThe value the tail node is pointing to is: ";
		std::cout << tail->val;
	}
}		