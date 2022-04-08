#include "ccc_win.h"

class Rectangle
{
public:
   Rectangle();
   Rectangle(Point corner1, Point corner2);
   void plot() const;
   void move(double dx, double dy);

private:
   Point corner1;
   Point corner2;
};

Rectangle::Rectangle(Point p1, Point p2)
{
   corner1 = p1;
   corner2 = p2;
}

void Rectangle::plot() const
{
   Point corner3 = Point(corner1.get_x(), corner2.get_y());
   Point corner4 = Point(corner2.get_x(), corner1.get_y());

   Line l1 = Line(corner1, corner3);
   Line l2 = Line(corner1, corner4);
   Line l3 = Line(corner2, corner3);
   Line l4 = Line(corner2, corner4);

   cwin << l1 << l2 << l3 << l4;
}

void Rectangle::move( double dx, double dy )
{
   corner1.move(dx, dy);
   corner2.move(dx, dy);
}

int ccc_win_main()
{
   Rectangle r1 = Rectangle(Point(3, 3), Point(4, 6));

   r1.plot();      /* show the new Rectangle */

   r1.move(-2, -3);  /* move the Rectangle */

   r1.plot();      /* show the Rectangle again once it has moved */

   return 0;
}
