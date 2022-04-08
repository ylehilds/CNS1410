#include <iostream>
#include <string>

using namespace std;

/**
   Returns the bar code value for a given digit.
   @param digit integer
   @return string encoding of the digit
*/
string code(int digit)
{
   if ( digit == 0 )
      return "||:::";
   else if (digit == 1)
      return ":::||";
   else if (digit == 2)
      return "::|:|";
   else if (digit == 3)
      return "::||:";
   else if (digit == 4)
      return ":|::|";
   else if (digit == 5)
      return ":|:|:";
   else if (digit == 6)
      return ":||::";
   else if (digit == 7)
      return "|:::|";
   else if (digit ==8)
      return "|::|:";
   else
      return "|:|::";
}

/**
   Calculates the sum of all digits of p.
   @param p long value
   @return sum of digits in p
*/
int digitsum(long p)
{
   if (p > 0)
      return (p % 10) + digitsum(p / 10);
   else
      return 0;
}

/**
   Determines the barcode sequence for a given code.
   @param postal long value
   @return string representation of barcode
*/
string barcode(long postal)
{
   string bars = code(postal % 10);
   postal = postal / 10;
   bars = code(postal % 10) + bars;
   postal = postal / 10;
   bars = code(postal % 10) + bars;
   postal = postal / 10;
   bars = code(postal % 10) + bars;
   postal = postal / 10;
   bars = code(postal % 10) + bars;
   
   int c = digitsum(postal); /* calculate the correction digit */
   int correction = (10 - c % 10) % 10;

   return "|" + bars + code(correction) + "|";
}

int main()
{
   cout << "Enter a ZIP code number: ";
   long postal;
   cin >> postal;

   cout << "The bar code representation of " << postal << " is " 
        << barcode(postal) << ".\n";

   return 0;
}
