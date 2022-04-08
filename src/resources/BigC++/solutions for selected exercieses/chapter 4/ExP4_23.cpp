#include "ccc_win.h"

int ccc_win_main()
{  
   int num_bars = cwin.get_int("Enter number of bars: ");
   cwin.coord(0, 100, num_bars, 0);

   Point start = Point(0, 0);

   int i = 1; 
   while (i <= num_bars)
   {  
      double value = cwin.get_double("Enter value:  ");

      Point p2 = start;
      p2.move(0, value);
      Point p3 = start;
      p3.move(1, 0);

      Line l1 = Line(start, p2);
      cwin << l1;
      l1.move(1,0);
      cwin << l1;

      Line l2 = Line(start, p3);
      cwin << l2;
      l2.move(0, value);
      cwin << l2;

      start.move(1, 0);
      i++;
   }

   return 0;
}
