// Array.cpp
#include "array.h"
#include <cassert>
#include <iostream>
using namespace std;

Array::Array() {
    data = new int[BLOCK_SIZE];
    capacity = BLOCK_SIZE;
    count = 0;
} 

Array::~Array() {
    delete [] data;
}

void Array::push_back(int x) {
    if (count == capacity)
        grow();
    assert(count < capacity);
    data[count++] = x;
}

int Array::pop_back(int y) {
	data[count--] = y;
	delete[] data;
}

int& Array::at(int n) {
    assert(n < count);
    return data[n];
}

int Array::size() const {
    return count;
}

void Array::grow() {
    assert(capacity > 1);
    int new_capacity = static_cast<int>(capacity*1.5);
    cout << "growing from " << capacity << " to " << new_capacity << endl;
    int* new_data = new int[new_capacity];
    for (int i = 0; i < count; ++i)
        new_data[i] = data[i];
    delete [] data;
    data = new_data;
    capacity = new_capacity;
}

Array::Array(const Array& a) {
    data = new int[a.capacity];
    for (int i = 0; i < a.count; ++i)
        data[i] = a.data[i];
    count = a.count;
    capacity = a.capacity;
}

Array& Array::operator=(const Array& a) {
    delete [] data;
    data = new int[a.capacity];
    for (int i = 0; i < a.count; ++i)
        data[i] = a.data[i];
    count = a.count;
    capacity = a.capacity;
    return *this;
}


