/* This solution only works for numbers 4 or 5 digits in length */ 

#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{  
   cout << "Enter an integer: "; 
   int num; 
   cin >> num;

   int digit5 = num % 10;
   num = num / 10;

   int digit4 = num % 10;
   num = num / 10;

   int digit3 = num % 10;
   num = num / 10;

   int digit2 = num % 10;
   num = num / 10;

   int digit1 = num % 10;
   num = num / 10;

   cout << "The digits extracted from integer " << num << " are:\n";
   cout << digit1 << " " << digit2 << " " << digit3 << " " << digit4 
      << " " << digit5 << "\n"; 

   return 0;
} 
  
