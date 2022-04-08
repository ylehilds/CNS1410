#include <iostream>
#include <vector>

using namespace std;

bool count(int e, vector<int> b)
{
   int count = 0;
   int i;
   for (i = 0; i < b.size(); i++)
      if (e == b[i]) count++;
   return count;
}

bool same_elements(vector<int>a, vector<int> b)
{
   int i;
   if (a.size() != b.size()) return 0;
   for (i = 0; i < a.size(); i++)
      if (count(a[i], a) != count(a[i], b))
         return false;
   return true;
}   

int main()
{
   vector<int>  a(9);
   vector<int>  b(9);

   a[0] = 1;
   a[1] = 4;
   a[2] = 9;
   a[3] = 16;
   a[4] = 9;
   a[5] = 7;
   a[6] = 4;
   a[7] = 9;
   a[8] = 11;

   b[0] = 11;
   b[1] = 1;
   b[2] = 4;
   b[3] = 9;
   b[4] = 16;
   b[5] = 9;
   b[6] = 7;
   b[7] = 4;
   b[8] = 9;

   cout << "The vectors a and b have ";

   if (!same_elements(a, b)) cout << "not ";

   cout << "the same elements.\n";

   return 0;
}

