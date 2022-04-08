#include <iostream>
#include <string>

using namespace std;

/**
   Converts the uppercase characters of a string. 
   @param s the string to convert
   @return s with uppercase characters converted to lowercase
*/
string lowercase(string s)
{
   if (s == "") return s;
   string first = s.substr(0, 1);
   string tail = lowercase(s.substr(1, s.length() - 1));
   string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string lower = "abcdefghijklmnopqrstuvwxyz";
   int i;
   for (i = 0; i < upper.length(); i++)
   {
      if (first == upper.substr(i, 1))
         return lower.substr(i, 1) + tail;
   }
   return first + tail;
}

int main()
{
   while (true)
   {
      string word;
      cin >> word;
      if (cin.fail())
         return 0;
      cout << lowercase(word) << "\n"; 
   }
}
