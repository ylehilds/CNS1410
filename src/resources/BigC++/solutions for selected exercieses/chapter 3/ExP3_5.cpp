#include <cmath>

using namespace std;

#include "ccc_win.h"

int ccc_win_main()
{  
   Point p1 = cwin.get_mouse( "Please click on the first point" );
   cwin << p1; /* display the first point */

   Point p2 = cwin.get_mouse( "Please click on the second point" );
   cwin << p2; /* display the second point */

   Line line(p1, p2);      /* define the Line object */

   cwin << line;

   /* calculate the line length using the Pythagorean formula */

   double length = sqrt(pow(p1.get_x() - p2.get_x(),2) +
      pow(p1.get_y() - p2.get_y(),2));

   /* line midpoint is the average of the x and y coordinates defining the
      line endpoints
   */

   Point midpoint((p1.get_x() + p2.get_x())/2, (p1.get_y() + p2.get_y())/2);
   cwin << Message(midpoint, length);

   return 0;
}
