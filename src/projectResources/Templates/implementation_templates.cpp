// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002  
// Professor: Charles Allison
// Project: Project ten
// Date Written: November 11th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.
#include "header_templates.h"

template<class T>
Node<T> :: Node(){
T data = 0;;
Node <T>* next;
}
template<class T>
void Node<T> :: setData(const T& s) {
  data = s;
 }
template<class T>
Node<T> :: Node<T> getData(){
  return data;
 }
template<class T>
void Node<T> :: setNext(Node<T>* n) {
  next = n;
 }
template<class T>
Node<T> :: Node<T>* getNext() {
  return *next;
 }

template<class T>
Iterator()
{
	Node <T>* a = first; 
}
template<class T>
Iterator(Node<T>* b)
{
	Node <T>* b = first; 
}
template<class T>
T& operator*()
{
	
}
template<class T>
Iterator<T>& operator++()
{
	
}
template<class T>
Iterator<T> operator++(int)
{
	
}
template<class T>
bool operator==(const Iterator<T>& a)
{
	count = a.count;
   Node<T>* p = NULL;
   Node<T>* q = a.first;
   while (q != NULL)
   {
      Node<T>* n = new Node<T>;
      n->getNext (NULL);
      n->setData (q->getData( ));
      if (p == NULL)
         first = n;
      else
         p->setNext (n);
      p = n;
      q = q.getNext( );
   }
return *this;
}
template<class T>
bool operator!=(const Iterator<T>&)
{
	 Node<T>* n = new Node<T>;
      n->getNext (NULL);
      n->setData (q->getData( ));
      if (p == NULL)
         first = n;
      else
         p->setNext (n);
      p = n;
      q = q.getNext( );
}



template<class T>
List<T>::List()
{  
   first = NULL;
   last = NULL;
}
template<class T>
void List<T>::push_back(const T& p) { 
 if (last == 0) 
  first = last = p;
 else {
  last->setNext(p);
  last = p;
 } 
 ++count;
}

template<class T>
List <T>::begin() { 
return Iterator<T> first;
}

template<class T>
List <T>::end() { 
return Iterator<T>last+1;
}
template<class T>
List<T>::~List() {

   Node<T>* p = first;
   while ( p!=NULL)
   {
      Node<T>* pnext = p->getNext( );
      delete p;
      p = pnext;
	}
}
template<class T>
List<T>::List(List<T>& a)
{
	count = a.count;
   Node<T>* p  =NULL;
   Node<T>* q = a.first;
   while (q != NULL)
   {
      Node<T>* n = new Node<T>;
      n->getNext (NULL);
      n->setData (q->getData( ));
      if (p == NULL)
         first = n;
      else
         p->setNext (n);
      p = n;
      q = q.getNext( );
   }

}
}
template<class T>
const List<T>& List<T>::operator=(const List<T>& a)
{
	count = a.count;
   Node<T>* p  =NULL;
   Node<T>* q = a.first;
   while (q != NULL)
   {
      Node<T>* n = new Node<T>;
      n->getNext (NULL);
      n->setData (q->getData( ));
      if (p == NULL)
         first = n;
      else
         p->setNext (n);
      p = n;
      q = q.getNext( );
   }
return *this;
}


