#include <iostream>
#include <string>
#include <list>

using namespace std;

void downsize(list<string>& staff)
{
   list<string>::iterator p = staff.begin();
   p++;
   while (p != staff.end())
   {
      p = staff.erase(p);
      if (p != staff.end()) p++;
   }
}

int main()
{
   list<string> staff;
   staff.push_back("Cracker, Carl");
   staff.push_back("Hacker, Harry");
   staff.push_back("Lam, Larry");
   staff.push_back("Sandman, Susan");

   downsize(staff);
   
   list<string>::iterator pos;
   /* print all values */

   for (pos = staff.begin(); pos != staff.end(); pos++)
      cout << *pos << "\n";

   return 0;
}
