/*****************************************************************
** Program name: Doubly-linked List
** Author:       Chen Zou
** Date:         10 May 2018
** Description:  This is the header file of implmentation file of
		class DList, which includes three data members: a 
		struct Node containing value and prev/next pointers,
		and pointers to the head and tail of the list. The
		class also has functions to add node to head/tail, 
		remove node from head/tail, print head or tail,
		and traverse the list in order or reverse order.
*****************************************************************/

#ifndef DLIST_HPP
#define DLIST_HPP

class DList
{
  protected:
	// declare a class for the lise node
	struct Node
	{
		int val;
		Node* next;
		Node* prev;
		Node(int val, Node* next = NULL, Node* prev = NULL)
		{
			this->val = val;
			this->next = next;
			this->prev = prev;
		}
	};
	Node* head;		// list head pointer
	Node* tail;		// list tail pointer	 

  public:
	DList() {head = NULL; tail = NULL;};
	~DList();
	void addHead(int);
	void addTail(int);
	void removeHead();
	void removeTail();
	void reverse();
	void traverse();
	void printHead();
	void printTail();
};	

#endif
