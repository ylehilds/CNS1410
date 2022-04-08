#include "ccc_win.h"

int ccc_win_main()
{  
   Point a = cwin.get_mouse("Click on a point to be an endpoint of the first line segment.");
   cwin << a;
   Point b = cwin.get_mouse("Click on the other endpoint of the first line segment.");
   cwin << b;
   Line l1 = Line(a, b);
   cwin << l1;

   Point c = cwin.get_mouse("Click on a point to be an endpoint of the second line segment.");
   cwin << c;
   Point d = cwin.get_mouse("Click on the other endpoint of the second line segment.");
   cwin << d;

   Line l2 = Line(c, d);
   cwin << l2;      

   /* Solve the system of equations for t */

   double t = ((-( d.get_y() - b.get_y() ) / -( d.get_y() - c.get_y() ) 
      - ( d.get_x() - b.get_x() ) /  ( d.get_x() - c.get_x() ))
      /
      ( ( a.get_x() - b.get_x() ) / -( d.get_x() - c.get_x() ) 
      + ( a.get_y() - b.get_y() ) /  ( d.get_y() - c.get_y() )));

   /* Compute and display the point of intersection (if any) */

   Point intersection = Point( t * a.get_x() + (1-t) * b.get_x(),  
      t * a.get_y() + (1-t) * b.get_y() );

   cwin << intersection;
   return 0;
}
