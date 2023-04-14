#include "LList.h"
#include <string>
#include <sstream>

using std::string;

const string LList::DELIMITER = string(" ");

// initialize NOT_DEFINED

// constructor with no arguments, makes an empty list
// code can be modified below if you choose to have a dummy head node

//I chose a negative 1 because with Linked List -1 does not represent anything. It is more or less good fit for NOT_DEFINED
const int LList::NOT_DEFINED = -1;

LList::LList() {
   this->head = nullptr;
}

// precondition:
//   LList::DELIMETER has been initialized
// postcondition:
//    return a string of the form 
//          [ DELIMITER element DELIMITER ... element DELIMITER ]
// code needs to be modified if you choose to have a dummy head node
string LList::toString() const {
   string str = "[";
   str += toString(this->head, DELIMITER);
   str += "]";
   return str;
}

// postcondition:
//    return a string of the form 
//         [ delimiter element ... element delimiter element delimiter ]
string LList::toString(Node * p, string delimiter) {
   if (p == nullptr) {
      return delimiter;
   }
   std::stringstream ss;
   ss << delimiter;
   ss << p->item;
   ss << toString(p->link, delimiter);
   return ss.str();
}

bool LList::isEmpty() const{
   if(!head)
      return true;
   return false;
}

void LList::cons(int x){
   Node* temp_node = new Node;
   temp_node->item = x;
   temp_node->link = head;
   this->head = temp_node;
}

void LList::append(int x){
  Node* temp_node = new Node;
  temp_node->item = x;
  temp_node->link = nullptr;
  if(isEmpty()){
    head = temp_node;
    return;
  }
  Node* temp = head;
  append(temp, temp_node);
}

void LList::append(Node* temp, Node* to_add){
  if(temp -> link)
    return append(temp->link, to_add);
  else
    temp->link = to_add;
}

int LList::length() const{
  if(isEmpty())
    return 0;
  return length(head, 1);
}

int LList::length(Node* temp, int number){
  if(temp->link){
    return number + length(temp->link, number + 1);
  }
  return 1;
}

bool LList::remove(int x){
  if(isEmpty())
    return false;
  if(head->item == x){
    if(head->link){
      Node* temp = head->link;
      head = temp;
    }
    else head = nullptr;
    return true;
  }
  return remove(head, x);
}

bool LList::remove(Node* temp, int x){
  Node* another_temp;
  if(temp->link)
    another_temp = temp->link;
  if(another_temp->item == x){
    temp->link = another_temp->link;
    // delete another_temp;
    return true;
  }
  if(temp->link)
    return remove(temp->link, x);
  return false;
}

bool LList::search(int x) const{
  if(isEmpty())
    return false;
  return search(head, x);
}

bool LList::search(Node* temp, int x){
  if(temp->item == x)
    return true;
  if(temp->link)
    return search(temp->link, x);
  return false;
}

int LList::first() const{
  if(isEmpty())
    return NOT_DEFINED;
  return head->item;
}

int LList::last() const{
  return last(head);
}

int LList::last(Node* temp){
  if(temp->link)
    return last(temp->link);
  return temp->item;
}

LList::LList(const LList& to_be_copied){
  if(to_be_copied.isEmpty())
    head = nullptr;
  else {
    Node* this_node = head;
    Node* copying_node = to_be_copied.head;
    Node* temp = copying_node;
    while(temp->link){
      Node* temp_node = new Node;
      temp_node->item = temp->link->item;
      this_node->link = temp_node;
      temp = temp->link;
      this_node = this_node->link;
    }
  }
}

bool operator == (const LList& lfSide, const LList& rtSide){
  if((!lfSide.head && rtSide.head) || (lfSide.head && !rtSide.head))
    return false;
  if(!lfSide.head && !rtSide.head)
    return true;
  return LList::same_or_not(lfSide.head, rtSide.head);

}

bool LList::same_or_not(Node* lfHead, Node* rtHead){
  if(lfHead->item != rtHead->item)
    return false;
  if(lfHead->link && rtHead->link){
    return same_or_not(lfHead->link, rtHead->link);
  }
  return false;
}

void LList::reverse(){
  if(!this->head)
    return;
   reverse(this->head, nullptr, nullptr);
}

void LList::reverse(Node* temp, Node* prev, Node* temp2){
  if(temp->link){
    temp2 = temp->link;
    temp->link = prev;
    prev = temp;
    temp = temp2;
    reverse(temp->link, prev, temp2); 
  }
}

LList& LList::operator = (const LList&to_be_copied){
  if(to_be_copied.isEmpty())
    head = nullptr;
  else {
    Node* this_node = head;
    Node* copying_node = to_be_copied.head;
    Node* temp = copying_node;
    while(temp->link){
      Node* temp_node = new Node;
      temp_node->item = temp->link->item;
      this_node->link = temp_node;
      temp = temp->link;
      this_node = this_node->link;
    }
  }
  return *this;
}

bool operator != (const LList& lfSide, const LList& rtSide){
  if((!lfSide.head && rtSide.head) || (lfSide.head && !rtSide.head))
    return true;
  if(!lfSide.head && !rtSide.head)
    return false;
  return !LList::same_or_not(lfSide.head, rtSide.head);
}

// destructor
// finish the comment on postcondition:
// postcondition: 
LList::~LList(){
   delete head;
}
