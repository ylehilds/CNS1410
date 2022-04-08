#include <iostream>
#include <vector>

using namespace std;

#include "ccc_time.h"

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
         swap(a[min_pos], a[next]);
   }
}

int main()
{
   cout << "Enter the minimum vector size: ";
   int n_min;
   cin >> n_min;
   cout << "Enter the maximum vector size: ";
   int n_max;
   cin >> n_max;
   cout << "Enter the number of measurements to take: ";
   int num_measure;
   cin >> num_measure;

   if (num_measure == 1) num_measure = 2;

   double elapsed; /* number of elapsed seconds within a test */
   double incr = (n_max - n_min) / (num_measure - 1);
   if (incr < 1) incr = 1;

   for (int tests = n_min; tests <= n_max; tests = tests + incr)
   {
      vector<int> v(tests);
      int i;
      for (i = 0; i < v.size(); i++)
         v[i] = rand_int(1, 100);

      Time before;
      selection_sort(v);
      Time after;

      elapsed = after.seconds_from(before);
      cout << " | " << tests << " | " << elapsed << " | " << "\n";
   }

   return 0;
}
