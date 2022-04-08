#include <iostream>
#include <vector>

using namespace std;

int rand_int(int a, int b)
{
   return a + rand() % (b - a + 1);
} 

void merge(vector<int>& a, int from, int mid, int to)
{
   int n = to - from + 1; /* size of the range to be merged */
   /* merge both halves into a temporary vector b */
   vector<int> b(n);

   int i1 = from;
   /* next element to consider in the first half */
   int i2 = mid + 1;
   /* next element to consider in the second half */
   int j = 0; /* next open position in b */

   /* as long as neither i1 nor i2 past the end, move the smaller
      element into b
   */
   while (i1 <= mid && i2 <= to)
   {
      if (a[i1] < a[i2])
      {
         b[j] = a[i1];
         i1++;
      }
      else
      {
         b[j] = a[i2];
         i2++;
      }
      j++;
   }

   /* note that only one of the two while loops below is executed
   */

   /* copy any remaining entries of the first half */
   while (i1 <= mid)
   {
      b[j] = a[i1];
      i1++;
      j++;
   }
   /* copy any remaining entries of the second half */
   while (i2 <= to)
   {
      b[j] = a[i2];
      i2++;
      j++;
   }

   /* copy back from the temporary vector */
   for (j = 0; j < n; j++)
      a[from + j] = b[j];
}

void merge_sort(vector<int>& a, int from, int to)
{
   int length = a.size();

   int j = 2;
   /*
      Example: Assume there are 16 elements to sort. The first 8 merge
      calls would sort adjacent regions of size 1:

      merge(a, 0, 0, 1);
      merge(a, 2, 2, 3);
      merge(a, 4, 4, 5);
      merge(a, 6, 6, 7);
      merge(a, 8, 8, 9);
      merge(a,10,10,11);
      merge(a,12,12,13);
      merge(a,14,14,15);

      The next four merge calls would sort adjacent regions of size 2:
      merge(a, 0, 1, 3);
      merge(a, 4, 5, 7);
      merge(a, 8, 9,11);
      merge(a,12,13,15);

      The next two merge calls would sort adjacent regions of size 4:
      merge(a, 0, 3, 7);
      merge(a, 8,11,15);

      The last merge call would sort adjacent regions of size 8:
      merge(a, 0, 7,15);
   */

   while (j <= length)
   {
      for (int i = 0; i < length; i+=j)
         merge(a, i, i + j/2 - 1, i + j - 1);
      j = j * 2;
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
   vector<int> v(16);
   int i;
   for (i = 0; i < v.size(); i++)
      v[i] = rand_int(1, 100);
   print(v);
   merge_sort(v, 0, v.size() - 1);
   print(v);
   return 0;
}
    
