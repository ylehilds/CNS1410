#include "classes.h"
#include <iostream>
#include <string>
//using namespace std;
using std::string;
Node :: Node()
{
	Next = 0;
}
string Node :: getQuantity()
{
	return Quantity;
}
string Node :: getItem()
{
	return Item;
}
 void Node :: setQuantity(const string& n)
 {
	Quantity = n;
 }
void Node ::setItem(const string& p)
{
	Item = p;
}
	
List :: List()
{
	first=last=0;
	counter = 0;
	
}
void Node :: setNext(Node* a)
{
	Next=a;
}
void List::push_back(Node* w)
{
	if (last == 0)
	{
		first=last=w;
	}
	else 
	{
		last->setNext(w);
		last =w;
	}
	++counter;
}

Node* Node::getNext()
{
	return Next;
}
Node* List:: getfirst()
{
	return first;
}
 void List ::push_front(Node* e)
 {
	e->setNext(first);
	first = e;
 }
 /*Node* List::pop_back( )
{
  Node* temp = last;
  Node* iter = getFirst();
  //assert(iter != 0);
  while (iter->getNext() != last) {
  iter = iter->getNext();
  }
	iter->setNext(0);
	last = iter;
	return temp;
	
}
Node* List::pop_front( )
{
	Node* unlink = first;
	first = first->getNext( );
	return unlink;
}*/