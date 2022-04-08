#include <vector>

using namespace std;

#include "ccc_win.h"

class Polygon
{
public:
   Polygon();
   void add_point(Point p);
   void plot() const;
   void move(double dx, double dy);
   void scale(double factor);

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

void Polygon::move(double dx, double dy)
{
   for (int i = 0; i < corners.size(); i++)
      corners[i].move(dx, dy);
}



void Polygon::scale(double factor)
{
   for (int i = 0; i < corners.size(); i++)
      corners[i] = Point(corners[i].get_x() * factor,
         corners[i].get_y() * factor);
}

int ccc_win_main()
{
   Polygon rectangle;
   rectangle.add_point(Point(1, 1));
   rectangle.add_point(Point(1, 4));
   rectangle.add_point(Point(2, 4));
   rectangle.add_point(Point(2, 1));
   rectangle.plot();
   rectangle.move(-2,0.5);
   rectangle.plot();
   rectangle.scale(2);
   rectangle.plot();

   return 0;
}


