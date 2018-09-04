/****************************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the function implmentation file for the Team class,
		which includes two data member: a struct Node containing
		value and prev/next pointers, and pointers to the head 
		node of the queue. The class also has functions to add 
		value to the back of the queue, remove the front node of 
		the queue, and display the front node value or the whole 
		queue's content.
**************************************************************************/

#include <string>
#include <iostream>
#include "Team.hpp"


// destructor
Team::~Team()
{
	// std::cout << "Calling destructor";
	while(!isEmpty())
	{
		if(head->next == head)
		{
			delete head->fighter;
			delete head;
			head = nullptr;
		}
		else
		{
			TeamNode* garbage = head;
			head = head->next;
			head->prev = garbage->prev;
			garbage->prev->next = head;
			//garbage->next = nullptr;
			//garbage->prev = nullptr;
			delete garbage->fighter;
			delete garbage;
		}
	}
}	


/****************************************************************************
**  This function checks if the queue is empty. If so, returns true, 
	otherwise returns false.
****************************************************************************/
bool Team::isEmpty()
{
	if(head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/****************************************************************************
**  This function takes an int, creates a new queuenode with the value and 
	appends it to the back of the queue.
****************************************************************************/
void Team::addBack(Character* fighter)
{
	// if list is empty, add to head
	if(isEmpty())
	{
		head = new TeamNode(fighter);
		head->next = head;
		head->prev = head;
	}
	// if there is only one node, add new node and link to head
	else if(head->next == head)
	{
		TeamNode* n = new TeamNode(fighter);
		head->next = n;
		n->prev = head;
		head->prev = n;
		n->next = head;
	}
	else	
	{
		// find tail and unlink the circle
		TeamNode* tail = head->prev;
		//tail->next = nullptr;
		//head->prev = nullptr;
		
		// create a new node and append to tail
		TeamNode* n = new TeamNode(fighter);
		tail->next = n;
		n->prev = tail;
		// link the new node to head
		n->next = head;
		head->prev = n;
	}
	// traverse print the list
	//printQueue();
}


/****************************************************************************
**  This function returns the character at the front node of the queue.
****************************************************************************/
Character* Team::getFront()
{
	// if empty, throw exception message and do nothing
	if(isEmpty())
	{
		throw std::string("\nWarning! The team is empty!\n");
	}
	// otherwise return the first fighter
	else
	{
		return head->fighter;
	}
}
	

/****************************************************************************
**  This function removes the front QueneNode of the queue.
****************************************************************************/
void Team::removeFront()
{
	// if empty, show message and do nothing
	if(isEmpty())
	{
		std::cout << "\nThe list is empty!\n";
		return;
	}
	// if there is only one node, delete it and set head to null
	else if(head->next == head)
	{
		delete head;
		head = nullptr;
	}
	// otherwise delete the head and reassign head to next node
	else
	{
		TeamNode* temp = head;
		TeamNode* tail = head->prev;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete temp;
	}
	// traverse print the list
	//printQueue();
}


/****************************************************************************
**  This function prints the team queue from head to tail using next pointer.
****************************************************************************/
void Team::printQueue()
{
	// if empty, do nothing
	if(isEmpty())
	{
		std::cout << "\nThe team is empty!\n";
		return;
	}
	else if(!head->next)
	{
		std::cout << "\nThe team has: ";
		std::cout << head->fighter->getName();
	}
	else
	{
		TeamNode* n = head;
		std::cout << "\nThe team has: ";
		do
		{
			std::cout << n->fighter->getName() << " ";
			n = n->next;
		}while(n != head);

		std::cout << std::endl; 
	}	
}



/****************************************************************************
**  This function prints the queue from htail to head using prev pointer.
****************************************************************************/
void Team::printReverse()
{
	// if empty, do nothing
	if(isEmpty())
	{
		std::cout << "\nThe container is empty!\n";
		return;
	}
	else if(!head->prev)
	{
		std::cout << "\nFrom top to bottom, the container has: ";
		std::cout << head->fighter->getName();
	}
	else
	{
		// find the last node of the queue
		TeamNode* n = head->prev;
		std::cout << "\nFrom top to bottom, the container has: ";
		do
		{
			std::cout << n->fighter->getName() << " ";
			n = n->prev;
		}while(n != head->prev);

		std::cout << std::endl; 
	}	
}


/****************************************************************************
**  This function takes an int, creates a new queuenode with the value and 
	appends it to the back of the queue.
****************************************************************************/
void Team::addFront(Character* fighter)
{
	// if list is empty, add to head
	if(isEmpty())
	{
		head = new TeamNode(fighter);
		head->next = head;
		head->prev = head;
	}
	// if there is only one node, add to front and link to the only node
	else if(head->next == head)
	{
		TeamNode* n = new TeamNode(fighter);
		head->prev = n;
		n->next = head;
		head->next = n;
		n->prev = head;
		head = n;
	}
	else	
	{
		// find tail and unlink the circle
		TeamNode* tail = head->prev;
		//tail->next = nullptr;
		//head->prev = nullptr;
		
		// create a new node and insert to front
		TeamNode* n = new TeamNode(fighter);
		head->prev = n;
		n->next = head;
		// link the new node to tail
		n->prev = tail;
		tail->next = n;
		// make n the head node
		head = n;
	}
	// traverse print the list
	//printQueue();
}


