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
// StackImpl.cpp
#include "Stack.h"
#include <cassert>
#include <iostream>
using namespace std; 
class StackImpl
{
	int *data;
    int count;
	int capacity;
    enum {BLOCK_SIZE = 5};
public:
	 void grow();
	StackImpl();

    ~StackImpl(); 

    void push(int); 

    void pop();

    int top();

    int size();
};
StackImpl::StackImpl() 
{
	data = new int[BLOCK_SIZE];
    capacity = BLOCK_SIZE;
	count =0;
}  

StackImpl::~StackImpl() {
    delete [] data;
}

void StackImpl::push(int x) {
	 if (count == capacity)
        grow();
    assert(count < capacity);
    data[count++] = x;
}

void StackImpl::pop() {
	if (count == 0)
	{
     throw EmptyStackException( );
   	}
  	count--;
} 

int StackImpl::top() {
	if (count == 0) 
	{
     throw EmptyStackException( );
   	}
	int s = count-1;
	return data[s];
} 
 
int StackImpl::size() {
    return count;
}
void StackImpl::grow() {
    assert(capacity > 1);
    int new_capacity = static_cast<int>(capacity*1.5);
    //cout << "growing from " << capacity << " to " << new_capacity << endl;
    int* new_data = new int[new_capacity];
    for (int i = 0; i < count; ++i)
        new_data[i] = data[i];
    delete [] data;
    data = new_data;
    capacity = new_capacity;
}


 Stack::Stack()
 {
	 Pimpl = new StackImpl;
 }
   Stack::~Stack()
	{
		Pimpl->~StackImpl();
	}

    void Stack::push(int x)
	{
		Pimpl->push(x);
	}

    void Stack::pop()
	{
		Pimpl->pop();
	}

    int Stack::top()
	{
		Pimpl->top();
	}

    int Stack::size()
	{
		Pimpl->size();
	}
	void Stack::grow()
	{
		Pimpl->grow();
	}
