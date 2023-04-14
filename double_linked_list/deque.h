// Name: 
#ifndef DEQUE_H
#define DEQUE_H
#include <string>
#include "dequeException.h"

class Deque {
   public:
      Deque(); 
      bool isEmpty() const;
      void pushBack(char x);
      void pushFront(char x);
      std::string stringFrontToBack() const;
      char popBack();
      char popFront() ;
      Deque(const Deque&);
      Deque& operator = (const Deque&);
      ~Deque();
      
   private:
      struct Node{
         char element;
         Node* next;
      };
      Node* front;
      Node* back;
      static std::string stringFrontToBack(std::string my_string, Node* first);
      static Node* popBack(Node* first);
      static void copy_this_deque(Node* first, Node* copying_first);
      static void delete_deque(Node* first);
};
#endif 
