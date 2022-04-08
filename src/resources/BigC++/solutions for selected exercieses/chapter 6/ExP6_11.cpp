#include <iostream>

using namespace std;

/**
   A cylindrical can. 
*/
class SodaCan
{
public:
   /**
      Constructs a soda can with a given height and radius.
      @param h the height
      @param r the radius
   */
   SodaCan(double h, double r);
   /**
      Computes the surface area of the can.
      @return the surface area
   */
   double get_surface_area() const;
   /**
      Computes the volume of the can.
      @return the volume
   */
   double get_volume() const;
private:
   double height;
   double radius;
};

const double PI = 3.141592653589793;

SodaCan::SodaCan(double h, double r)
{
   height = h;
   radius = r;
}

double SodaCan::get_surface_area() const
{
   return 2 * PI * radius * height;
}

double SodaCan::get_volume() const
{
   return  PI * radius * radius * height;
}

int main()
{
   SodaCan can(10, 5);
   cout << can.get_volume() << "\n";
   cout << can.get_surface_area() << "\n";
   return 0;
}
