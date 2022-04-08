#include "ccc_win.h"

const double STOP_BOX_LEFT = 6;
const double STOP_BOX_RIGHT = 8;
const double STOP_BOX_BOTTOM = -9;
const double STOP_BOX_TOP = -8;

int ccc_win_main()
{  
   double sum_x = 0;
   double sum_y = 0;
   int count = 0;
   double sum_squares_x = 0;
   double sum_xy = 0;
   double average_x = 0;
   double average_y = 0;

   /* draw stop box */
   Line l1 = Line(Point(STOP_BOX_LEFT, STOP_BOX_BOTTOM),
      Point(STOP_BOX_LEFT, STOP_BOX_TOP));
   cwin << l1;
   l1.move( STOP_BOX_RIGHT - STOP_BOX_LEFT, 0 );
   cwin << l1;
   Line l2 = Line(Point(STOP_BOX_LEFT, STOP_BOX_BOTTOM),
      Point(STOP_BOX_RIGHT, STOP_BOX_BOTTOM));
   cwin << l2;
   l2.move( 0, STOP_BOX_TOP - STOP_BOX_BOTTOM );
   cwin << l2;
   cwin << Message(Point(STOP_BOX_LEFT + 0.2, STOP_BOX_TOP - 0.2 ), "STOP");

   Point p;

   bool more = true;
   while (more)
   {  
      Point p = cwin.get_mouse("Click on a point");
      cwin << p;
      double x = p.get_x();
      double y = p.get_y();
      bool stop = true;
      if (STOP_BOX_LEFT > x) stop = false;
      if (x > STOP_BOX_RIGHT) stop = false;
      if (STOP_BOX_BOTTOM > y) stop = false;
      if (y > STOP_BOX_TOP) stop = false;
      if (stop)
      {  
         more = false;
      }
      else
      {  
         count++;
         sum_x = sum_x + x;
         sum_y = sum_y + y;

         sum_squares_x = sum_squares_x + x * x;
         sum_xy = sum_xy + x * y;
      }
   }

   if (count > 1)
   {  
      average_x = sum_x / count;
      average_y = sum_y / count;
      double slope = (sum_xy - count * average_x * average_y) /
         (sum_squares_x - count * average_x * average_x);
      double x1 = -10;
      double x2 = 10;
      double y1 = average_y + slope * (x1 - average_x);
      double y2 = average_y + slope * (x2 - average_x);

      Line l = Line(Point(x1, y1), Point(x2, y2));
      cwin << l;
   }

   return 0;
}
