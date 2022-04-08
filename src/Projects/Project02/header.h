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

#include <string>
using std::string;

class Node {
 string item;
 string qty;
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
 void setItem(const string& s) {
  item = s;
 }
// getter	
// Purpose: gets the item (node) name 
// Parameters: none
// Returns: the item's name name
// Pre-conditions: none 
// Post-conditions: none 
 string getItem() const {
  return item;
 }
// Purpose: sets the quantity of a node
// Parameters: A string
// Returns: none
// Pre-conditions: 1 string 
// Post-conditions: none 
 void setQty(const string& s) {
  qty = s;
 }
// Purpose: gets the quantity of a node
// Parameters: none
// Returns: quantity
// Pre-conditions: none 
// Post-conditions: none 
 string getQty() const {
  return qty;
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
// Purpose: takes a Pointer and adds the node pointed to by the pointer to the front of the list. 
// Parameters: a Pointer
// Returns: none
// Pre-conditions: has to be a Pointer parameter 
// Post-conditions: none 
 void push_front(Node*);
// Purpose: takes a Node* as a parameter and adds the node pointed to by the pointer to the end of the list. 
// Parameters: a pointer 
// Returns: none
// Pre-conditions: has to be a Pointer parameter 
// Post-conditions: none 
 void push_back(Node*);
// Purpose: function that removes the first node from the list, and returns a pointer to this node. 
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
 Node* pop_front();
 // Purpose: function that removes the last node from the list, and returns a pointer to this node
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
 Node* pop_back();
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
// Purpose: deletes the node
// Parameters: takes a Pointer 
// Returns: none
// Pre-conditions: has to be a Pointer parameter 
// Post-conditions: none 
void delete_front();
// Purpose: insert a node
// Parameters: takes 2 Pointers. 
// Returns: none
// Pre-conditions: has to be 2 Pointer parameters 
// Post-conditions: none  
void insertNode ( Node* here, Node* newNode );
};

#endif
