#include "ccc_win.h" 

int ccc_win_main()
{  
   /* first draw a square */
   cwin << Line(Point(0,0), Point(1,0))
      << Line(Point(1,0), Point(1,1))
      << Line(Point(1,1), Point(0,1))
      << Line(Point(0,1), Point(0,0));

   Point a = cwin.get_mouse("Please click on a point");

   /* Now determine if the user clicked inside our square.  Check if the
      x and y coordinates of the point lie within the square. */

   if (a.get_x() < 0)
      cwin << Message(Point(2,2), "You missed.");
   else if (a.get_x() > 1)
      cwin << Message(Point(2,2), "You missed.");
   else if (a.get_y() < 0)
      cwin << Message(Point(2,2), "You missed.");
   else if (a.get_y() > 1)
      cwin << Message(Point(2,2), "You missed.");
   else
      cwin << Message(Point(2,2), "Congratulations.");

   return 0;
}
