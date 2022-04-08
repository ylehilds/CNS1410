#include <iostream>
#include <string>

using namespace std;

/**
   Returns the bar code value for a given bar code string.
   @param code bar code string
   @return value of the bar code, -1 if invalid code
*/
int value(string code)
{
   if (code == "||:::")
      return 0;
   else if (code == ":::||")
      return 1;
   else if (code == "::|:|")
      return 2;
   else if (code == "::||:")
      return 3;
   else if (code == ":|::|")
      return 4;
   else if (code == ":|:|:")
      return 5;
   else if (code == ":||::")
      return 6;
   else if (code == "|:::|")
      return 7;
   else if (code == "|::|:")
      return 8;
   else if (code == "|:|::")
      return 9;
   else
      return -1; /* error */
}

/**
   Converts a barcode sequence into its numeric form.
   @param barcode string
   @return numeric form of the barcode, -1 if invalid
*/
long convert(string barcode)
{
   const int NDIGIT = 6;
   const int DIGIT_LENGTH = 5;
   if (barcode.length() != 2 + NDIGIT * DIGIT_LENGTH) 
      return -1;
   if (barcode.substr(0, 1) != "|") return -1;
   if (barcode.substr(barcode.length() - 1, 1) != "|") return -1;
      
   int d1 = value(barcode.substr(1, DIGIT_LENGTH));
   int d2 = value(barcode.substr(1 + DIGIT_LENGTH, DIGIT_LENGTH));
   int d3 = value(barcode.substr(1 + 2 * DIGIT_LENGTH, DIGIT_LENGTH));
   int d4 = value(barcode.substr(1 + 3 * DIGIT_LENGTH, DIGIT_LENGTH));
   int d5 = value(barcode.substr(1 + 4 * DIGIT_LENGTH, DIGIT_LENGTH));
   int d6 = value(barcode.substr(1 + 5 * DIGIT_LENGTH, DIGIT_LENGTH));

   if ((d1 + d2 + d3 + d4 + d5 + d6) % 10 != 0)
      return -1;
      
   return 10000L * d1 + 1000 * d2 + 100 * d3 + 10 * d4 + d5;      
}

int main()
{
   string barcode;         /*  = "||:|:::|:|:||::::::||:|::|:::|||";  */
   cout << "Enter a postal bar code: ";
   cin >> barcode;

   long v = convert(barcode);
   if (v >= 0)
      cout << "The value is " << v << ".\n";
   else
      cout << "The postal bar code is invalid.\n";

   return 0;
}
