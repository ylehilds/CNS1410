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


   int sgn_b; /* this is used in the modified formula */

   if (b >= 0) sgn_b = 1;
   else sgn_b = -1;
   if (a != 0) /* avoid division by zero */
   {  
      double discriminant = b * b - 4 * a * c;
      if (discriminant > 0)
      {  
         double q = -(b + sgn_b * sqrt(discriminant)) / 2; 
         double x1 = q / a;
         double x2 = c / q;

         cout << "The solutions are " << x1 
            << " and " << x2 << ".\n";
      }
      else
      {  
         if (discriminant == 0)
            cout << "The only solution is " << -b / (2 * a) << ".\n";
        else
            cout << "There are no solutions.\n"; /* negative discriminant */
      }
   }
   else
      cout << "Equation is not quadratic.\n";

   return 0;
}
