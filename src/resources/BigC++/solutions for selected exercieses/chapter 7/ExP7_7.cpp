#include <iostream>

using namespace std;

int main()
{
   cout << "Enter an integer: ";
   int num;
   cin >> num;

   int i = 2;

   while (i <= num)
   {
      if ( num % i == 0 )
      {
         cout << i << "\n";
         num = num / i;
      }
      else
         i++;
   }

   return 0;
}
