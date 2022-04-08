#include <iostream>

using namespace std;

#include <string>
#include "ccc_time.h"

int main()
{  
   Time t1 = Time();
   cout << "Type the following sentence as quickly as you can:\n";
   cout << "The quick brown fox jumps over the lazy dog.\n";

   string s;
   getline(cin, s);

   Time t2 = Time();      
   double et = t2.seconds_from(t1);
   cout << "That sentence took you " << et << " seconds to type.";

   return 0;
} 
