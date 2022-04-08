// File Prologue
// Author: Lehi Alcantara 
// Course: CNS 1410
// section: 002  
// Professor: Charles Allison 
// Project: Project ten
// Date Written: September 14th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.


#ifndef HEADER_H
#define HEADER_H
using namespace std;

template<class T>
class Node
{
T data;
Node<T>* next;
public:
Node() 
	{
		next = 0;
	}
~Node()
	{
	//cout << " Node dest was called" << endl;
	}
    
void setData(const T& s) 
	{
		data = s;
	}

T getData() const 
	{
		return data;
	}
void setNext(Node<T>* n)
	{
		next = n;
	}

Node<T>* getNext()
	{
		return next;
	}
 
};

template <class T>
class Iterator 
{
	Node <T>* pos;
public:
Node<T>* getPos ()
{
	return pos;
}
Iterator(Node<T>* p)
	{
		pos = p;
	}

~Iterator()
	{
		//cout << "iterator dest was called" << endl;
	}
	
T operator*() 
{
	return pos->getData();
}

void operator++()
{
    if (pos)
        pos=pos->getNext();
}

bool operator==(const Iterator<T>& b)
{
	if ( pos == b.pos )
			return true;
		else
			return false;
}

bool operator!=(const Iterator<T>& b)
{
	if ( pos != b.pos )
			return true;
		else
			return false;
}

};

template<class T>
class List 
{
	Node<T>* first;
	Node<T>* last;
	int count;
public:
	void push_back(T t) 
{
    Node<T>* p = new Node<T>;
    p->setData(t);
	if (last == 0)
		first = last = p;
	else 
	{
	last->setNext(p);
	last = p;
	}
++count;
}

List() 
	{
		first = last = 0;
		count = 0;
	} 

~List() 
	{
		while (first != 0)
		{
			Node<T>* temp = new Node<T>; 
			temp = first->getNext();
			delete first;
			first = temp;
		//	cout << "List dest was called" << endl;
		}
		
	} 
const Iterator<T> begin( )
	{ 
		Iterator<T> anIterator(first);
		return anIterator;
		
	}
	   
const Iterator<T> end( ) 
	{
		 Iterator<T> anIterator1(0);
		 return anIterator1;
	} 

const List<T>& operator=(List<T>& b)
       {
              Iterator<T> a = begin();
              Iterator<T> c = b.begin();
               while (c != b.end())
               {
                       double temp = c.getPos()->getData();
                       push_back(temp);
                       ++c;
               }
			   return *this;
} 

List (List& b) 
       {
               first = b.first;
               last = b.last;
               count = b.count;
       }
int size() const {
    return count;
}
};

#endif
 
 




