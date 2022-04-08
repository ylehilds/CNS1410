# include <iostream>
using namespace std;
class Node
{
	private:
		string Quantity;
		string Item;
		Node* Next;
	public:
		Node();
		string getQuantity();
		string getItem();
		void setQuantity(const string&);
		void setItem(const string&);
		void setNext(Node*);
		Node* getNext();
	
};

class List
{
private:
	
	Node* first;
	Node* last;
	int counter;
	public:
		Node* getfirst();
		List();	//	A constructor that creates an empty list object. 

	 void push_back(Node*); //function that takes a Node* as a parameter and adds the node pointed to by the pointer to the end of the list. 
	 void push_front(Node*); // function that takes a Node* as a parameter and adds the node pointed to by the pointer to the front of the list. 
	 Node* pop_back( ); //function that removes the last node from the list, and returns a pointer to this node. Important, do not delete the node in this function. Simply unlink it from the list. 
	Node* pop_front( );  //function that removes the first node from the list, and returns a pointer to this node. Important, do not delete the node in this function. Simply unlink it from the list. 
	Node* getFirst( );  //function that returns a pointer to the first node in the list. 

	
};