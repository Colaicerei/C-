/****************************************************************************
** Program name: Queue with Circular Linked List
** Author:       Chen Zou
** Date:         15 May 2018 
** Description:  This is the function implmentation file for the Queue class,
		which includes two data member: a struct Node containing
		value and prev/next pointers, and pointers to the head 
		node of the queue. The class also has functions to add 
		value to the back of the queue, remove the front node of 
		the queue, and display the front node value or the whole 
		queue's content.
**************************************************************************/

#include <string>
#include <iostream>
#include "Queue.hpp"


// destructor
Queue::~Queue()
{
	while(!isEmpty())
	{
		std::cout << "calling destructor\n";
		// check if there is only one node
		if(head->next == head)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			QueueNode* garbage = head;
			head = head->next;
			head->prev = garbage->prev;
			garbage->prev->next = head;
			//garbage->next = nullptr;
			//garbage->prev = nullptr;
			delete garbage;
		}
	}
}	


/****************************************************************************
**  This function checks if the queue is empty. If so, returns true, 
	otherwise returns false.
****************************************************************************/
bool Queue::isEmpty()
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
void Queue::addBack(int val)
{
	// if list is empty, add to head
	if(isEmpty())
	{
		head = new QueueNode(val);
		head->next = head;
		head->prev = head;
	}
	// if there is only one node, add new node and link to head
	else if(head->next == head)
	{
		QueueNode* n = new QueueNode(val);
		head->next = n;
		n->prev = head;
		head->prev = n;
		n->next = head;
	}
	else	
	{
		// find tail and unlink the circle
		QueueNode* tail = head->prev;
		//tail->next = nullptr;
		//head->prev = nullptr;
		
		// create a new node and append to tail
		QueueNode* n = new QueueNode(val);
		tail->next = n;
		n->prev = tail;
		// link the new node to head
		n->next = head;
		head->prev = n;
	}
	// traverse print the list
	printQueue();
}


/****************************************************************************
**  This function returns the value of the node at the front of the queue.
****************************************************************************/
int Queue::getFront()
{
	// if empty, show message do nothing
	if(isEmpty())
	{
		throw std::string("\nWarning! The queue is empty!\n");
	}
	// otherwise return the front node value
	else
	{
		return head->val;
	}
}
	

/****************************************************************************
**  This function removes the front QueneNode of the queue.
****************************************************************************/
void Queue::removeFront()
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
		QueueNode* temp = head;
		QueueNode* tail = head->prev;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete temp;
	}
	// traverse print the list
	printQueue();
}


/****************************************************************************
**  This function prints the queue from head to tail using next pointer.
****************************************************************************/
void Queue::printQueue()
{
	// if empty, do nothing
	if(isEmpty())
	{
		std::cout << "\nThe list is empty!\n";
		return;
	}
	else if(!head->next)
	{
		std::cout << "\nYour linked list is: ";
		std::cout << head->val;
	}
	else
	{
		QueueNode* n = head;
		std::cout << "\nYour linked list is: ";
		do
		{
			std::cout << n->val << " ";
			n = n->next;
		}while(n != head);

		std::cout << std::endl; 
	}	
}

