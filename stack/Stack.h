#ifndef STACK
#define STACK

#include <string>

class Stack{
	public:
		//construct an empty stac k
		Stack();

		//Determine whether this stack is empty
		//Return true if stack is empty false otherwise

		bool is_empty() const;

		//Add an item to the top of this stack
		//ERROR or exception if stack is full
		//Stack overflow
		//post condition: item is on top of the stack
		void push(int x, int option);

		//retrieves and removes the top of this stack
		//ERROR or exception if stack if empty
		//Stack overflow
		//postcondition: returned is the item that was most recently added
		int pop();

		//retrieves the top of this stack
		//ERROR  or Exception if stack is empty
		//postcondition: returned is the item that was most recently added
		int peek() const;


	private:
		void stack_error(std::string msg) const;
		int n;
    int capacity;
		int* items;
};

#endif