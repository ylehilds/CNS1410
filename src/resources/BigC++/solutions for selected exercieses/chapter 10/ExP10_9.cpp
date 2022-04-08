#include <iostream>

/**
   Computes the length of the prefix of a string that is
   composed of characters in a given set.
   @param s the string whose maximum prefix is to be found
   @param t the string whose characters are to be contained
   in the prefix
   @return the length of the prefix of s consisting of 
   characters of t (in any order)
*/
int strspn(const char s[], const char t[])
{
   int n = 0;
   while (*s != '\0')
   {
      const char* p = t;
      while (*p != *s && *p != '\0') p++;
      if (*p == 0) // no match
         return n;
      n++;
      s++;
   }
   return n;
}

int main()
{
   cout << strspn("mississippi", "ims") << "\n";
}
