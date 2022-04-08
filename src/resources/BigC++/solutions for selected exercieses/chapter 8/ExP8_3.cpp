#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
   Compares two floating-point numbers.
   @param x a floating-point number
   @param y a floating-point number
   @return true if x is close to y
*/
bool approx_equal(double x, double y)
{
   const double EPSILON = 1E-6;
   if (x == 0) return fabs(y) <= EPSILON;
   if (y == 0) return fabs(x) <= EPSILON;
   return fabs(x - y) / max(fabs(x), fabs(y)) <= EPSILON;
}

/**
   Calculates the arc sine value.
   @param x a double value in the range [-1, 1]
   @return the arc sine of x
*/
double arcsin(double x)
{
/* Iteratively calculate new values of sum until the difference between
   successive values is less than 1E-06
*/
   double sum = x;
   double oldsum;
   double term = x;
   int i = 3;
   do
   {
      oldsum = sum;
      term = term * x * x * (i - 2) * (i - 2) / (i * (i - 1));
      sum = sum + term;
      i = i + 2;
   } while (!approx_equal(sum, oldsum));
   return sum;
}

int main()
{
   double a;
   for (int i = -10; i < 11; i++)
   {
      a = i / 10.0;
      cout << "arcsin (" << a << ") = " << arcsin(a) << ".\n";
   }
   return 0;
}
