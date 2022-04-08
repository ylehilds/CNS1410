#include <vector>

using namespace std;

#include "ccc_win.h"

int rand_int(int a, int b)
{
   return a + rand() % (b - a + 1);
} 

void print(vector<int> a, int n)
{
   int i;
   cwin.clear();
   for (i = 0; i < a.size(); i++)
   {
      cwin << Line(Point(i,0), Point(i, a[i]));
      cwin << Message(Point(i,a[i]), a[i]);
   }
   if (n >= 0)
   {
      cwin << Message(Point(n, a[n] * 1.1), "VV");
      string s = cwin.get_string("Hit Enter to continue");
   }
}

int binary_search(vector<int> v, int from, int to, int a)
{
   if (from > to)
      return -1;
   int mid = (from + to) / 2;
   print(v, mid);
   int diff = v[mid] - a;
   if (diff == 0) /* v[mid] == a */
      return mid;
   else if (diff < 0) /* v[mid] < a */
      return binary_search(v, mid + 1, to, a);
   else
      return binary_search(v, from, mid - 1, a);
}

int ccc_win_main()
{
   vector<int> v(20);
   int i;
   v[0] = 1;
   for (i = 1; i < v.size(); i++)
      v[i] = v[i - 1] + rand_int(1, 10);
   cwin.coord(0, v[v.size()-1] *1.1, v.size(), 0);
   print(v, -1);
   int n = cwin.get_int("Enter number to search for: ");
   int b = binary_search(v, 0, v.size() - 1, n);
   print(v, b);
   return 0;
}
