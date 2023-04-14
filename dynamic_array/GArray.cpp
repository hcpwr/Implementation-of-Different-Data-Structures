/* 
Name: 
Student Number:
code started by Gladys Monagan
*/

#include "GArray.h"
#include <sstream>
#include <string>

using std::string;

// constructor with no arguments, makes an empty array
GArray::GArray() {
	// Array.n(0), Array.items(nullptr), capacity(0);
	A = {0, nullptr, 1};
}

const int GArray::NADA = 0;

// postcondition:
//   returns true if the array is empty, false otherwise
bool GArray::isEmpty() const {
	return A.n == 0 ? true : false;
}

void GArray::append(int x) {
	if(A.n == 0){
		A.n += 1;
		A.items = new int[A.n];
		A.items[0] = x;
	}else{
		int temp[A.n];
		for(int i = 0; i < A.n; i++)
			temp[i] = A.items[i];
		A.n += 1;
		A.capacity *= 2;
		A.items = new int[A.n];
		for(int i = 0; i < A.n - 1; i++)
			A.items[i] = temp[i];
		A.items[A.n - 1] = x;
	}
}

// make a string from the values of the array enclosed in "{ " followed by the value
// followed by a blank and then "}"
string GArray::toString() const {
	string str = "{ ";
	for(int i = 0; i < A.n; i++){
    str = str + std::to_string(A.items[i]) + " ";

  }
		// str.push_back(std::to_string(A.items[i]));
    // str.push_back(char(A.items[i]));
    str += "}";
  return str;
}

int GArray::length() const {
	return A.n;

}

bool GArray::search(int x) const {
	for(int i = 0; i < A.n; i++)
		if(A.items[i] == x)
			return true;
	return false;
}

// postcondition:
//   returns the first element of the array if it exists or GArray::NADA otherwise
int GArray::first() const {
	return A.n == 0 ? GArray::NADA : *A.items;
}

// postcondition:
//   returns the last element of the array if it exists or GArray:: NADA otherwise
int GArray::last() const {
	return A.n == 0 ? GArray::NADA : A.items[A.n - 1];
}

void GArray::reverse() {
	for(int i = 0, z = A.n - 1; i < A.n / 2; i++, z--)
		A.items[i] = A.items[z];
}

bool operator == (const GArray& lfSide, const GArray& rtSide) {
	return GArray::equalArrays(lfSide.A, rtSide.A);
}


bool GArray::equalArrays(const Array& a, const Array& b) {
	int count = 0;
	if(a.n == b.n)
		for(int i = 0; i < a.n; i++)
			if(a.items[i] == b.items[i])
				count++;
	if(count == a.n)
		return true;
	return false;
}

GArray::Array GArray::copyArray(const Array& from) {
	A = from;
	return A;
}

void GArray::deleteArray(Array& array) {
	delete array.items;
	// delete *array;
}

// copy constructor 
// precondition:
//   there is enough heap memory to make a full copy
GArray::GArray(const GArray& other) {
	A = other.A;
}

// overload the assignment operator
GArray& GArray::operator = (const GArray& other) {
   if (this != &other) {
   	copyArray(other.A);
   }
   return *this;
}

// destructor
GArray::~GArray(){
	GArray::deleteArray(A);
}
