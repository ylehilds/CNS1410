#include <iostream>

using namespace std;

template<typename Iterator, typename Action>
void for_each(Iterator current, Iterator stop, Action action)
{
   while (current != stop)
   {
      action(*current);
      ++current;
   }
}

template<typename Iterator1, typename Iterator2>
void copy(Iterator1 current, Iterator1 stop, Iterator2 to)
{
   while (current != stop)
   {
      *to = *current;
      ++current;
      ++to;
   }
}

template<typename Iterator, typename Value>
void fill(Iterator current, Iterator stop, Value value)
{
   while (current != stop)
   {
      *current = value;
      ++current;
   }
}

template<typename Iterator, typename Action>
void generate(Iterator current, Iterator stop, Action action)
{
   while (current != stop)
   {
      *current = action();
      ++current;
   }
}

template<typename Iterator, typename Value>
void replace(Iterator current, Iterator stop, Value a, Value b)
{
   while (current != stop)
   {
      if (*current == a)
	 *current = b;
      ++current;
   }
}

template<typename Iterator, typename Value>
void count(Iterator current, Iterator stop, Value a)
{
   int count = 0;
   while (current != stop)
   {
      if (*current == a)
	 ++count;
      ++current;
   }
   return count;
}

template<typename Iterator, typename Value>
Iterator find(Iterator current, Iterator stop, Value a)
{
   while (current != stop)
   {
      if (*current == a)
	 return current;
      ++current;
   }
   return stop;
}

template<typename Iterator1, typename Iterator2, typename Value> 
Iterator2 remove_copy(Iterator1 current, Iterator1 stop, Iterator2 to, Value value)
{
   while (current != stop)
   {
      if (*current != value)
      {
	 *to = *current;
	 ++to;
      }
      ++current;
   }
   return to;
}

int main()
{
   return 0;
}
