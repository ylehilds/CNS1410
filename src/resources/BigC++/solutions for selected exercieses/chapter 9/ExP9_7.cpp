#include <iostream>
#include <vector>

using namespace std;

bool equals(vector<int> a, vector<int> b)
{
   if (a.size() != b.size()) return false;

   int i;
   for (i = 0; i < a.size(); i++)
      if (a[i] != b[i]) return false;
   return true;
}

int main()
{
   vector<int>  a(4);
   vector<int>  b(4);
   int i;

   for (i = 0; i < a.size(); i++) /* initialize vector a to some values */
      a[i] = (i+1) * (i+1);

   for (i = 0; i < b.size(); i++)  /* initialize vector b to some values */
      b[i] = (i+1) * (i+1);

   cout << "Vectors a and b are ";
   if (!equals(a,b)) cout << "not ";
   cout << "equal.\n";

   return 0;
}



