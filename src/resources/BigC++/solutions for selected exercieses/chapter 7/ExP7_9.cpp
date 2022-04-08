#include <iostream>
#include <cmath>

using namespace std;

const double EPSILON = 1E-14;

int main()
{
   cout << "Enter a value: ";
   double a;
   cin >> a;

   cout << "Enter the root to find for this value: ";
   int n;
   cin >> n;

   if (n < 2)
   {
      cout << "The root must be greater than 1.\n";
      return 0;
   }

   double xold;
   double xnew = 1;    /* initial guess */

   do
   {
      xold = xnew;
      xnew = xold - (pow(xold, n) - a) / (n * pow(xold, n - 1));
   }
   while (fabs(xold - xnew) > EPSILON);
      
   cout << "The " << n << "th root of " << a << " is " << xnew << ".\n";

   return 0;
}
