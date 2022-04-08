#include <iostream>
#include <string>

using namespace std;

int main()
{  
   cout << "Hello, My name is Hal!\n";
   cout << "What would you like me to do?\n";
   string user_input;
   getline(cin, user_input);
   cout << "I am sorry, I cannot do that.";
   return 0;
}
