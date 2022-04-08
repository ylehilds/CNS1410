#include <cmath>

using namespace std;

#include "ccc_win.h" 

double f(double x)
{
   return pow(x, 3) / 100 - x + 10;
}

int ccc_win_main()
{
   cwin.coord(-10, 20, 10, 0);

   double x;
   double y;

   Point p;
   Point q;

   double xmax = 10;
   double xmin = -10;

   double d = (xmax - xmin) / 100;

   x = xmin;
   y = f(x);

   p = Point(x, y);

   for (int i = 0; i < 100; i++)
   {
      x = x + d;
      y = f(x);

      q = Point(x, y);

      cwin << Line(p, q);
      p = q;
   }

   return 0;
}
