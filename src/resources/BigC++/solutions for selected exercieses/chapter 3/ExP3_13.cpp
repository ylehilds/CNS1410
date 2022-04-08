#include "ccc_win.h"

int ccc_win_main()
{  
   double x = 0; /* the coordinates of the first ring center */
   double y = 0;
   const double DISTANCE_BETWEEN_RING_CENTERS = 4;  /* arbitrary choice here                                                                                        but must be greater than
                                                                   the ring radius */
   const double RING_RADIUS = 2.5;

   Circle loop(Point(x, y), RING_RADIUS);
   cwin << loop; /* first ring (top middle) */

   loop.move(x - DISTANCE_BETWEEN_RING_CENTERS, 0); /* top left ring */
   cwin << loop;

   loop.move(x + 2 * DISTANCE_BETWEEN_RING_CENTERS, 0); /* top right ring */
   cwin << loop;

   /* The placement of the ring centers form the endpoints of equilateral
      triangles.  The distance between the apex of an equilateral
      triangle and the base is given as sqrt(3) * base / 2  
   */

   loop.move(x - (DISTANCE_BETWEEN_RING_CENTERS / 2.0),
           y - DISTANCE_BETWEEN_RING_CENTERS * sqrt(3.0) / 2.0);
                                                                                                                                           /* bottom right ring */
   cwin << loop;

   loop.move(x - DISTANCE_BETWEEN_RING_CENTERS, 0);                /* bottom left ring */
   cwin << loop;

   return 0;
}

