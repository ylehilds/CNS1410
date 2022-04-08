#include <iostream>

using namespace std;
double exponential( double x )
{
   double summand = 1;
   int n = 1;
   double sum = 1;

   do
   {
      summand = summand * x / n;
      sum = sum + summand;
      n++;
   }
   while (summand > 0.00001);

   return sum;
}


int main()
{
   cout << "Enter the power: ";
   double power;
   cin >> power;

   cout << "e to the " << power << "th power is " 
      << exponential(power) << "\n";

   return 0;
}
