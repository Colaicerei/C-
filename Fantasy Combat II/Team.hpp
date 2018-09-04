/*****************************************************************
** Program name: Fantasy Combat Tournament
** Author:       Chen Zou 
** Date:         16 May 2018
** Description:  This is the header file of implmentation file of
		class Team, which includes two data member: a 
		struct Node containing value and prev/next pointers, 
		and pointers to the head node of the queue. The 
		class also has functions to add value to the back of
		the queue, remove the front node of the queue, and 
		display the front node value or the whole queue.
*****************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
class Team
{
  private:
	// declare a struct of node of characters
	struct TeamNode
	{
		Character* fighter;
		TeamNode* next;
		TeamNode* prev;
		TeamNode(Character* fighter, TeamNode* next = nullptr, TeamNode* prev = nullptr)
		{
			this->fighter = fighter;
			this->next = next;
			this->prev = prev;
		}
	};
	TeamNode* head;		// pointer to the first fighter object	 

  public:
	Team() {head = nullptr;};
	~Team();
	bool isEmpty();	// check if team is empty
	void addBack(Character*);	//create node with user input and append to the back
	void addFront(Character*);	//create node with user input and insert to the front
	Character* getFront();	// returns the front node character
	void removeFront();	// removes the front TeamNode
	void printQueue();	// print the team from head to tail using next
	void printReverse(); // print the container from tail to head
};	

#endif
