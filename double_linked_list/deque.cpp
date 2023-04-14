// Name: 
#include "deque.h"
#include "dequeException.h"
#include <string>
using std::string;

//construct an empty Deque

Deque::Deque(): front(nullptr), back(nullptr) {}

bool Deque::isEmpty() const {
	return (front == nullptr && back == nullptr);
}

// complexity: 
void Deque::pushBack(char x) {
	Node* new_node = new Node;
	new_node->element = x;
	new_node->next = nullptr;
	if(isEmpty()){
		back = new_node;
		front = new_node;
	}else{
		back->next = new_node;
		back = new_node;
	}
	return;
}

// complexity:
void Deque::pushFront(char x) {
	Node* new_node = new Node;
	new_node->element = x;
	if(isEmpty()){
		new_node->next = nullptr;
		front = new_node;
		back = new_node;	
	}else{
		new_node->next = front;
		front = new_node;
	}
	return;
}

//return a string of all chars in a list opening with [ and closing with ], no spaces
string Deque::stringFrontToBack() const {
	if(isEmpty())
		return "[]";
	return stringFrontToBack("[", front); 
}

string Deque::stringFrontToBack(string my_string, Node* first){
	if(first->next){
		my_string = my_string + first->element;
		return stringFrontToBack(my_string, first->next);
	}else{
		my_string = my_string + first->element;
	}
	return my_string + "]";
}

//remove and return last element if there is one otherwise throw exception
// complexity:
char Deque::popBack() {
	if(isEmpty())
		throw DequeException("Trying to pop from an empty list");
	char to_return;
	if(front->next){
		Node* temp;
		temp = popBack(front);
		to_return = back->element;
		delete back;
		back = temp;
	}else{
		to_return = front->element;
		delete front;
		delete back;
	}
	return to_return;
}

Deque::Node* Deque::popBack(Node* first){
	Node* temp = first->next;
	// if(temp->next == nullptr){
	// 	return first;
	// }
	// if(temp->next)
	// 	return popBack(first->next);
	// // return temp;
	while(temp->next){
		first = first->next;
		temp = first->next;
	}
	return first;
}

//remove and return first element if there is one otherwise throw exception
// complexity:
char Deque::popFront() {
	if(isEmpty())
		throw DequeException("Trying to pop from an empty list");
	Node* temp = front;
	char to_return = temp->element;
	delete front;
	front = temp->next;
	delete temp; 
	return to_return;
}

Deque::Deque(const Deque& other) {
	if(other.isEmpty()){
		front = nullptr;
		back = nullptr;
	}
	back->element = other.back->element;
	front->element = other.front->element;
	copy_this_deque(front, other.front);
}

void Deque::copy_this_deque(Node* current_first, Node* copying_first){
	if(copying_first->next){
		current_first->next = new Node;
		current_first->next->element = copying_first->next->element;
		return copy_this_deque(current_first->next, copying_first->next);
	}
}

// complexity:
Deque& Deque::operator = (const Deque& rtSide) {
	if(rtSide.isEmpty()){
		delete_deque(front);
		front = nullptr;
		back = nullptr;
	}
	copy_this_deque(front, rtSide.front);
	return *this;
}

Deque::~Deque(){
	delete_deque(front);
	delete back;
}

void Deque::delete_deque(Node* first){
	if(first->next){
		Node* temp = first;
		delete first;
		return delete_deque(temp->next);
	}
}