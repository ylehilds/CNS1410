#include <iostream>
#include <string>

using namespace std;

namespace Cay_S_Horstmann_4089245085
{
   bool isvowel(char c)
   {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o'
         || c == 'u';
   }

   void cin(string& s)
   {
      string r;
      for (int i = 0; i < s.length(); i++)
      {
         if (!isvowel(s[i])) r = r + s.substr(i, 1);
      }
      s = r;
   }
   
   void cout(string& s)
   {
      string r;
      for (int i = 0; i < s.length(); i++)
      {
         if (isvowel(s[i])) r = r + s.substr(i, 1);
      }
      s = r;
   }
}

namespace csh = Cay_S_Horstmann_4089245085;

int main()
{
   string s;
   std::cout << "Enter a string: ";
   getline(std::cin, s);
   string t = s;
   csh::cin(s);
   std::cout << s << "\n";
   csh::cout(t);
   std::cout << t << "\n";
   return 0;
}
