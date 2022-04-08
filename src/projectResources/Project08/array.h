#ifndef ARRAY_H
#define ARRAY_H

class Array {
    int* data;
    int count;
    int capacity;
    enum {BLOCK_SIZE = 5};
    void grow();
public:
    Array();
    Array(const Array&);
    Array& operator=(const Array&);
    ~Array();
    void push_back(int);
    int pop_back(int);
    int& at(int);
    int size() const;
};

#endif

