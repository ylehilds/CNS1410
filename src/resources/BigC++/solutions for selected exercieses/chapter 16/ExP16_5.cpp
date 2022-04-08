#include <string>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   list<string> staff;
   staff.push_back("Harry");
   staff.push_back("Vivian");
   staff.push_back("Zack");
   staff.push_back("Sam");
   staff.push_back("Dick");

   cout << "The maximum element in the list is " << *max_element(staff.begin(), staff.end()) << "\n";

   return 0;
}
