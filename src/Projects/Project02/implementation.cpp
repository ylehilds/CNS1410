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
#include "header.h"

void List::push_back(Node* p) {
 if (last == 0)
  first = last = p;
 else {
  last->setNext(p);
  last = p;
 }
 ++count;
}

void List::push_front ( Node* n )
{
     n->setNext(first);
     first = n;
}

void List::delete_front ( )
{
     Node* byeByeNode = first;
     first = first->getNext( );
     delete byeByeNode;
}

void List::insertNode ( Node* here, Node* newNode )
{
     Node* tempPtr = here->getNext( );
     newNode->setNext(tempPtr);
     here->setNext(newNode);
}
Node* List::pop_back( )
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
}
	
