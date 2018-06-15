/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::QUEUE HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "character.hpp"
#include <string>
using std::string;
struct QueueNode
{
	QueueNode* next;
	QueueNode* prev;
	Character* fighter;
	string name;
};

class Queue
{
	private:
		QueueNode* head;		
	public:
		Queue();
		~Queue();
		bool isEmpty();
		void addBack(Character* val, string name);
		Character* getFront();
		string getFrontName();
		void removeFront();
		void printQueue();
};
#endif
