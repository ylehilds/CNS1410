#include <vector>

using namespace std;

#include "ccc_win.h"

class Shape
{
public:
   Shape();
   virtual double area() const;
   virtual void plot() const;
};

Shape::Shape()
{
}


double Shape::area() const
{
   return 0;
}

void Shape::plot() const
{
}

class Rectangle : public Shape
{
public:
   Rectangle();
   Rectangle(Point p, double l, double w);
   virtual double area() const;
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

double Rectangle::area() const
{
  return width * height;
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
private:
};

Square::Square()
{
}

Square::Square(Point p, double l) : Rectangle(p, l, l)
{ 
}

class Triangle : public Shape
{
public:
   Triangle();
   Triangle(Point p1, Point p2, Point p3);
   virtual double area() const;
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

double Triangle::area() const
{
   double x = 0.5 * fabs(corner1.get_x() * corner2.get_y()
      + corner2.get_x() * corner3.get_y()
      + corner3.get_x() * corner1.get_y()
      - corner1.get_x() * corner3.get_y()
      - corner2.get_x() * corner1.get_y()
      - corner3.get_x() * corner2.get_y());

   return x;
}

void Triangle::plot() const
{
   cwin << Line(corner1, corner2);
   cwin << Line(corner2, corner3);
   cwin << Line(corner3, corner1);
}

int ccc_win_main()
{
   vector<Shape*> v(9);

   /* populate shapes */
   v[0] = new Rectangle(Point(2,2), 2, 3);
   v[1] = new Rectangle(Point(14,2), 1, 3);
   v[2] = new Rectangle(Point(27,2), 5, 8);
   v[3] = new Square(Point(2,12), 5);
   v[4] = new Square(Point(15,12), 3);
   v[5] = new Square(Point(30,12), 2);
   v[6] = new Triangle(Point(2,22),Point(4, 16), Point(1,10));
   v[7] = new Triangle(Point(15,22),Point(14,17),Point(12,20));
   v[8] = new Triangle(Point(30,22), Point(28,18),Point(22,19));

   cwin.coord(0,50,50,0);
   double total_area = 0;

   int i;
   for (i = 0; i < v.size(); i++)
   {
      v[i]->plot();
      total_area = total_area + v[i]->area();
   }
   string s = "The total area of all shapes is ";
   cwin << Message(Point(10,45), s);
   cwin << Message(Point(35,45), total_area);
   return 0;
}
