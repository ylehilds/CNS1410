#include <iostream>
#include <iomanip>
   
using namespace std;

const double G = 9.81;

int main()
{  
   const double delta_t = 0.01;
   double v0;
   
   cout << "Enter the initial velocity in m/sec: ";
   cin >> v0;

   double s = 0;
   double v = v0;
   int seconds = 0;

   cout << "   Incremented   Calculated\n";
   cout << "    Distance      Distance\n";
   cout << " sec       (m)       (m)\n";

   while (s >= 0)
   {  
      int i = 1;
      while (i <= 100)
      {  
         s = s + v * delta_t;
         v = v - G * delta_t;
         i++;
      }
      seconds++;

      cout << setiosflags(ios::fixed) << setprecision(2);

      double pos = -1 / 2.0 * G * seconds * seconds + v0 * seconds;
      cout << setw(3) << seconds << setw(13) << s << setw(14) 
         << pos << "\n";
   }

   return 0;
}
