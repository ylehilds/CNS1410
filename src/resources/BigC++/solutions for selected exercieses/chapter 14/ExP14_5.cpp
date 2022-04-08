#include <iostream>
#include <string>

using namespace std;

/**
   Attempts to locate substring t within string s.
   @param s a string
   @param t a string
   @param n the number of characters previously matched
   @return offset index of first match; otherwise, -1 if not found
*/
int index_of_helper(string s, string t, int n)
{  
   if (t.length() > s.length())
      return -1;
   if (t == s.substr(0, t.length()))
      return n;
   return index_of_helper(s.substr(1, s.length() - 1), t, n + 1);
}

/**
   Attempts to locate substring t within string s
   @param s a string
   @param t a string
   @return index of first match; otherwise, -1 if not found
*/
int index_of(string s, string t)
{  
   return index_of_helper(s, t, 0);
}


int main()
{  
   string s;
   string t;
   cout << "Enter the first string: ";
   cin >> s;
   cout << "Enter the second string: ";
   cin >> t;

   int index = index_of(s, t);

   if (index >= 0)
      cout << "The substring " << t << " was found at position " << index << ".\n";
   else
      cout << "The substring " << t << " was not found in " << s << ".\n";

   return 0;
}
