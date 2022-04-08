// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002  
// Professor: Charles Allison 
// Project: Project two
// Date Written: September 8th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.
 

#ifndef HEADER_H
#define HEADER_H

template<class T>
class Node {
T data;
Node<T>* next;
public: 
 Node();
 void  setItem(const T& s);
 T getItem() const;
 void setQty(const T& s);
 void setNext(T* n);
 Node<T>* getNext();
};


template<class T>
Node<T> :: Node ()
{
 next = 0;
}
template<class T>
void Node<T> :: setItem(const T& s) {
  data = s;
 }
template<class T>
T Node<T> :: getItem() const {
  return data;
 }
 template<class T>
 void Node <T> :: setQty(const T& s) {
  data = s;
 }

 template<class T>
 void Node<T> :: setNext(T* n) {
  next = n;
 }
 template<class T>
T Node<T> :: getNext() {
  return next;
 }




template<class T>
class List {
Node<T>* first;
Node<T>* last;
int count;
public:
List();
//~List();
void push_back(const T&);
Node<T> getfirst();
int getcount const;
};


	
template<class T>
 List<T> :: List() {
  first = last = 0;
  count = 0;
 }
 
template<class T>
void List<T> :: push_back(const T& p)
{
if (last == 0)
  first = last = p;
else 
{
last->setNext(p);
last = p;
}
 ++count;
}

 template<class T>
 Node<T> :: Node<T>* getFirst() {
 return first;
 }

 int :: getCount() const {
  return count;
 }











	













































/*
#include <string>
using std::string;

class Node {
int data;
 Node* next;
public:
// default Constructor
// Purpose: initializes Pointer next to zero
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
 Node() {
  next = 0;
 }
 // setter 
// Purpose: sets the name of the item (node)
// Parameters: a string
// Returns: none
// Pre-conditions: input in the parameter a string 
// Post-conditions: none 
 void setItem(const int& s) {
  data = s;
 }
// getter	
// Purpose: gets the item (node) name 
// Parameters: none
// Returns: the item's name name
// Pre-conditions: none 
// Post-conditions: none 
 int getItem() const {
  return data;
 }
// Purpose: sets the quantity of a node
// Parameters: A string
// Returns: none
// Pre-conditions: 1 string 
// Post-conditions: none 
 void setQty(const int& s) {
  data = s;
 }
// Purpose: gets the quantity of a node
// Parameters: none
// Returns: quantity
// Pre-conditions: none 
// Post-conditions: none 
 int getQty() const {
  return data;
 }
// setter
// Purpose: sets the next node
// Parameters: A Pointer
// Returns: none
// Pre-conditions: parameter has to be a pointer 
// Post-conditions: none 
 void setNext(Node* n) {
  next = n;
 }
// getter Pointer
// Purpose: Points to the next item (node) in the list
// Parameters: none
// Returns: a Pointer
// Pre-conditions: none
// Post-conditions: none
 Node* getNext() {
  return next;
 }
};

class List {
 Node* first;
 Node* last;
 int count;
public:
// default Constructor, creates an empty list object
// Purpose: to construct the class
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
 List() {
  first = last = 0;
  count = 0;
 }
// Purpose: takes a Node* as a parameter and adds the node pointed to by the pointer to the end of the list. 
// Parameters: a pointer 
// Returns: none
// Pre-conditions: has to be a Pointer parameter 
// Post-conditions: none 
 void push_back(Node*);
// Purpose: function that returns a pointer to the first node in the list. 
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
 Node* getFirst() {
  return first;
 }
// Purpose: counts nodes 
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
 int getCount() const {
  return count;
 }

};
*/
#endif
