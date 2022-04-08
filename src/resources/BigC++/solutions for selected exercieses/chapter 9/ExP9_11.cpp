#include <vector>

using namespace std;

#include "ccc_win.h"

const double PI = 3.141592653589793;

class Polygon
{
public:
   Polygon();
   void add_point(Point p);
   void plot() const;
private:
   vector<Point> corners;
};

Polygon::Polygon()
{
}

void Polygon::add_point(Point p)
{
   corners.push_back(p);
}

void Polygon::plot() const
{
   int i;
   int n = corners.size();
   for (i = 0; i < n; i++)
      cwin << Line(corners[i], corners[(i + 1) % n]);
}


int ccc_win_main()
{
   Polygon rectangle;
   rectangle.add_point(Point(1, 1));
   rectangle.add_point(Point(1, 4));
   rectangle.add_point(Point(2, 4));
   rectangle.add_point(Point(2, 1));
   rectangle.plot();

   Polygon hexagon;
   int i;
   int num_sides = 6;
   for (i = 0; i < num_sides; i++)
      hexagon.add_point(Point(cos(2 * PI * i / num_sides),
         sin(2 * PI * i / num_sides)));
   hexagon.plot();

   return 0;
}


