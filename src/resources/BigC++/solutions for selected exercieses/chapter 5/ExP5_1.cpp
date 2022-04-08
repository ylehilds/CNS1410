#include <iostream>
#include <cmath>

using namespace std;

/**
   Computes the value of an investment with compound interest.
   Interest is compounded monthly
   @param balance the initial value of the investment
   @param rate the interest rate in percent
   @param years the number of years the investment is held
   @return the balance after years number of years
*/
double future_value(double balance, double rate, int years)
{  
   double b = balance * pow(1 + rate / (12 * 100), 12 * years);
   return b;
}

int main()
{  
   cout << "Please enter the interest rate in percent: ";
   double rate;
   cin >> rate;

   cout << "Please enter the initial balance: ";
   double balance;
   cin >> balance;

   cout << "After 10 years, the balance is " <<
      future_value(balance, rate, 10) << "\n";

   cout << "After 20 years, the balance is " <<
      future_value(balance, rate, 20) << "\n";

   cout << "After 30 years, the balance is " <<
      future_value(balance, rate, 30) << "\n";

   return 0;
}
