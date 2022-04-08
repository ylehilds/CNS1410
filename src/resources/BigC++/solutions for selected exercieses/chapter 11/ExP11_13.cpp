#include <vector>

using namespace std;

#include "ccc_win.h"

class Shape
{
public:
   Shape();
   virtual void plot() const;
   virtual Shape* make_shape(Point p) const;
};

Shape::Shape()
{
}

void Shape::plot() const
{
}

Shape* Shape::make_shape(Point p) const
{
   return NULL;
}

class Rectangle : public Shape
{
public:
   Rectangle();
   Rectangle(Point p, double l, double w);
   virtual Shape* make_shape(Point p) const;
   virtual void plot() const;
private:
   Point corner;
   double width;
   double height;
};

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Point p, double w, double h)
{
   corner = p;
   width = w;
   height = h;
}

Shape* Rectangle::make_shape(Point p) const
{
   return new Rectangle(p, 3, 2);
}

void Rectangle::plot() const
{
   Point p2 = corner;
   p2.move(0, height);
   Point p3 = corner;
   p3.move(width, 0);
   Line l1(corner, p2);
   Line l2(corner, p3);
   cwin << l1 << l2;
   l1.move(width, 0);
   l2.move(0, height);
   cwin << l1 << l2;
}

class Square : public Rectangle
{
public:
  Square();
  Square(Point p, double l);
  Shape* make_shape(Point p) const;
};

Square::Square()
{
}

Square::Square(Point p, double l) : Rectangle(p, l, l)
{ 
}

Shape* Square::make_shape(Point p) const
{
   return new Square(p, 2);
}

class Triangle : public Shape
{
public:
   Triangle();
   Triangle(Point p1, Point p2, Point p3);
   virtual Shape* make_shape(Point p) const;
   virtual void plot() const;
private:
   Point corner1;
   Point corner2;
   Point corner3;
};

Triangle::Triangle()
{
}

Triangle::Triangle(Point p1, Point p2, Point p3) 
{
   corner1 = p1;
   corner2 = p2;
   corner3 = p3;
}

Shape* Triangle::make_shape(Point p) const
{
   Point q = p;
   q.move(-1, 2);
   Point r = p;
   r.move(1, 2);
   return new Triangle(p, q, r);
}

void Triangle::plot() const
{
   cwin << Line(corner1, corner2);
   cwin << Line(corner2, corner3);
   cwin << Line(corner3, corner1);
}

class CircleShape : public Shape
{
public:
   CircleShape();
   CircleShape(Point p, double r);
   virtual Shape* make_shape(Point p) const;
   virtual void plot() const;
private:
   Point center;
   double radius;
};

CircleShape::CircleShape()
{
}

CircleShape::CircleShape(Point p, double r)
{
   center = p;
   radius = r;
}

Shape* CircleShape::make_shape(Point p) const
{
   return new CircleShape(p, 1);
}

void CircleShape::plot() const
{
   cwin << Circle(center, radius);
}

int ccc_win_main()
{
   cwin.coord(0, -1, 10, 9);
   vector<Shape*> icons;
   icons.push_back(new Rectangle(Point(0.1, 0.3), 0.8, 0.4));
   icons.push_back(new Square(Point(0.2, 1.2), 0.6));
   icons.push_back(new Triangle(Point(0.5, 2.3), Point(0.2, 2.7), Point(0.8, 2.7)));
   icons.push_back(new CircleShape(Point(0.5, 3.5), 0.4));

   int i;
   for (i = 0; i < icons.size(); i++)
   {
      Square(Point(0, i), 1).plot();
      icons[i]->plot();
   }
   Square(Point(0, i), 1).plot();
   cwin << Message(Point(0, i), "Quit");

   bool more = true;
   while (more)
   {
      Point p = cwin.get_mouse("Select shape");
      if (0 <= p.get_x() && p.get_x() <= 1
         && 0 <= p.get_y() && p.get_y() < icons.size() + 1)
      {
         int item = static_cast<int>(p.get_y());
         if (item == icons.size()) more = false;
         else 
         {
            p = cwin.get_mouse("Select location");
            icons[item]->make_shape(p)->plot();
         }
      }
   }
   return 0;
}
