#include <iostream>
#include <cmath>

using namespace std;

/**
   Converts a Julian day number into its year/month/day.
   @param jul long value representing Julian day number
   @return year - int
   @return month - int
   @return day - int
*/
void jul_to_date(long jul, int& year, int& month, int& day)
{
   long JGREG = 2299161;
         /* the Julian day number of the adoption of the Gregorian
            calendar    
         */   
   if (jul >= JGREG)
   {
      long jalpha = ((jul - 1867216) - 0.25) / 36524.25;
      jul = jul + 1 + jalpha - (int)(0.25 * jalpha);
   }
   long jb = jul + 1524;
   long jc = 6680.0 + (jb - 2439870 - 122.1)/365.25;
   long jd = 365 * jc + (0.25 * jc);
   int je = (jb - jd)/30.6001;

   day = jb - jd - (long)(30.6001 * je);
   month = je - 1;
   year = (int)(jc - 4715);

   if (month > 12) month = month - 12;
   if (month > 2) year = year - 1;
   if (year < 0) year = year - 1;
}

/**
   Converts a date into a Julian day number.
   @param year integer
   @param month integer
   @param day integer
   @return long value representing Julian day number
*/
long julian(int year, int month, int day)
{
   int jy = year;
   int jm = month;
   int jd = day;

   if (jy < 0) jy++;

   if (jm > 2)
      jm++;
   else
   {
      jm = jm + 13;
      jy = jy - 1;
   }
   long jul = floor(365.25 * jy) + floor(30.6001 * jm) + jd + 1720995.0;

   /* If the date is before Oct 15, 1582, return this value */

   if (jy < 1582 || (jy == 1582 && (jm < 10 || (jm == 10 && jd < 15))))
      return jul;
      
   /* Apply a correction */

   int ja = static_cast<int>(0.01 * jy);
   jul = jul + 2 - ja + 0.25 * ja;

   return jul;
}

int main()
{
   cout << "Enter a year, month, day (eg 1998 3 23 or -1293 12 4): ";
   int year;
   int month;
   int day;
   cin >> year >> month >> day;

   long jul_then = julian(year, month, day);

   cout << "Enter the number of days prior to that date: ";
   long n;
   cin >> n;

   long jul_new = jul_then - n;

   jul_to_date(jul_new, year, month, day);

   cout << "The date " << year << " " << month << " " << day << " is " <<
      n << " days away.\n";

   return 0;
}
