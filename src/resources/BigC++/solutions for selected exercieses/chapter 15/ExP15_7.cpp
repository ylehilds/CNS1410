#include <iostream>
#include <vector>

using namespace std;

int rand_int(int a, int b)
{
   return a + rand() % (b - a + 1);
} 

bool binary_search(vector<int> v, int from, int to, int a, int& m)
{
   if (from > to)
   /* cannot find value a in this vector */
   {
      m = from; /* return index of next highest value */
      return false;
   }
   int mid = (from + to) / 2;
   int diff = v[mid] - a;
   if (diff == 0) /* v[mid] == a */
   {
      m = mid;
      return true;
   }
   else if (diff < 0) /* v[mid] < a */
      return binary_search(v, mid + 1, to, a, m);
   else
      return binary_search(v, from, mid - 1, a, m);
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
   v[0] = 1;
   for (i = 1; i < v.size(); i++)
      v[i] = v[i - 1] + rand_int(1, 10);

   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;
   int m;
   bool j = binary_search(v, 0, v.size() - 1, n, m);
   if (j == true)
      cout << "Found in position " << m << "\n";
   else
      cout << "Not found. Should go before position " << m << "\n";
   return 0;
}
