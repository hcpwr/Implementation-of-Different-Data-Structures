#ifndef LLIST_H
#define LLIST_H

#include <string>
class  LList {
   public:
      // create an empty list
      LList();

      // return if the list is empty, false otherwise
      bool isEmpty() const;

      // insert x at the beginning of the list
      // precondition: there is enough heap memory
      // postcondition: x is placed in the list as first element
      void cons(int x);

      // append x to the end of the list
      // precondition: there is enough heap memory
      // postcondition: x is placed as the last element
      void append(int x);

      // return a string consisting of all the elements of the list

      std::string toString() const;

      // return the number of elements in the list
      int length() const;

      // determine if x is in the list
      // postcondition: return true if found, false otherwise
      bool search(int x) const;

      // return the first element of the list and LList::NOT_DEFINED if the list is empty
      int first() const;

      // return the last element of the list and LList::NOT_DEFINED if the list is empty
      int last() const;

      // delete the first occurrence of x in the list 
      // postcondition: return true if x was removed, false otherwise
      bool remove(int x);

      // mutator method (function) that reverses the list
      void reverse();

      // mutator method to transfer all the elements from the 'other' list 

      void splice(LList& other, int pos);

      // return true if the lfSide is equal to the rtSide 
      // meaning that the elements of both lists are equal and in the same order
      friend bool operator == (const LList& lfSide, const LList& rtSide);

      // return true if the lfSide is not equal to the rtSide list, false otherwise
      friend bool operator != (const LList& lfSide, const LList& rtSide);
      
      // copy constructor
      // we assuming that there is enough heap memory to make a copy
      LList(const LList&);

      // overloaded assignment operator
      // we assuming that there is enough heap memory to make a copy
      LList& operator = (const LList&);

      // destructor
      ~LList();

      // string that separates the values of the list in toString 
      static const std::string DELIMITER;

      // value returned when the list is empty and first() or last() is called
      static const int NOT_DEFINED;

   private:
      struct Node {
         int item;
         Node* link;
      };

      Node* head;
      
      // returns a string with an opening "[", 
      // followed by the delimiter followed by each element of the 
      // list which is followed by a delimiter with a "]" closing the list
      static std::string toString(Node * p, std::string delimiter);
      static void append(Node* temp, Node* to_add);
      static int length(Node* temp, int number);
      static bool remove(Node* temp, int x);
      static bool search(Node* temp, int x);
      static int last(Node* temp);
      static bool same_or_not(Node* lfHead, Node* rtHead);
      static LList::Node* reverse(Node* temp, Node* prev, Node* temp2);
};
 
#endif
