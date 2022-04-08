#include <vector>

using namespace std;

#include "ccc_win.h"

int rand_int(int a, int b)
{
   return a + rand() % (b - a + 1);
} 

void swap(int& x, int& y)
{
   int temp = x;
   x = y;
   y = temp;
}

void print(vector<int> a)
{
   int i;
   cwin.clear();
   for (i = 0; i < a.size(); i++)
      cwin << Line(Point(i+1,0),Point(i+1,a[i]));
   string s = cwin.get_string("Hit Enter to continue");
}

void selection_sort(vector<int>& a)
{
   int next; /* the next position to be set to the minimum */

   for (next = 0; next < a.size() - 1; next++)
   {
     /* find the position of the minimum */
      int min_pos = next;
      int i;
      for (i = next + 1; i < a.size(); i++)
         if (a[i] < a[min_pos]) min_pos = i;

      if (min_pos != next)
      {
         swap(a[min_pos], a[next]);
         print(a);
      }
   }
}

int ccc_win_main()
{
   vector<int> v(20);
   int i;
   for (i = 0; i < v.size(); i++)
   v[i] = rand_int(1, 100);
   cwin.coord(0, 100, v.size() * 1.1, 0);
   print(v);
   selection_sort(v);
   print(v);
   return 0;
}
