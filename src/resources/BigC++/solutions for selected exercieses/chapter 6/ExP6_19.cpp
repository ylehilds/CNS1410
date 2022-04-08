#include "ccc_win.h"

using namespace std;

const double G = -9.81;
const double PI = 3.141592653589793;

class Cannonball
{
public:
   Cannonball(double x);
   void move(double sec);
   void plot() const;
   void shoot(double angle, double v);

private:
   double x_position;
   double y_position;
   double x_velocity;  /* measured in m/sec */
   double y_velocity;  /* measured in m/sec */
};

Cannonball::Cannonball(double x)
{
   x_position = x;
   y_position = 0;
   x_velocity = 0;
   y_velocity = 0;
}

void Cannonball::move(double sec)
{
   x_position = x_position + x_velocity * sec;
   y_position = y_position + y_velocity * sec;
   y_velocity = y_velocity + G * sec;
}

void Cannonball::plot() const
{
   cwin << Point(x_position, y_position);
}

void Cannonball::shoot(double angle, double v)
{
   x_velocity = v * cos(angle * PI / 180.0);
   y_velocity = v * sin(angle * PI / 180.0);
   plot();
   do
   {
      move(0.1);   /* time interval of 0.1 seconds */
      plot();
   } while (y_position > 0);
}

int ccc_win_main()
{
   cwin.coord(0, 100, 100, 0);
   double angle = cwin.get_double("Enter the launch angle in degrees: (e.g. 45)");
   double ini_vel = cwin.get_double("Enter the initial velocity in m/s: (e.g. 30) ");
   Cannonball theball(0);
   theball.shoot(angle, ini_vel);

   return 0;
}
