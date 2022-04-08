#include <iostream>
#include <list>

using namespace std;

class SetIterator;

class Set
{  
public:
   Set();
   bool is_element(int x);
   void insert(int x);
   void erase(int x);
   void print();
   SetIterator begin();
   SetIterator end();
private:
   list<int> items;
};

class SetIterator
{
public:
   SetIterator();
   SetIterator(list<int>::iterator p);
   void next();
   int get();
   bool equals(SetIterator other);
private:
   list<int>::iterator pos;
};

Set::Set()
{  
}

bool Set::is_element(int x)
{
   list<int>::iterator pos;
   for (pos = items.begin(); pos != items.end(); pos++)
      if (*pos == x) return true;
   return false;
}

void Set::insert(int x)
{
   if (!is_element(x))
      items.push_back(x);
}

void Set::erase(int x)
{
   list<int>::iterator pos;
   for (pos = items.begin(); pos != items.end(); pos++)
      if (*pos == x) 
      {
         items.erase(pos);
         return;
      }
}

void Set::print()
{
   SetIterator pos;
   cout << "{ ";
   for (pos = items.begin(); !pos.equals(items.end()); pos.next())
      cout << pos.get() << " ";
   cout << "}\n";
}

SetIterator Set::begin()
{
   return SetIterator(items.begin());
}

SetIterator Set::end()
{
   return SetIterator(items.end());
}

SetIterator::SetIterator()
{
}

SetIterator::SetIterator(list<int>::iterator p)
{
   pos = p;
}

void SetIterator::next()
{
   pos++;
}

int SetIterator::get()
{
   return *pos;
}

bool SetIterator::equals(SetIterator other)
{
   return pos == other.pos;
}

int main()
{
   Set s;
   s.insert(3);
   s.insert(4);
   s.insert(5);
   s.insert(3);
   s.erase(2);
   s.erase(4);

   s.print();

   for (int i = 0; i < 6; i++)
      if (s.is_element(i))
         cout << "found element " << i << "\n";
      else
         cout << "didn't find element " << i << "\n";

   return 0;
}

