#include "ccc_win.h"

int ccc_win_main()
{  
   const double PI = 3.141592653589793;
   
   double data1 = cwin.get_double("Enter the first value: ");
   double data2 = cwin.get_double("Enter the second value: ");
   double data3 = cwin.get_double("Enter the third value: ");
   double data4 = cwin.get_double("Enter the fourth value: ");

   double total = data1 + data2 + data3 + data4;

   double theta_1 = 2 * PI * data1 / total; 

   /* express the angles as
      proportion of the 2 Pi
      radians within a circle 
   */

   double theta_2 = 2 * PI * data2 / total;
   double theta_3 = 2 * PI * data3 / total;

   const double RADIUS = 4;
   const Point ORIGIN = Point(0,0);

   cwin << Circle(ORIGIN, RADIUS); /* draw pie outline */

   double x = RADIUS * cos(theta_1); /* use polar representation */
   double y = RADIUS * sin(theta_1);

   cwin << Line(ORIGIN, Point(x,y)); /* first pie wedge */

   x = RADIUS * cos(theta_1 + theta_2);
   y = RADIUS * sin(theta_1 + theta_2);

   cwin << Line(ORIGIN, Point(x,y)); /* second pie wedge */

   x = RADIUS * cos(theta_1 + theta_2 + theta_3);
   y = RADIUS * sin(theta_1 + theta_2 + theta_3);

   cwin << Line(ORIGIN, Point(x,y)); /* third pie wedge */

   x = RADIUS * cos(0);
   y = RADIUS * sin(0);

   cwin << Line(ORIGIN, Point(x,y)); /* fourth pie wedge */

   return 0;
}
