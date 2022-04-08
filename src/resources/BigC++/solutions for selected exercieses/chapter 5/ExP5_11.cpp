#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/**
   Prompts for a floating point number.
   @param prompt string object
   @return doubleing point number
*/
double get_double(string prompt)
{
   cout << prompt << " ";
   double value;
   cin >> value;
   if (cin.fail())
   {
      cout << "Input error.\n";
      exit(1);
   }

   return value;
}

int main()
{
   double salary;
   salary = get_double("Please enter your salary:");
   cout << "Your salary is " << salary << "\n";
   return 0;
}
