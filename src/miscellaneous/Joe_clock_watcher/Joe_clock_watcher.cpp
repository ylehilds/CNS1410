#include <iostream>
using namespace std;

int main( )
{
     // DECLARE CONSTANTS
     const int QUIT_TIME = 2300;
     const int HUNDRED = 100;       // conversion factor
     const  int SIXTY = 60;             // conversion factor
     int currentTime = 1300;

     cout << "Please type in the current time in military format (hhmm): ";
     cin >> currentTime;

     // convert current time to minutes
     int currHours = currentTime / HUNDRED;
     int currMins = currHours * SIXTY + (currentTime % HUNDRED);

     // convert quit time to minutes (could have used a constant for this, but this is more general)
     int quitHours = QUIT_TIME / HUNDRED;
     int quitMins = quitHours * SIXTY + (QUIT_TIME % HUNDRED);

     // calculate minutes left till quitting time
     int minsLeft = quitMins - currMins;

     // convert back to hours and minutes
     int hoursLeft = minsLeft / SIXTY;
     minsLeft = minsLeft % 60;

     // print result
     cout << "\nThere are " << hoursLeft << " hours and " << minsLeft << " minutes left till quitting time!";

     system("PAUSE");
     return 0;
}

