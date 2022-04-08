#include <iostream>

using namespace std;

#include "ccc_time.h"

int main()
{  
   const int SECONDS_PER_MINUTE = 60;

   cout << "Enter the time your next assignment is due (hour min): ";
   int hour;
   int min;

   cin >> hour >> min;

   Time due_time(hour, min, 0); 
   Time now;

   int diff = due_time.seconds_from(now) / SECONDS_PER_MINUTE; 

   cout << "The assignment is due in " << diff << " minutes." << "\n";

   return 0;
}

