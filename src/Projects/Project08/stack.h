// File Prologue
// Author: Lehi Alcantara 
// Course: CNS 1410
// section: 002     
// Professor: Charles Allison
// Project: Project Eight
// Date Written: October 29th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
// P.S. -> Professor Allison gave us the skeleton of this code.

#ifndef STACK_H
#define STACK_H

class Stack {
    int* data;
    int count;
    int capacity;
    enum {BLOCK_SIZE = 5};
    void grow();
public:
// default constructor	
// Purpose: initialize object's values 
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    Stack();
// parameterized constructor	
// Purpose: Allocates storage for characters and does a deep copy
// Parameters: object same type as the caller object
// Returns: makes a deep copy
// Pre-conditions: none 
// Post-conditions: none 	
    Stack(const Stack&);
// operator overloading	=
// Purpose: to compare two objects
// Parameters: an object
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    Stack& operator=(const Stack&);
// destructor
// Purpose: destroys dynamic Allocated storage 
// Parameters:none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    ~Stack();
// Purpose: copies (push) to the stack
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
    int pop();
// Purpose: to peek at thetop of the array or stack
// Parameters:none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
    int top();
// Purpose: kepps track of size
// Parameters: none
// Returns: count
// Pre-conditions: none 
// Post-conditions: none 
    int size();
};

#endif

