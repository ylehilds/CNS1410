#include <iostream>
#include <string>

using namespace std;

int main()
{
   cout <<  "Please enter your income: ";
   double income;
   cin >> income;
          
   cout << "Please enter S for single or M for married: ";

   string maritalStatus;
   cin >> maritalStatus;
          
   double tax = 0;
   int cutoff15 = 0;
   int cutoff28 = 0;      

   if (maritalStatus == "S")
   {
      cutoff15 = 21450;
      cutoff28 = 30450;
   }
   else       /* status = M */
   {
      cutoff15 = 35800;
      cutoff28 = 50700;
   }

   if (income < cutoff15)
      tax = 0.15 * income; 
   else if (income < cutoff15 + cutoff28)
      tax = 0.15 * cutoff15 + (income - cutoff15) * 0.28; 
   else 
      tax = 0.15 * cutoff15 + 0.28 * cutoff28 
         + 0.31 * (income - cutoff15 - cutoff28); 

   cout << "The tax is " << tax;
    
   return 0;
}

    
