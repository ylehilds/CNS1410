#include <iostream>

using namespace std;

class Set {
public:
   Set();
   void add(int n);
   bool contains(int n) const;
   int get_size() const;
   // the big three functions
   Set(const Set& right);
   Set& operator= (const Set& right);
   ~Set();
private:
   void free();
   void copy(const Set& right);
   int* elements;
   int size;
};

Set::Set()
{
   elements = 0;
   size = 0;
}

void Set::free()
{
   delete elements;
}

void Set::copy(const Set& right)
{
   size = right.get_size();
   elements = new int[size];
   for (int i = 0; i < size; i++)
      elements[i] = right.elements[i];
}

Set::Set(const Set& right)
{
  copy(right);
}

Set& Set::operator=(const Set& right)
{
   if (this != &right)
   {
      free();
      copy(right);
   }
   return *this;
}

Set::~Set()
{
   free();
}

void Set::add(int n)
{
   if (contains(n)) return;
   int* newelements = new int[size+1];
   for (int i = 0; i < size; i++)
      newelements[i] = elements[i];
   newelements[size] = n;
   delete elements;
   elements = newelements;
   size++;
}

bool Set::contains(int n) const
{
   for (int i = 0; i < size; i++)
      if (elements[i] == n)
	 return true;
   return false;
}

int Set::get_size() const
{
   return size;
}

void displaySet(const Set& a)
{
   cout << "set size is " << a.get_size() << " values[ ";
   for (int i = 0; i < 10; i++)
      if (a.contains(i))
	 cout << i << " ";
   cout << "]\n" ;
}

void f(Set x)
{
   cout << "in function f\n";
   displaySet(x);
}

int main()
{
   Set a;
   displaySet(a);
   a.add(3); a.add(7); displaySet(a);
   a.add(5); a.add(3); displaySet(a);
   Set b;
   b = a; displaySet(b);
   f(b);
   return 0;
}
