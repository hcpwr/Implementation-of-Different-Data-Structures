#ifndef DEQUE_EXCEPTION_H
#define DEQUE_EXCEPTION_H

#include <stdexcept>
#include <string>

class DequeException : public std::logic_error {  
   public:
      DequeException(const std::string& message = "")
         : logic_error(message.c_str())
      {}  // end constructor
}; // end DequeException
#endif 