// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002   
// Professor: Charles Allison
// Project: Project Five
// Date Written: September 29, 2007 
// --------------------------------------

// I declare that the following source code was written 
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.

#include <iostream>
#include <string>
using namespace std;
  
// Purpose: figure out if there is a string2 in string1
// Parameters: 2 strings and 1 integer
// Returns: the result if there a a string2 in string 1
// Pre-conditions: none 
// Post-conditions: none 
int helper(string s,string t,int index)
{
int size = t.length();
 if ( s.size() < t.size())
  {
  return -1;  
  }
 if (s.compare (0, size, t) == 0)
 {
	 return index;
 }
 return helper(s.substr(1,s.size()),t,index+1);
}
// Purpose: calls the helper function
// Parameters: 2 strings
// Returns: the result from helper if there a a string2 in string 1
// Pre-conditions: none 
// Post-conditions: none 
int index_of(string s, string t) 
{
	return helper(s,t,0);
}
  
int main() 

{
 system("title Lehi's String characters comparison proram");
 system("color e");
 cout << "Please input a string : "; 
 string s;
 getline(cin, s);
 cout << "Please input another string for comparison: ";
 string t; 
 getline(cin,t);
 if (index_of(s,t) >= 0)
 cout << endl << "The 2nd string was found in string 1 at position: " << index_of(s,t) << endl;
 else
	cout << endl << "The 2nd string was not found in string 1" << endl;
 system("PAUSE");
 return 0;
}

