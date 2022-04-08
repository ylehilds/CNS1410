#include <iostream>

using namespace std;
int main()
{
   double count = 0;
   double sum = 0;
   double max;
   double min;
   double value;
   bool more;

   more = true;

   while (more)
   {
      cout << "Enter a value: ";
      cin >> value;
      if (cin.fail())
         more = false;
      else
      {
         count++;
         sum = sum + value;
         if (count == 1)        /* first value is placed into max and min */
         {
            max = value;
            min = value;
         }
         else
         {
            if (value > max)   /* did we find a bigger value than max */
               max = value;
            if (value < min)   /* did we find a smaller value than min */
               min = value;
         }
      }
   } while (more);

   if (count > 0)
   {
      double average = sum / count;
      cout << "The maximum value is " << max << ".\n";
      cout << "The minimum value is " << min << ".\n";
      cout << "The average value is " << average << ".\n";
   }

   return 0;
}
