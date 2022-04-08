#include <iostream>

using namespace std;

int main()
{  
   cout << "Enter today's currency exchange rate from dollars into yen: ";
   double dollar_to_yen;
   cin >> dollar_to_yen;

   double amount;
   bool more = true;
   while (more)
   {  
      cout << "Enter a U.S. dollar value: ";
      cin >> amount;

      if (cin.fail())
         more = false;
      else if (amount <= 0)
         more = false;
      else
         cout << amount << " dollars is worth " << amount * dollar_to_yen << " yen.\n";
   }      
   return 0;
}
