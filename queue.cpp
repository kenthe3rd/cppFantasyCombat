/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::QUEUE IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "queue.hpp"
#include <iostream>
using std::cout;
using std::endl;
/******************************************************************************
 *CONSTRUCTOR
 *****************************************************************************/

Queue::Queue()
{
	head = nullptr;
}

/******************************************************************************
 *DESTRUCTOR
 *****************************************************************************/

Queue::~Queue()
{
	if(!this->isEmpty())
	{
		QueueNode* garbage = nullptr;
		
		if(head->next != nullptr)
		{
			QueueNode* findLast = head->next;
			if(head->next->next != head)
			{
				//more than two items in queue
				while(findLast->next != head)
				{
					findLast = findLast->next;
				}
				while(garbage != head)
				{
					garbage = findLast;
					findLast = findLast->prev;
					delete garbage->fighter;
					delete garbage;
				}
			}
			else
			{
				//only two items in queue
				delete head->next->fighter;
				delete head->next;
				delete head->fighter;
				delete head;
			}
		}
		else
		{
			//only one item in queue
			delete head->fighter;
			delete head;
		}
	}
}

/******************************************************************************
 *IS_EMPTY: Returns true if the Queue is empty, otherwise returns false
 *****************************************************************************/

bool Queue::isEmpty()
{
	if(this->head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/******************************************************************************
 *ADD_BACK: Adds a QueueNode to the back of the Queue
 *****************************************************************************/

void Queue::addBack(Character* val, string name)
{
	QueueNode* nullNode = nullptr;
	if(!this->isEmpty())
	{
		if(head->next != nullptr)
		{
			if(head->next->next != head)
			{
				QueueNode* findLast = head;
				
				//there are more than two items in the Queue
				while(findLast->next != head)
				{
					findLast = findLast->next;
				}
				findLast->next = new QueueNode{head, findLast,
				val, name};
				head->prev = findLast->next;
			}
			else
			{
				//there are exactly two items in the Queue
				head->next->next = 
				new QueueNode{head, head->next, val, name};
				head->prev = head->next->next;
			}
		}
		else
		{
			//there is exactly one item in the Queue
			head->next = new QueueNode{head, head, val, name};
			head->prev = head->next;
		}	
	}
	else
	{
		head = new QueueNode{nullNode, nullNode, val, name};
	}
}


/******************************************************************************
 *GET_FRONT: returns the value of the QueueNode at the front of the Queue
 *****************************************************************************/

Character* Queue::getFront()
{
	if(this->isEmpty())
	{
		cout << endl << "ERROR: NO ITEMS IN QUEUE" << endl << endl;
	}
	else
	{
		return head->fighter;
	}
}





/******************************************************************************
 *GET_FRONT_NAME: returns the name of the fighter at the front of the Queue
 *****************************************************************************/

string Queue::getFrontName()
{
	if(this->isEmpty())
	{
		cout << endl << "ERROR: NO ITEMS IN QUEUE" << endl << endl;
	}
	else
	{
		return head->name;
	}
}




/******************************************************************************
 *REMOVE_FRONT: removes an item from the front of the Queue
 *****************************************************************************/

void Queue::removeFront()
{
	QueueNode* garbage = head;
	if(this->isEmpty())
	{
		cout << endl << "ERROR: NO ITEMS IN QUEUE" << endl << endl;
	}
	else
	{
		//there is at least one item in the Queue
		QueueNode* newHead = head->next;
		QueueNode* findLast = head;
		if(head->next != nullptr)
		{
			if(head->next->next != head)
			{
				//there are at least three items in the Queue
				while(findLast->next != head)
				{
					findLast = findLast->next;
				}
				findLast->next = newHead;
				head = newHead;
				head->prev = findLast;
				delete garbage;
			}
			else
			{
				//there are exactly two items in the Queue
				newHead->next = nullptr;
				newHead->prev = nullptr;
				head = newHead;
				delete garbage;	
			}
		}
		else
		{
			//there is only one item in the Queue
			delete head;
			head = nullptr;
		}
		
	}
}


/******************************************************************************
 *PRINT_QUEUE: traverses through the queue
 *****************************************************************************/

void Queue::printQueue()
{
	QueueNode* findLast = head;
	if(this->isEmpty())
	{
		cout << endl << "ERROR: NO ITEMS IN QUEUE" << endl << endl;
	}
	else
	{
		cout << "The queue is:";
		if(head->next != nullptr)
		{
			findLast = head->next;
			if(head->next->next != head)
			{
				cout  <<  head->name << " ";
				while(findLast->next != head)
				{
					cout << findLast->name << " ";
					findLast = findLast->next;
				}
				cout << findLast->name;
			}
			else
			{
				cout << head->name << " " 
				<< findLast->name << endl;
			}
		}
		else
		{
			cout << head->name << endl;
		}
	}
}
