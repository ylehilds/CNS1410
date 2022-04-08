#include <iostream>
#include <vector>
#include "ccc_win.h"

/**
   A shape that can be drawn on the graphics window
*/
class Shape
{
public:
   /**
      Draws the current shape in the graphics window
      @param win the window in which to draw
   */
   virtual void draw(GraphicWindow& win) const = 0;

   /**
      Move the current shape by a fixed amount
      @param dx amount to move in x direction
      @param dy amount to move in y direction
   */
   virtual void move(double dx, double dy) = 0;
};

/**
  A shape that encapsulates the graphics window Circle object
*/
class CircleShape : public Shape
{
public:
   /**
     Create a circle with given radius centered at given point
     @param center center point for circle
     @param radius radius of circle
   */
   CircleShape(Point center, double radius);

   /**
      Draws the current shape in the graphics window
      @param win the window in which to draw
   */
   virtual void draw(GraphicWindow& win) const;

   /**
      Move the current shape by a fixed amount
      @param dx amount to move in x direction
      @param dy amount to move in y direction
   */
   virtual void move(double dx, double dy);

private:
   Circle c;
};

CircleShape::CircleShape(Point center, double radius) 
   : c(center, radius) { }

void CircleShape::draw(GraphicWindow& win) const
{
   win << c;
}

void CircleShape::move(double dx, double dy)
{
   c.move(dx, dy);
}

/**
  A shape that encapsulates the graphics window Line object
*/
class LineShape : public Shape
{
public:
   /**
     Create a line between two points
     @param s the starting point
     @param e the ending point
   */
   LineShape(Point s, Point e);

   /**
      Draws the current shape in the graphics window
      @param win the window in which to draw
   */
   virtual void draw(GraphicWindow& win) const;

   /**
      Move the current shape by a fixed amount
      @param dx amount to move in x direction
      @param dy amount to move in y direction
   */
   virtual void move(double dx, double dy);
private:
   Line lne;
};

LineShape::LineShape(Point s, Point e) : lne(s, e) { }

void LineShape::draw(GraphicWindow& win) const
{
   win << lne;
}

void LineShape::move(double dx, double dy)
{
   lne.move(dx, dy);
}

/**
  A shape that encapsulates the graphics window Message object
*/
class MessageShape : public Shape
{
public:
   /**
     Create a message at current point with given text
     @param p the point for the message
     @param m the message to be printed
   */
   MessageShape(Point p, string m);

   /**
      Draws the current shape in the graphics window
      @param win the window in which to draw
   */
   virtual void draw(GraphicWindow& win) const;

   /**
      Move the current shape by a fixed amount
      @param dx amount to move in x direction
      @param dy amount to move in y direction
   */
   virtual void move(double dx, double dy);
private:
   Message msg;
};

MessageShape::MessageShape(Point p, string m) : msg(p, m) { }

void MessageShape::draw(GraphicWindow& win) const
{
   win << msg;
}

void MessageShape::move(double dx, double dy)
{
   msg.move(dx, dy);
}

int  ccc_win_main()
{
   vector<Shape*> items;
   Point p(1, 3);
   items.push_back(new CircleShape(p, 2.4));
   Point q(4, 7);
   items.push_back(new LineShape(p, q));
   items.push_back(new MessageShape(p, "hello world\n"));

   vector<Shape*>::iterator current = items.begin();
   vector<Shape*>::iterator stop = items.end();
   while (current != stop) 
   {
     (*current)->draw(cwin);
     ++current;
   }
   return 0;
}
