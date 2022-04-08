#include <iostream>
#include <vector>

using namespace std;

double scalar_product(vector<double> a, vector<double> b)
{
   double sum = 0;
   if (a.size() == b.size())
   {
      for (int i = 0; i < a.size(); i++)
         sum = sum + a[i] * b[i];
   }
   return sum;
}

int main()
{
   vector<double> a(5);
   vector<double> b(5);
   a[0] = 1;
   a[1] = 2;
   a[2] = 3;
   a[3] = 4;
   a[4] = 5;

   b[0] = 2;
   b[1] = 1;
   b[2] = 0;
   b[3] = -1;
   b[4] = -2;

   cout << "The scalar product of the vectors is " 
     << scalar_product(a,b) << "\n";

   return 0;
}
