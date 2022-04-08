// File Prologue
// Author: Lehi Alcantara 
// Course: CNS 1410
// section: 002     
// Professor: Charles Allison
// Project: Project Nine
// Date Written: October 2nd, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.

#ifndef Stack_H
#define Stack_H
 
class StackImpl;
class Stack {
	
private:
		StackImpl* Pimpl;
public:
// default constructor	
// Purpose: initialize object's values 
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    Stack();
// destructor
// Purpose: destroys dynamic Allocated storage 
// Parameters:none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    ~Stack();
// Purpose: copies (push) to the Stack
// Parameters: integer
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    void push(int); 
// Purpose: to decrement count
// Parameters: none
// Returns:none
// Pre-conditions: none 
// Post-conditions: none  
    void pop() ;
// Purpose: to peek at thetop of the array or Stack
// Parameters:none
// Returns: int
// Pre-conditions: none 
// Post-conditions: none 
    int top();
// Purpose: kepps track of size
// Parameters: none
// Returns: count
// Pre-conditions: none 
// Post-conditions: none 
    int size();
// Purpose: grow stack array
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
	void grow();
};

 class EmptyStackException{
public:
	EmptyStackException()
		:message ("the Stack is empty, therefore can not top/pop the Stack\n"){ }
	
     const char* what ( ) const { return message; }
	
   private:
      const char* message;
	
 };
 
 
#endif

