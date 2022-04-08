#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int WEEKDAY_RATE = 0;
const int EVENING_RATE = 1;
const int NIGHT_WEEKEND_RATE = 2;

const int FIRST = 0;
const int ADDITIONAL = 1;

const int SATURDAY = 5;
const int SUNDAY = 6;

int get_rate(int wday, int hour)
{
   if (hour < 8 || hour >= 23) return NIGHT_WEEKEND_RATE;
   if (wday == SATURDAY) return NIGHT_WEEKEND_RATE;
   if (hour >= 17 && hour < 23) return EVENING_RATE;
   if (wday == SUNDAY) return NIGHT_WEEKEND_RATE;
   return WEEKDAY_RATE;
}

int main()
{
   double rate[3][9][2];
   vector<string> destination(9);
   vector<string> weekday(7);

   rate[0][0][0] = .19;  rate[0][0][1] = .09;
   rate[0][1][0] = .26;  rate[0][1][1] = .12;
   rate[0][2][0] = .32;  rate[0][2][1] = .14;
   rate[0][3][0] = .38;  rate[0][3][1] = .15;
   rate[0][4][0] = .43;  rate[0][4][1] = .17;
   rate[0][5][0] = .48;  rate[0][5][1] = .19;
   rate[0][6][0] = .51;  rate[0][6][1] = .20;
   rate[0][7][0] = .53;  rate[0][7][1] = .21;
   rate[0][8][0] = .54;  rate[0][8][1] = .22;

   rate[1][0][0] = .12;  rate[1][0][1] = .05;
   rate[1][1][0] = .16;  rate[1][1][1] = .07;
   rate[1][2][0] = .20;  rate[1][2][1] = .09;
   rate[1][3][0] = .24;  rate[1][3][1] = .09;
   rate[1][4][0] = .27;  rate[1][4][1] = .11;
   rate[1][5][0] = .31;  rate[1][5][1] = .12;
   rate[1][6][0] = .33;  rate[1][6][1] = .13;
   rate[1][7][0] = .34;  rate[1][7][1] = .13;
   rate[1][8][0] = .35;  rate[1][8][1] = .14;

   rate[2][0][0] = .07;  rate[2][0][1] = .03;
   rate[2][1][0] = .10;  rate[2][1][1] = .04;
   rate[2][2][0] = .12;  rate[2][2][1] = .05;
   rate[2][3][0] = .15;  rate[2][3][1] = .06;
   rate[2][4][0] = .17;  rate[2][4][1] = .06;
   rate[2][5][0] = .19;  rate[2][5][1] = .07;
   rate[2][6][0] = .20;  rate[2][6][1] = .08;
   rate[2][7][0] = .21;  rate[2][7][1] = .08;
   rate[2][8][0] = .21;  rate[2][8][1] = .08;

   destination[0] = "Sudbury";
   destination[1] = "Framingham";
   destination[2] = "Lowell";
   destination[3] = "Brockton";
   destination[4] = "Worcester";
   destination[5] = "Rockport";
   destination[6] = "Fall River";
   destination[7] = "Falmouth";
   destination[8] = "Hyannis";
   
   weekday[0] = "Monday";
   weekday[1] = "Tuesday";
   weekday[2] = "Wednesday";
   weekday[3] = "Thursday";
   weekday[4] = "Friday";
   weekday[5] = "Saturday";
   weekday[6] = "Sunday";

   cout << "Enter the destination code: (1-8)\n";
   for (int i = 0; i < destination.size(); i++)
       cout << (i+1) << " " << destination[i] << "\n";
   int dest_code;
   cin >> dest_code;
   if (dest_code < 1 || dest_code > destination.size())
   {
      cout << "Illegal input.\n";
      return 0;
   }
   dest_code--;
      
   cout << "Enter the starting hours: (0-23) ";
   int ihour;
   cin >> ihour;
   if (ihour < 0 || ihour > 23)
   {
      cout << "Illegal input.\n";
      return 0;
   }
  
   cout << "Enter the starting minutes: (0-59) ";
   int iminutes;
   cin >> iminutes;
   if (iminutes < 0 || iminutes > 59)
   {
      cout << "Illegal input.\n";
      return 0;
   }
   
   cout << "Enter the length of the call in minutes: ";
   int calltime;
   cin >> calltime;

   cout << "Enter the day of the week: (1-7)\n";
   for (int i = 0; i < weekday.size(); i++)
       cout << (i+1) << " " << weekday[i] << "\n";
   int wday;
   cin >> wday;
   if (wday < 1 || wday > weekday.size())
   {
      cout << "Illegal input.\n";
      return 0;
   }
   wday--;

   int minute = FIRST;
   double charge = 0;    /* cumulative charge */

   for (int count_mins = 0; count_mins < calltime; count_mins++)
   {
      int r = get_rate(wday, ihour);
      charge = charge + rate[r][dest_code][minute];      
      minute = ADDITIONAL;
      iminutes++;
      if (iminutes == 60)
      {
         iminutes = 0;
         ihour++;
         if (ihour == 24)
            ihour = 0;
      }
   }

   cout << "Charge is $" << charge << "\n";

   return 0;
}
