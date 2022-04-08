#include <iostream>

using namespace std;

/**
   Determines if a year is a leap year.
   @param year integer
   @return true if year is a leap year; false otherwise
*/
bool leap_year(int year)
{
   if (year % 4 == 0)
   {
      if (year < 1582)
         return true;
      else if (year % 400 == 0)
         return true;
      else if (year % 100 == 0)
         return false;
      else
         return true;
   }
   else
      return false;
}

int main()
{
   cout << "Enter a year: ";
   int year;
   cin >> year;

   cout << "The year " << year << " is";

   if (leap_year(year))
      cout << " ";
   else
      cout << "not ";

   cout << "a leap year.\n";

   return 0;
}
