#include <iostream> 
#include <cmath> 

using namespace std; 

int main() 
{  
   const int MINUTES_IN_HOUR = 60; 
   const int MINUTES_PER_DAY = 24 * 60; 
  
   cout << "Please enter the first time: "; 
   int first_time; 
   cin >> first_time ; 
  
   cout << "Please enter the second time: "; 
   int second_time; 
   cin >> second_time; 

  
   /* convert the times into number of minutes */ 

   int hours1 = first_time / 100; 
   int minutes1 = first_time % 100; 
   int time1 = hours1 * MINUTES_IN_HOUR + minutes1; 

   int hours2 = second_time / 100; 
   int minutes2 = second_time % 100; 
   int time2 = hours2 * MINUTES_IN_HOUR + minutes2; 

   int diff = time2 - time1; 

   diff = (diff + MINUTES_PER_DAY) % MINUTES_PER_DAY;   
      /* if diff is negative, add one day */ 
  
   int hours = diff / MINUTES_IN_HOUR; 
   int minutes = diff % MINUTES_IN_HOUR; 

   cout << hours << " hours " << minutes << " minutes" << "\n"; 

   return 0; 
} 
  
