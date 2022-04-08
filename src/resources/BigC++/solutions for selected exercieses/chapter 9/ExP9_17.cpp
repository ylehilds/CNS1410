#include <vector>

using namespace std;

#include "ccc_win.h"

void rand_seed()
{
   int seed = static_cast<int>(time(0));
   srand(seed);
}
    
double rand_double(double a, double b)
{
   return a + (b - a) * rand() * (1.0 / RAND_MAX);
}

void bar_chart(vector<double> data)
{
   double max;
   double min;
   int num_elements = data.size();
   /* find the maximum and minimum value of all data elements
   */
   if (num_elements > 0)
   {
      max = data[0];
      min = data[0];
      for (int i = 1; i < num_elements; i++)
      {
         if (data[i] > max) max = data[i];
         if (data[i] < min) min = data[i];
      }
   }

   cwin.coord(0, max, num_elements, min);
   int left_border = 0;
   for (int i = 0; i < num_elements; i++)
   {
      Point p1(i, 0);
      Point p2(i, data[i]);
      Point p3(i + 1, 0);
      Point p4(i + 1, data[i]);
      cwin << Line(p1, p2) << Line(p1, p3) << Line(p2, p4)
         << Line(p3, p4);
    }
}

int ccc_win_main()
{
   rand_seed();
   int DATA_SIZE = 10;
   vector<double> data(DATA_SIZE);
   for (int i = 0; i < DATA_SIZE; i++)
      data[i] = rand_double(-100, 100);
   bar_chart(data);

   return 0;
}

