#include <iostream> 
#include <cmath> 
#include <iomanip> 

using namespace std; 

int main() 
{  
   const double PI = 3.141592653589793; 
   const double RAD_TO_DEG = PI / 180; 
   double angle = 0; 
  
   cout << "0  degrees: " << setw(8) << setprecision(4) << sin(angle) << " " 
        << setw(12) << cos(angle) << "\n"; 
  
   angle = 30 * RAD_TO_DEG; 
   cout << "30 degrees: " << setw(8) << sin(angle) << " " 
        << setw(12) << cos(angle) << "\n"; 

   angle = 45 * RAD_TO_DEG; 
   cout << "45 degrees: " << setw(8) << sin(angle) << " " 
        << setw(12) << cos(angle) << "\n"; 

   angle = 60 * RAD_TO_DEG; 
   cout << "60 degrees: " << setw(8) << sin(angle) << " " 
        << setw(12) << cos(angle) << "\n"; 

   angle = 90 * RAD_TO_DEG; 
   cout << "90 degrees: " << setw(8) << sin(angle) << " " 
        << setw(12) << cos(angle) << "\n"; 
  
   return 0; 
} 
  
