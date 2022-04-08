#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<double>& a)
{
   for (int i = 0; i < a.size() / 2; i++)
   {
      double temp = a[i];
      a[i] = a[a.size() - i - 1];
      a[a.size() - i - 1] = temp;
   }
}

int main()
{
   vector<double> a(9);

   a[0] = 1;
   a[1] = 4;
   a[2] = 9;
   a[3] = 16;
   a[4] = 9;
   a[5] = 7;
   a[6] = 4;
   a[7] = 9;
   a[8] = 11;

   reverse(a);

   cout << "The reverse of the vector is ";
   for (int i = 0; i < a.size(); i++)
      cout << a[i] << " ";
   cout << "\n";

   return 0;
}

