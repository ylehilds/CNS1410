#include <cmath>

using namespace std;

#include "ccc_win.h"

int ccc_win_main()
{  
   /* prompt for the center of the circle */

   Point center = cwin.get_mouse( "Please click on a circle center point" );
   cwin << center; /* display the center point */

   Point boundary = cwin.get_mouse( "Please click on a circle boundary point" );
   cwin << boundary; /* display the boundary point */

   double center_x = center.get_x(); /* extract the x,y coordinates of the center point */
   double center_y = center.get_y();

   double boundary_x = boundary.get_x(); /* extract the x,y coordinates of the boundary point */
   double boundary_y = boundary.get_y();

   /* calculate the circle radius using the distance formula */

   double radius = sqrt(pow(center_x - boundary_x, 2) +
           pow(center_y - boundary_y, 2));

   Circle c(center, radius); /* define the new circle */

   cwin << c; /* display the circle */

   return 0;
}
