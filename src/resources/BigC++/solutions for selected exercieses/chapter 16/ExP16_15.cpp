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
   cout << "Enter an integer, the maximum prime to compute using the sieve of Eratosthenes: ";
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++)
      s.insert(i);

   s.erase(1);    // 1 is not a prime number

   int i;
   int j;
   for (i = 2; i * i <= n; i++)
      for (j = 2; i * j <= n; j++)
         s.erase(i * j); 

   s.print();

   return 0;
}
