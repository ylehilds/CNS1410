#include "ccc_x11.h"
#include <iostream>
#include <vector>

using namespace std;

class Chart 
{
public:
   void add(double v);
   virtual void draw(const Point& p) const = 0;
protected:
   vector<double> values;
};

void Chart::add(double v)
{
   values.push_back(v);
}

class PieChart : public Chart 
{
public:
   virtual void draw(const Point& p) const;
};

void PieChart::draw(const Point& Origin) const
{
   const double RADIUS = 4;
   const double PI = 3.1415926;

   double total = 0.0;
   for (int i = 0; i < values.size(); i++)
	total += values[i];

   cwin << Circle(Origin, RADIUS);

   double theta = 0.0;
   for (int i = 0; i < values.size(); i++) 
   {
      double x = RADIUS * cos(theta);
      double y = RADIUS * sin(theta);
      cwin << Line(Origin, Point(x, y));
      theta += 2 * PI * values[i] / total;
   }
}

class Rectangle {
public:
   Rectangle (double ix, double iy, double w, double h);
   virtual void draw();
protected:
   double x, y;
   double height, width;
};

Rectangle::Rectangle(double ix, double iy, double w, double h)
  : x(ix), y(iy), height(h), width(w)
{ }

void Rectangle::draw()
{
   Point ul(x, y);
   Point ur(x+width, y);
   Point ll(x, y+height);
   Point lr(x+width, y+height);
   Line l1(ul, ur);
   Line l2(ul, ll);
   Line l3(ur, lr);
   Line l4(ll, lr);
   cwin << l1 << l2 << l3 << l4;
}

class BarChart : public Chart
{
public:
   virtual void draw(const Point& p) const;
};

void BarChart::draw(const Point& origin) const
{
   double x = origin.get_x();
   double y = origin.get_y();
   for (int i = 0; i < values.size(); i++) 
   {
      Rectangle r(x, y, values[i], 1);
      r.draw();
      y -= 2;
   }
}

int ccc_win_main() {
   PieChart data;
   data.add(3.0);
   data.add(2.0);
   data.add(4.0);
   data.draw(Point(0, 0));
   return 0;
}
