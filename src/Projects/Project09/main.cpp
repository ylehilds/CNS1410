// File Prologue
// Author: Lehi Alcantara 
// Course: CNS 1410 
// section: 002          
// Professor: Charles Allison
// Project: Project Nine 
// Date Written: November 2nd, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.


#include <iostream> 
#include "stack.h"
using namespace std;
void sum (Stack ); 
int main() {  
	system ("TITLE LEHI ALCANTARA'S PROJECT 09 - CNS 1410");
	system("COLOR E");
	cout << "Student: Lehi Alcantara "  << endl <<"section: 002" <<endl <<"Project Nine" << endl <<endl;
	int counter =0;
	Stack a;
    cin.exceptions (ios::badbit | ios::failbit);
 	int input;
	do
   { 
	  try 
      {
		cout << "Enter an integer value, or 0 to quit: ";
		cin >> input;
		a.push(input);
		++counter;
	  }
      catch (ios_base::failure e)
      {
          cin.clear ( );
          cin.ignore (80, '\n'); 
          cout << "You typed an invalid integer\n";
       }
		catch(...)
		{
			cout << "something happened" << endl;
		}
   } while ( input != 0);


	cout << "removing data from the stack: " << endl;
	 try
       {
		for (int i = 0; i < counter; ++i)
	  {
	  cout << a.top() << endl;
	  a.pop();
	  }
        }
        catch ( EmptyStackException& e)
        {
			cout << e.what( );
		} 
		catch(...)
		{
			cout << "something happened" << endl;
		}
	 try
       {
		a.top();
	   }
	 catch ( EmptyStackException& e)
        {
			cout << e.what( );
		} 
	 catch(...)
		{
			cout << "something happened" << endl;
		}
	 
		 try
       {
		a.pop();
	   }
	 catch ( EmptyStackException& e)
        {
			cout << e.what( );
		} 
	 catch(...)
		{
			cout << "something happened" << endl;
		}
	system("PAUSE");
	return 0;

}
