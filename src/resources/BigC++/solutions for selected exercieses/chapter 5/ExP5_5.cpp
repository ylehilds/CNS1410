#include <iostream>
#include <string>

using namespace std;

/**
   Turns a digit into its English name.
   @param n an integer between 1 and 9
   @return the name of n ("one" . . . "nine")
*/
string digit_name(int n)
{
   if (n == 1) return "one";
   else if (n == 2) return "two";
   else if (n == 3) return "three";
   else if (n == 4) return "four";
   else if (n == 5) return "five";
   else if (n == 6) return "six";
   else if (n == 7) return "seven";
   else if (n == 8) return "eight";
   else if (n == 9) return "nine";
   return "";
}

/**
   Turns a number between 10 and 19 into its English name.
   @param n an integer between 10 and 19
   @return the name of n ("ten" . . . "nineteen")
*/
string teen_name(int n)
{
   if (n == 10) return "ten";
   else if (n == 11) return "eleven";
   else if (n == 12) return "twelve";
   else if (n == 13) return "thirteen";
   else if (n == 14) return "fourteen";
   else if (n == 15) return "fifteen";
   else if (n == 16) return "sixteen";
   else if (n == 17) return "seventeen";
   else if (n == 18) return "eighteen";
   else if (n == 19) return "nineteen";
   return "";
}

/**
   Gives the English name of a multiple of 10.
   @param n an integer between 2 and 9
   @return the name of 10 * n ("twenty" . . . "ninety")
*/
string tens_name(long n)
{
   if (n == 2) return "twenty";
   else if (n == 3) return "thirty";
   else if (n == 4) return "forty";
   else if (n == 5) return "fifty";
   else if (n == 6) return "sixty";
   else if (n == 7) return "seventy";
   else if (n == 8) return "eighty";
   else if (n == 9) return "ninety";
   return "";
}

/**
   Turns a number into its English name.
   @param n any integer between -999999 and 999999 
   @return the name of n (e.g. "two hundred seventy four")
*/
string int_name(int n)
{
   long c = n; /* the part that still needs to be converted */
   string r; /* the return value */

   if (c == 0) return "zero";

   if (c < 0)
   {
      r = "negative";
      c = -c;
   }

   if (c >= 1000)
   {
      r = r + int_name(c / 1000) + " thousand";
      c = c % 1000;
   }

   if (c >= 100)
   {
      r = r + " " + digit_name(c / 100) + " hundred";
      c = c % 100;
   }

   if (c >= 20)
   {
      r = r + " " + tens_name(c / 10);
      c = c % 10;
   }
   else if (c >= 10)
   {
      r = r + " " + teen_name(c);
      c = 0;
   }

   if (c > 0)
      r = r + " " + digit_name(c);

   return r;
}

int main()
{
   int n;
   cout << "Please enter an integer: ";
   cin >> n;
   cout << int_name(n) << "\n";
   return 0;
}

