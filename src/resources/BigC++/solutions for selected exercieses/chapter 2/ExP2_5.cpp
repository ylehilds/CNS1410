#include <iostream> 

using namespace std; 

int main() 
{  
   const double PI = 3.141592653589793; 
  
   cout << "Please enter a radius value: "; 
   double radius; 
   cin >> radius; 

   double area = PI * radius * radius; 

   double circumference = 2 * PI * radius; 

   double volume = (4.0 / 3.0) * PI * radius * radius * radius; 

   double surface_area = 4 * PI * radius * radius; 

   cout << "The area of a circle with radius " << radius 
      << " is " << area << ".\n"; 
   cout << "The circumference of a circle with radius " << radius 
      << " is " << circumference << ".\n"; 
   cout << "The volume of a sphere with radius " << radius 
      << " is " << volume << ".\n"; 
   cout << "The surface area of a sphere with radius " << radius 
      << " is " << surface_area << ".\n"; 

   return 0; 
} 
  
