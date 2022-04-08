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
// Stack.cpp
#include "stack.h"
#include <cassert>
#include <iostream>
using namespace std;

Stack::Stack() {
    data = new int[BLOCK_SIZE];
    capacity = BLOCK_SIZE;
    count = 0;
}  

Stack::~Stack() {
    delete [] data;
}

void Stack::push(int x) {
    if (count == capacity)
        grow();
    assert(count < capacity);
    data[count++] = x;
}

int Stack::pop() {
  	count--;
	
} 

int Stack::top() {
	int s = count-1;
	return data[s];
} 

int Stack::size() {
    return count;
}

void Stack::grow() {
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


Stack::Stack(const Stack& a) {
    data = new int[a.capacity];
    for (int i = 0; i < a.count; ++i)
        data[i] = a.data[i];
    count = a.count;
    capacity = a.capacity;
}

Stack& Stack::operator=(const Stack& a) {
    delete [] data;
    data = new int[a.capacity];
    for (int i = 0; i < a.count; ++i)
        data[i] = a.data[i];
    count = a.count;
    capacity = a.capacity;
    return *this;
}


