#include "Stack.h"
#include <iostream>

Stack::Stack(): n(0), capacity(1),items(new int[1]){}

bool Stack::is_empty() const {
	return n == 0;
}

void Stack::push(int x, int option){
	items[n] = x;
	n++;
	switch(option){
		case 1:
			int* temp_array;
			temp_array = items;
			capacity++;
			items = new int[capacity];
			for(int i = 0; i < n; i++)
				items[i] = temp_array[i];
			delete[] temp_array;
      break;
    case 2:
      if(n == capacity){
        int* temp_array;
        temp_array = items;
        capacity += 10;
        items = new int[capacity];
        for(int i = 0; i < n; i++)
          items[i] = temp_array[i];
        delete[] temp_array;
        break;
      }
    case 3:
      if(n == capacity){
        int* temp_array;
        temp_array = items;
        capacity = capacity * 2;
        items = new int[capacity];
        for(int i = 0; i < n; i++)
          items[i] = temp_array[i];
        delete[] temp_array;
        break;
      }
	}

}

int Stack::pop(){
	if(is_empty()){
		stack_error("ITS EMPTY GENIUS");
	}
		n--;
		return items[n];
}

int Stack::peek() const {
	if(is_empty()){
		stack_error("Cannot peek, empty stack");
	}
	return items[n - 1];
}

void Stack::stack_error(std::string msg) const {
	std::cerr << "Error:  \n" << msg;
	exit(1);
}