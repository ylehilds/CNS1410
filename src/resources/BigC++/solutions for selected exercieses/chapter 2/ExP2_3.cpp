#include <iostream>
#include <cstdlib>

using namespace std; 

int main() 
{  
   cout << "Please enter the first integer: "; 
   int a; 
   cin >> a; 

   cout << "Please enter the second integer: "; 
   int b; 
   cin >> b; 

   cout << "The sum of " << a << " and " << b << " is "; 
   cout << (a + b) << ".\n"; 

   cout << "The difference of " << a << " and " << b << " is "; 
   cout << (a - b) << ".\n"; 

   cout << "The product of " << a << " and " << b << " is "; 
   cout << (a * b) << ".\n"; 

   cout << "The average of " << a << " and " << b << " is "; 
   cout << (a + b)/2.0 << ".\n"; 

   cout << "The distance between " << a << " and " << b << " is "; 
   cout << abs(a - b) << ".\n"; 

   cout << "The maximum of " << a << " and " << b << " is "; 
   cout << ( abs(a - b) + a + b ) / 2 << ".\n"; 

   cout << "The minimum of " << a << " and " << b << " is "; 
   cout << (a + b - abs( a - b ) ) / 2 << ".\n"; 

   return 0; 
} 
  
