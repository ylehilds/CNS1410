#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Set 
{
public:
   class Iterator;
   void add(T v);
   void remove(T v);
   Iterator begin();
   Iterator end();
private:
   vector<T> data;
};

template<typename T>
class Set<T>::Iterator 
{
public:
   Iterator(int index, Set *s);
   T get();
   void next();
   bool equals(Iterator s);
private:
   int index;
   Set *values;
};

template<typename T>
Set<T>::Iterator::Iterator(int i, Set *s)
{
   index = i;
   values = s;
}

template<typename T>
T Set<T>::Iterator::get()
{
   return (*values).data[index];
}

template<typename T>
void Set<T>::Iterator::next()
{
   index++;
}

template<typename T>
bool Set<T>::Iterator::equals(Iterator s)
{
	return (values == s.values) && (index == s.index);
}

template<typename T>
Set<T>::Iterator Set<T>::begin()
{
   return Iterator(0, this);
}

template<typename T>
Set<T>::Iterator Set<T>::end()
{
   return Iterator(data.size(), this);
}

template<typename T>
void Set<T>::add(T v)
{
	Iterator p = begin();
	Iterator q = end();
	while (! p.equals(q)) 
	{
	   if (p.get() == v)
	      return;
	   p.next();
	}
	data.push_back(v);
}

int main()
{
   Set<int> a;
   a.add(7);
   a.add(4);
   a.add(7);
   a.add(5);
   Set<int>::Iterator p = a.begin();
   Set<int>::Iterator q = a.end();
   while (! p.equals(q)) 
   {
      cout << "value " << p.get() << "\n";
      p.next();
   }
    return 0;
}
