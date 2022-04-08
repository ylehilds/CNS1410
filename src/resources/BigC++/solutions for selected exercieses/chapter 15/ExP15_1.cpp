#include <iostream>
#include <vector>

using namespace std;

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
      /* find the position of the maximum element */
      int max_pos = next;
      int i;
      for (i = next + 1; i < a.size(); i++)
         if (a[i] > a[max_pos]) max_pos = i;

      if (max_pos != next)
         swap(a[max_pos], a[next]);
   }
}

void print(vector<int> a)
{
   int i;
   for (i = 0; i < a.size(); i++)
       cout << a[i] << " ";
   cout << "\n";
}

int main()
{
   vector<int> v(20);
   int i;
   for (i = 0; i < v.size(); i++)
   v[i] = rand_int(1, 100);
   print(v);
   selection_sort(v);
   print(v);
   return 0;
}
