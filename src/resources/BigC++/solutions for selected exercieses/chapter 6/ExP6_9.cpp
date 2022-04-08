#include "ccc_win.h"

class Triangle
{  
public:
   Triangle();
   Triangle(Point corner1, Point corner2, Point corner3);
   void plot() const;
   void move( double dx, double dy );

private:
   Point corner1;
   Point corner2;
   Point corner3;
};

Triangle::Triangle( Point p1, Point p2, Point p3 )
{
   corner1 = p1;
   corner2 = p2;
   corner3 = p3;
}

void Triangle::plot() const
{
   Line l1 = Line(corner1, corner2);
   Line l2 = Line(corner1, corner3);
   Line l3 = Line(corner2, corner3);

   cwin << l1 << l2 << l3;
}

void Triangle::move(double dx, double dy)
{
   corner1.move(dx, dy);
   corner2.move(dx, dy);
   corner3.move(dx, dy);
}

int ccc_win_main()
{
   Point p1 = Point(0,0);
   Point p2 = Point(-5, -5);
   Point p3 = Point(-2, 4);

   cwin << p1 << p2 << p3;

   Triangle r1 = Triangle(p1, p2, p3);

   r1.plot();

   r1.move( -2, -3);

   r1.plot();

   return 0;
}
