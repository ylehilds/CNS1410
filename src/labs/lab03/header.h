// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002  
// Professor: Charles Allison
// Project: Lab Three
// Date Written: September 5th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.


class Node
{
    private:
		string item;
        string quantity;
        Node* next;
    public:
// getter	
// Purpose: gets the item (node) name 
// Parameters: none
// Returns: the name
// Pre-conditions: none 
// Post-conditions: none 
	string getName( );
// setter 
// Purpose: sets the name of the item (node)
// Parameters: a string
// Returns: none
// Pre-conditions: input in the parameter a string 
// Post-conditions: none 
	void setName(string);
// getter Pointer
// Purpose: Points to the next item (node) in the list
// Parameters: none
// Returns: a Pointer
// Pre-conditions: none
// Post-conditions: none
	Node* getNext( );
// setter
// Purpose: sets the next node
// Parameters: A Pointer
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
	void setNext(Node*);
// Purpose: Parameterized constructor
// Parameters: 2 strings
// Returns: none
// Pre-conditions: 2 strings 
// Post-conditions: none 
	Node(:string, :string)
// Purpose: sets the quantity of a node
// Parameters: A string
// Returns: none
// Pre-conditions: 1 string 
// Post-conditions: none 
	setQuantity(:string) :void
// Purpose: gets the quantity of a node
// Parameters: none
// Returns: quantity
// Pre-conditions: none 
// Post-conditions: none 
	getQuantity( ) :string

}; 
class List
{
    private:
         int number;
         Node* first;
    public:
// default Constructor, creates an empty list object
// Purpose: to construct the class
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
		List();
// getter
// Purpose: gets the number of nodes objects in the list
// Parameters: none
// Returns:  a size of list (the number of a node object)
// Pre-conditions: none 
// Post-conditions: none 
	string getNumber( );
// Purpose: Initializes the class information of the employee
// Parameters: takes a Pointer and adds the node pointed to by the pointer to the front of the list. 
// Returns: none
// Pre-conditions: has to be a Pointer parameter 
// Post-conditions: none 
//A push_front(Node*) function that takes a Node* as a parameter and adds the node pointed to by the pointer to the front of the list. 
void push_front(Node* );
// Purpose: function that removes the first node from the list, and returns a pointer to this node. 
// Parameters: none
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
//A pop_front( ) function that removes the first node from the list, and returns a pointer to this node. Important, do not delete the node in this function. Simply unlink it from the list. 
void pop_front( );
// Purpose: deletes the node
// Parameters: takes a Pointer 
// Returns: none
// Pre-conditions: has to be a Pointer parameter 
// Post-conditions: none 
delete_front(:Node*)
// Purpose: insert a node
// Parameters: takes 2 Pointers. 
// Returns: none
// Pre-conditions: has to be 2 Pointer parameters 
// Post-conditions: none  
insertNode(:Node*, Node*): void

}; 

