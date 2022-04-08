#include <string>
#include <iostream>
#include <cassert>

using namespace std;

template<typename T> class List;
template<typename T> class Iterator;

template<typename T>
class Node
{
public:
   /* 
      Constructs a node with a given data value.
      @param s the data to store in this node
   */
   Node(T s);
private:
   T data;
   Node<T>* previous;
   Node<T>* next;
friend class List<T>;
friend class Iterator<T>;
};

template<typename T>
class List
{
public:
   /**
      Constructs an empty list;
   */
   List();
   /**
      Appends an element to the list.
      @param s the value to append
   */
   void push_back(T s);
   /**
      Inserts an element into the list.
      @param iter the position before which to insert
      @param s the value to append
   */
   void insert(Iterator<T> iter, T s);
   /**
      Removes an element from the list.
      @param i the position to remove
      @return an iterator pointing to the element after the
      erased element
   */
   Iterator<T> erase(Iterator<T> i);
   /**
      Gets the beginning position of the list.
      @return an iterator pointing to the beginning of the list
   */
   Iterator<T> begin();
   /**
      Gets the past-the-end position of the list.
      @return an iterator pointing past the end of the list
   */
   Iterator<T> end();

   void remove(const T& value);
   void reverse();
   void unique();
private:
   Node<T>* first;
   Node<T>* last;
};

template<typename T>
class Iterator
{
public:
   /**
      Constructs an iterator that does not point into any list.
   */
   Iterator();
   /**  
      Looks up the value at a position.
      @return the value of the node to which the iterator points
   */
   T get() const;
   /**
      Advances the iterator to the next node.
   */
   void next();
   /**
      Moves the iterator to the previous node.
   */
   void previous();
   /**
      Compares two iterators
      @param b the iterator to compare with this iterator
      @return true if this iterator and b are equal
   */
   bool equals(Iterator b) const;
private:
   Node<T>* position;
   Node<T>* last;
friend class List<T>;
};

template<typename T>
Node<T>::Node(T s)
{  
   data = s;
   previous = NULL;
   next = NULL;
}

template<typename T>
List<T>::List()
{  
   first = NULL;
   last = NULL;
}

template<typename T>
void List<T>::push_back(T s)
{  
   Node<T>* newnode = new Node<T>(s);
   if (last == NULL) /* list is empty */
   {  
      first = newnode;
      last = newnode;
   }
   else
   {  
      newnode->previous = last;
      last->next = newnode;
      last = newnode;
   }
}

template<typename T>
void List<T>::insert(Iterator<T> iter, T s)
{  
   if (iter.position == NULL)
   {  
      push_back(s);
      return;
   }

   Node<T>* after = iter.position;
   Node<T>* before = after->previous;
   Node<T>* newnode = new Node<T>(s);
   newnode->previous = before;
   newnode->next = after;
   after->previous = newnode;
   if (before == NULL) /* insert at beginning */
      first = newnode;
   else
      before->next = newnode;
}

template<typename T>
Iterator<T> List<T>::erase(Iterator<T> i)
{  
   Iterator<T> iter = i;
   assert(iter.position != NULL);
   Node<T>* remove = iter.position;
   Node<T>* before = remove->previous;
   Node<T>* after = remove->next;
   if (remove == first)
      first = after;
   else
      before->next = after;
   if (remove == last)
      last = before;
   else
      after->previous = before;
   iter.position = after;
   delete remove;
   return iter;
}

template<typename T>
Iterator<T> List<T>::begin()
{  
   Iterator<T> iter;
   iter.position = first;
   iter.last = last;
   return iter;
}

template<typename T>
Iterator<T> List<T>::end()
{  
   Iterator<T> iter;
   iter.position = NULL;
   iter.last = last;
   return iter;
}

template<typename T>
Iterator<T>::Iterator()
{  
   position = NULL;
   last = NULL;
}

template<typename T>
T Iterator<T>::get() const
{  
   assert(position != NULL);
   return position->data;
}

template<typename T>
void Iterator<T>::next()
{  
   assert(position != NULL);
   position = position->next;
}

template<typename T>
void Iterator<T>::previous()
{  
   if (position == NULL)
      position = last;
   else 
      position = position->previous;
   assert(position != NULL);
}

template<typename T>
bool Iterator<T>::equals(Iterator b) const
{  
   return position == b.position;
}

template<typename T>
void List<T>::remove(const T& value)
{
   Iterator<T> p = begin();
   Iterator<T> q = end();
   while (! p.equals(q))
   {
      if (p.get() == value) 
      {
	 Iterator<T> r = p;
	 p.next();
	 erase(r);
      }
      else
	 p.next();
   }
}

template<typename T>
void List<T>::reverse()
{
   Iterator<T> p = begin();
   Iterator<T> q = end();
   while (! p.equals(q))
   {
      q.previous();
      if (p.equals(q))
	 return;
      // swap the two values
      T temp = p.position->data;
      p.position->data = q.position->data;
      q.position->data = temp;
      p.next();
   }
}

template<typename T>
void List<T>::unique()
{
   Iterator<T> p = begin();
   Iterator<T> q = end();
   while (! p.equals(q))
   {
      Iterator<T> r = p;
      p.next();
      if ((! p.equals(q)) && r.get() == p.get())
	 erase(r);
   }
}

int main()
{  
   List<int> a;

   a.push_back(1);
   a.push_back(2);
   a.push_back(1);
   a.push_back(5);
   a.push_back(5);
   a.push_back(1);
   a.push_back(1);
   a.push_back(7);
   a.push_back(7);
   a.push_back(7);
   a.push_back(1);

   cout << "test remove\n";
   a.remove(1);
   Iterator<int> p = a.begin();
   Iterator<int> q = a.end();
   while (! p.equals(q)) 
   {
      cout << "element " << p.get() << "\n";
      p.next();
   }

   cout << "test unique\n";
   a.unique();
   p = a.begin();
   q = a.end();
   while (! p.equals(q)) 
   {
      cout << "element " << p.get() << "\n";
      p.next();
   }

   cout << "test reverse\n";
   a.reverse();
   p = a.begin();
   q = a.end();
   while (! p.equals(q)) 
   {
      cout << "element " << p.get() << "\n";
      p.next();
   }

   return 0;
}
