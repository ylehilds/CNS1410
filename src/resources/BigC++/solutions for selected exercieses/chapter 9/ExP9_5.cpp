#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
   int i = 0;
   int j = 0;
   int k = 0;
   vector<int> c(a.size() + b.size());
   while ((i < a.size()) && (j < b.size()))
   {
      c[k]   = a[i];
      c[k+1] = b[j];
      i++;
      j++;
      k = k + 2;
   }

   if (i < a.size())   /* have we more a elements to add? */
   {
      while (i < a.size())
      {
         c[k] = a[i];
         i++;
         k++;
      }
   }
   else if (j < b.size())  /* have we more b elements to add? */
   {
      while (j < b.size())
      {
         c[k] = b[j];
         j++;
         k++;
      }
   }
   return c;
}

int main()
{
   vector<int>  a(4);
   vector<int>  b(5);
   int i;

   for (i = 0; i < a.size(); i++)      /* initialize vector a to some values */
      a[i] = (i+1) * (i+1);

   b[0] = 9;
   b[1] = 7;
   b[2] = 4;
   b[3] = 9;
   b[4] = 11;

   vector<int> c = merge(a, b);

   cout << "Result of merge of a and b is ";

   for (i = 0; i < c.size(); i++)
      cout << c[i] << " ";

   cout << "\n";

   return 0;
}



