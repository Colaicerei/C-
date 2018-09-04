/*****************************************************************
** Program name: Queue with Circular Linked List
** Author:       Chen Zou
** Date:         15 May 2018 
** Description:  This is the header file of implmentation file of
		Queue class, which includes two data member: a struct
		Node containing value and prev/next pointers, and 
		pointers to the head node of the queue. The class 
		also has functions to add value to the back of the 
		queue, remove the front node of the queue, and display
		the front node value or the whole queue's content.
*****************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
  private:
	// declare a class for the QueneNode
	struct QueueNode
	{
		int val;
		QueueNode* next;
		QueueNode* prev;
		QueueNode(int val, QueueNode* next = nullptr, QueueNode* prev = nullptr)
		{
			this->val = val;
			this->next = next;
			this->prev = prev;
		}
	};
	QueueNode* head;		// pointer to the first QueueNode object	 

  public:
	Queue() {head = nullptr;};
	~Queue();
	bool isEmpty();	// check if queue is empty
	void addBack(int);	//create node with user input and append to the back
	int getFront();	// returns the value of the node at front
	void removeFront();	// removes the front QueueNode
	void printQueue();	// print the queue from head to tail using next

};	

#endif
