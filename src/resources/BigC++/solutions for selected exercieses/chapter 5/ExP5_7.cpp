#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;
   
/**
   Calculates the volume of a sphere.
   @param r radius
   @return volume of the sphere
*/
double sphere_volume( double r)
{
   return 4 / 3. * PI * r * r * r;
}

/**
   Calculates the surface area of a sphere.
   @param r radius
   @return surface area of the sphere
*/
double sphere_surface( double r)
{
   return 4 * PI * r * r;
}

/**
   Calculates the volume of a cylinder.
   @param r radius
   @param h height of cylinder
   @return volume of the cylinder
*/
double cylinder_volume( double r, double h)
{
   return PI * r * r * h;
}

/**
   Calculates the surface area of a cylinder.
   @param r radius
   @param h height of cylinder
   @return surface area of the cylinder
*/
double cylinder_surface( double r, double h)
{
   return 2 * PI * r * h;
}

/**
   Calculates the volume of a cone.
   @param r radius
   @param h height of cone
   @return volume of the cone
*/
double cone_volume( double r, double h)
{
   return 1 / 3. * PI * r * r * h;
}

/**
   Calculates the surface area of a cone.
   @param r radius
   @param h height of cone
   @return surface area of the cone
*/
double cone_surface( double r, double h)
{
   return sqrt(r * r + h * h) * r * PI;
}

int main()
{
   double radius;
   double height;
   cout << "Please enter a radius value: ";
   cin >> radius;
   cout << "Please enter a height value: ";
   cin >> height;

   cout << "The volume of a sphere of radius " << radius <<
      " is " << sphere_volume(radius) << ".\n";
   cout << "The surface area of a sphere of radius " << radius <<
      " is " << sphere_surface(radius) << ".\n";
   cout << "The volume of a cylinder of radius " << radius <<
      " and height " << height << " is " <<
      cylinder_volume(radius, height) << ".\n";
   cout << "The surface area of a cylinder of radius " << radius <<
      " and height " << height << " is " <<
      cylinder_surface(radius, height) << ".\n";
   cout << "The volume of a cone of radius " << radius <<
      " and height " << height << " is " <<
      cone_volume(radius, height) << ".\n";
   cout << "The surface area of a cone of radius " << radius <<
      " and height " << height << " is " <<
      cone_surface(radius, height) << ".\n";

   return 0;
}
