#include <iostream>
#include <string>

using namespace std;

class Country
{
public:
   Country();
   Country(string n, long p, double a);
   string get_name() const;
   long get_population() const;
   double get_area() const;
   double get_population_density() const;

 private:
   string name;
   long population;
   double area;    /* square kilometers */
};

Country::Country()
{
   population = 0;
   area = 0;
}

Country::Country(string n, long p, double a)
{
   name = n;
   population = p;
   area = a;
}

string Country::get_name() const
{
   return name;
}

long Country::get_population() const
{
   return population;
}

double Country::get_area() const
{
   return area;
}

double Country::get_population_density() const
{
   if (area == 0) return 0;
   else return population / area;
}

int main()
{
   Country largest_country;   /* name of biggest country */
   Country most_people;     /* name of country with most people */
   Country highest_density;   /* name of country with highest density */

   bool more = true;
   while (more)
   {
      string s;
      cout << "Enter the country's name, or QUIT to finish:";
      cin >> s;
      if (cin.fail())
        more = false;
      else if (s == "QUIT")
         more = false;
      else
      {
         cout << "Enter the population of " << s << ": ";
         long pop;
         cin >> pop;
         cout << "Enter the area of " << s << " in square km: ";
         double area;
         cin >> area;
         Country c(s, pop, area);

         /* determine if this country is the largest one so far */
         if (c.get_area() > largest_country.get_area())
            largest_country = c;
         if (c.get_population() > most_people.get_population())
            most_people = c;
         if (c.get_population_density() > highest_density.get_population_density())
            highest_density = c;
      }
   }
   cout << most_people.get_name() << "has the largest population with " << most_people.get_population() << " people.\n";
   cout << largest_country.get_name() << " has the largest area with " << largest_country.get_area() << " square km.\n";
   cout << highest_density.get_name() << " has the highest density with " << highest_density.get_population_density() << " people per sq. km.\n";
   return 0;
}
