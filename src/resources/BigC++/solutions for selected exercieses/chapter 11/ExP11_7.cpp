#include <vector>

using namespace std;

#include "ccc_win.h"

using namespace std;

class Vehicle
{
public:
   Vehicle();
   Vehicle(Point p);
   Point get_position() const;
   virtual void draw() const;
private:
   Point position;
};

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(Point p)
{
   position = p;
}

/**
   return the vehicle position
*/
Point Vehicle::get_position() const
{
   return position;
}

void Vehicle::draw() const
{
}

class Car : public Vehicle
{
public:
   Car();
   Car(Point p);
   virtual void draw() const;
};

Car::Car()
{
}

Car::Car(Point p) : Vehicle(p)
{
}

void Car::draw() const
{
   Point p = get_position();
   double x = p.get_x();
   double y = p.get_y();

   cwin << Line(Point(x, y + 2), Point(x, y + 4));
   cwin << Line(Point(x, y + 4), Point(x+10,y+4));
   cwin << Line(Point(x+10,y + 4), Point(x+10,y+2));
   cwin << Line(Point(x+10,y + 2), Point(x, y+2));

   cwin << Line(Point(x+3, y + 4), Point(x+3, y+6));
   cwin << Line(Point(x+3, y + 6), Point(x+7, y+6));
   cwin << Line(Point(x+7, y + 6), Point(x+7, y+4));

   cwin << Circle(Point(x+3, y+1), 1);
   cwin << Circle(Point(x+7, y+1), 1);
}

class Truck : public Vehicle
{
public:
   Truck();
   Truck(Point p);
   virtual void draw() const;
};

Truck::Truck()
{
}

Truck::Truck(Point p) : Vehicle(p)
{
}

void Truck::draw() const
{
   Point p = get_position();
   double x = p.get_x();
   double y = p.get_y();

   cwin << Line(Point(x, y + 2), Point(x, y + 7));
   cwin << Line(Point(x, y + 7), Point(x + 4,y + 7));
   cwin << Line(Point(x + 4,y + 7), Point(x + 4,y + 2));
   cwin << Line(Point(x + 4,y + 2), Point(x, y + 2));

   cwin << Line(Point(x + 4.1, y + 2), Point(x + 4.1, y + 8));
   cwin << Line(Point(x + 4.1, y + 8), Point(x + 12, y + 8));
   cwin << Line(Point(x + 12, y + 8), Point(x + 12, y + 2));
   cwin << Line(Point(x + 12, y + 2), Point(x + 4.1, y + 2));

   cwin << Circle(Point(x + 2, y + 1), 1);
   cwin << Circle(Point(x + 5, y + 1), 1);
   cwin << Circle(Point(x + 7, y + 1), 1);
   cwin << Circle(Point(x + 9, y + 1), 1);
   cwin << Circle(Point(x + 11, y + 1), 1);
}

int ccc_win_main()
{
   vector<Vehicle*> v(6);

   /* populate vehicles */
   v[0] = new Car(Point(2,2));
   v[1] = new Truck(Point(14,2));
   v[2] = new Car(Point(27,2));
   v[3] = new Truck(Point(2,12));
   v[4] = new Car(Point(15,12));
   v[5] = new Car(Point(30,12));

   cwin.coord(0,50,50,0);
   int i;
   for (i = 0; i < v.size(); i++)
      v[i]->draw();

   return 0;
}
