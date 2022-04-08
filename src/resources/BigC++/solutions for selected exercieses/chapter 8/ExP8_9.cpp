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
   cout << "Entering digit_name with input " << n << ".\n";
   string r;
   if (n == 1) r = "one";
   else if (n == 2) r = "two";
   else if (n == 3) r = "three";
   else if (n == 4) r = "four";
   else if (n == 5) r = "five";
   else if (n == 6) r = "six";
   else if (n == 7) r = "seven";
   else if (n == 8) r = "eight";
   else if (n == 9) r = "nine";
   else r = "";
   cout << "Exiting int_name, returning " << r << "\n";
   return r;
}

/**
   Turns a number between 10 and 19 into its English name.
   @param n an integer between 10 and 19
   @return the name of n ("ten" . . . "nineteen")
*/
string teen_name(int n)
{
   cout << "Entering teen_name with input " << n << ".\n";
   string r;
   if (n == 10) r = "ten";
   else if (n == 11) r = "eleven";
   else if (n == 12) r = "twelve";
   else if (n == 13) r = "thirteen";
   else if (n == 14) r = "fourteen";
   else if (n == 15) r = "fifteen";
   else if (n == 16) r = "sixteen";
   else if (n == 17) r = "seventeen";
   else if (n == 18) r = "eighteen";
   else if (n == 19) r = "nineteen";
   else r = "";
   cout << "Exiting teen_name, returning " << r << "\n";
   return r;
}

/**
   Gives the English name of a multiple of 10.
   @param n an integer between 2 and 9
   @return the name of 10 * n ("twenty" . . . "ninety")
*/
string tens_name(long n)
{
   cout << "Entering tens_name with input " << n << ".\n";
   string r;
   if (n == 2) r = "twenty";
   else if (n == 3) r = "thirty";
   else if (n == 4) r = "forty";
   else if (n == 5) r = "fifty";
   else if (n == 6) r = "sixty";
   else if (n == 7) r = "seventy";
   else if (n == 8) r = "eighty";
   else if (n == 9) r = "ninety";
   else r = "";
   cout << "Exiting tens_name, returning " << r << "\n";
   return r;
}

/**
   Turns a number into its English name.
   @param n a positive integer <= 999999
   @return the name of n (e.g. " two hundred seventy four")
   @return NOTE:       this function will return the string with a leading blank
*/
string int_name(long n)
{
   long c = n; /* the part that still needs to be converted */
   string r; /* the return value */
   cout << "Entering int_name with input " << n << ".\n";
   if (c == 0) return "zero";

   if (c < 0)
   {
      r = "minus";
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

   cout << "Exiting int_name, returning " << r << "\n";
   return r;
}

int main()
{
   long n;
   cout << "Please enter a positive integer: ";
   cin >> n;
   cout << int_name(n);
   return 0;
}
