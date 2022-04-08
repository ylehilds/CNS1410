
#include <iostream>
#include <cmath> 

using namespace std; 

int main() 
{  
   const double PI = 3.141592653589793; 
  
   cout << "Enter the length of side A of the triangle: "; 
   double a; 
   cin >> a; 

   cout << "Enter the length of side B of the triangle : "; 
   double b; 
   cin >> b; 

   cout << "Enter the angle, between the two sides, in degrees : "; 
   double gamma; /* angle gamma is between sides a and b */ 
   cin >> gamma; 

   gamma = gamma * PI / 180; /* convert from degrees to radians */ 

   /* use the law of cosines to find the other length */ 

   double c = sqrt(a * a + b * b - 2 * a * b * cos(gamma)); 

   double alpha = acos((b * b + c * c - a * a) / (2 * b * c)); 

   alpha = alpha * 180.0 / PI; /* convert from radians to degrees */ 

   double beta = acos((a * a + c * c - b * b) / (2 * a * c)); 

   beta = beta * 180.0 / PI;       /* convert from radians to degrees */ 

   cout << "The third side of the triangle having sides " << a
      << " and " << b << " is " << c  << ".\n"; 

   cout << "The two other angles of the triangle are " 
      << alpha << " degrees and " 
      << beta << " degrees.\n"; 

   return 0; 
} 
  
