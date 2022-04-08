#include <cmath>

using namespace std;

#include "ccc_win.h"

/**
   Calculates the distance between two Point objects.
   @param p Point object
   @param q Point object
   @return distance between the two Points
*/
double dist(Point p, Point q)
{
   double dx = p.get_x() - q.get_x();
   double dy = p.get_y() - q.get_y();
   return sqrt(dx * dx + dy * dy);
}

int ccc_win_main()
{
   Point first = cwin.get_mouse("Click a spot for the first point");
   cwin << first;

   Point second = cwin.get_mouse("Click a spot for the second point");
   cwin << second;

   double d = dist(first, second);

   cwin << Message(second, d);

   return 0;
}

