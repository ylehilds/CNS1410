#include <iostream>
#include <cmath>

using namespace std;

int main()
{  
   cout << "For the quadratic equation  a*x*x + b*x + c = 0, enter values for\n";
   cout << "a: ";
   double a;
   cin >> a;
   cout << "b: ";
   double b;
   cin >> b;
   cout << "c: ";
   double c;
   cin >> c;

   double discriminant = b * b - 4 * a * c;

   if (a != 0) /*  avoid division by zero */
   {  
      if (discriminant > 0)
      {  
         cout << "The solutions are " << (sqrt(discriminant) - b) / (2 * a)
            << " and " << -(b + sqrt(discriminant)) / (2 * a) << ".\n";
      }
      else
      {  
         if (discriminant == 0)
            cout << "The only solution is " << -b / (2 * a) << ".\n";
         else
            cout << "There are no real solutions.\n";     /* negative discriminant */
      }
   }
   else
      cout << "Equation is not quadratic.\n";

   return 0;
}
