#include <vector>
#include <iostream>

using namespace std;

template<typename Itr, typename T>
Itr find(Itr start, Itr stop, T& value)
{
   while (start != stop)
   {
      if (*start == value)
	 return start;
      start++;
   }
   return stop;
}

int main() {
   vector<int> a;
   a.push_back(1);
   a.push_back(4);
   a.push_back(7);

   vector<int>::iterator p = find(a.begin(), a.end(), 4);
   if (p != a.end())
      cout << "found " << *p << "\n";
   else
      cout << "not found\n";
}
