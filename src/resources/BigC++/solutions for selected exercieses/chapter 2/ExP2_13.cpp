#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{  
   cout << "Please enter an integer between 1,000 and 999,999: "; 
   string num; 
   cin >> num; 

   int length = num.length();

   /* 
      The thousands portion is extracted
      by looking at the first length-4 characters. 
      The rest of the number starts at position 
      length-3 in the string.
   */

   string thousands = num.substr(0, length - 4);
   string remainder = num.substr(length - 3, 3);

   cout << thousands << remainder << "\n"; 

   return 0; 
} 
  
