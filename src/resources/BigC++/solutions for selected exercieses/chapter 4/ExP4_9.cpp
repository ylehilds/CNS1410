#include <iostream>
#include <string>

using namespace std;

int main()
{  
   cout <<  "Do you want to continue: ";
   string input;
   getline(cin, input);
   bool ok = false;
   if (input == "y")
      cout <<  "Ok\n";
   else if (input == "Y")
      cout <<  "Ok\n";
   else if (input == "yes")
      cout <<  "Ok\n";
   else if (input == "Yes")
      cout <<  "Ok\n";
   else if (input == "OK")
      cout <<  "Ok\n";
   else if (input == "Ok")
      cout <<  "Ok\n";
   else if (input == "ok")
      cout <<  "Ok\n";
   else if (input == "Sure")
      cout <<  "Ok\n";
   else if (input == "sure")
      cout <<  "Ok\n";
   else if (input == "SURE")
      cout <<  "Ok\n";
   else if (input == "Why Not?")
      cout <<  "Ok\n";
   else if (input == "why not?")
      cout <<  "Ok\n";
   else if (input == "WHY NOT?")
      cout <<  "Ok\n";
   else if (input == "N")
      cout <<  "Terminating\n";
   else if (input == "n")
      cout <<  "Terminating\n";
   else if (input == "No")
      cout <<  "Terminating\n";
   else if (input == "no")
      cout <<  "Terminating\n";
   else
      cout << "Bad input\n"; 
       
   return 0;
}

