#include <iostream>

using namespace std;

int main()
{
   cout <<  "Enter a month (1-12): ";
   int month;
   cin >> month;

   if (month == 4 || month == 6 || month == 9 || month == 11)
      cout << "30 days\n";         
   else if (month == 2)
      cout << "28 or 29 days\n";               
   else 
      cout << "31 days\n";         
      
   return 0;   
}
