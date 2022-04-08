#include <iostream>
#include <string>

using namespace std;

/**
   Returns the number form of a Roman digit.
   @param digit string, the digit to convert from Roman
   @return the equivalent decimal value
*/
int roman_value(string digit)
{
   if (digit == "I") return 1;
   else if (digit == "V") return 5;
   else if (digit == "X") return 10;
   else if (digit == "L") return 50;
   else if (digit == "C") return 100;
   else if (digit == "D") return 500;
   else if (digit == "M") return 1000;
   else return 0;
}

/**
   Returns the decimal form of a Roman number.
   @param roman string, the number to convert from Roman
   @return the equivalent decimal value 
*/
int convert_from_roman(string roman)
{
   if (roman.length() == 0)
      return 0;
   if (roman.length() == 1)
      return roman_value(roman);
   string first = roman.substr(0,1);
   string second = roman.substr(1,1);

   int v1 = roman_value(first);
   int v2 = roman_value(second);
   
   if (v1 >= v2) 
      return v1 + convert_from_roman(roman.substr(1, roman.length() - 1));
   else
      return v2 - v1 + convert_from_roman(roman.substr(2, roman.length() - 2));
}

int main()
{
   cout << "Enter a Roman number: ";
   string roman;
   cin >> roman;

   int value = convert_from_roman(roman);

   cout << "The decimal equivalent of " << roman << " is "
      << value << ".\n";

   return 0;
}
