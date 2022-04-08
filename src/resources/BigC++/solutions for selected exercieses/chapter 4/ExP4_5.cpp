#include "ccc_win.h" 

int ccc_win_main()
{  
   Point a = cwin.get_mouse("Please click on the first point");
   cwin << a;
   Point b = cwin.get_mouse("Please click on the second point");
   cwin << b;
   cwin << Line(a, b);   /* display the first line segment */

   Point c = cwin.get_mouse("Please click on the third point");
   cwin << c;
   Point d = cwin.get_mouse("Please click on the fourth point");
   cwin << d;
   cwin << Line(c, d);   /* display the second line segment */

   /* Calculate the t value for the point of intersection expressed as
      ta + (1-t)b      -- a little bit of algebra work here   
   */

   double t = ((b.get_x() * (c.get_y() - d.get_y()) 
      + c.get_x() * (d.get_y() - b.get_y())
      - d.get_x() * (c.get_y() - b.get_y()))
      / ((a.get_x() - b.get_x()) * (d.get_y() - c.get_y())
      + (c.get_x() - d.get_x()) * (a.get_y() - b.get_y())));
                             

   if (t > 0)
      if (t < 1)    /* the intersection point is on a line */
      {  
         double int_x = a.get_x() * t + (1 - t) * b.get_x();
         double int_y = a.get_y() * t + (1 - t) * b.get_y();

         cwin << Point(int_x, int_y);                
      }
   return 0;
}

