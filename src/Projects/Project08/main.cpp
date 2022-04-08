// File Prologue
// Author: Lehi Alcantara 
// Course: CNS 1410
// section: 002       
// Professor: Charles Allison
// Project: Project Eight
// Date Written: October 29th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
// P.S. -> Professor Allison gave us the skeleton of this code.

#include <iostream>
#include "stack.h"
using namespace std;
void sum (Stack ); 
int main() { 
	system ("TITLE LEHI ALCANTARA'S PROJECT 08 - CNS 1410");
	system("COLOR E");
	cout << "Stack print out: " << endl;
	//array of 12 integers
	int p[12];
	  for (int i = 0; i < 12; ++i)
        p[i]=i+1;
	  for (int i = 0; i < 12; ++i)
        cout << p[i] << endl;
	
//------------------------------------------------------------------------------------------------------------------------	  
	system("PAUSE");
	cout << "display Pushing data from array to Stack object and then remove data from stack:";
	Stack a;
	for (int i = 0; i < 12; ++i)
        a.push(p[i]);
	for (int i = 0; i < 12; ++i)
	  {
	  cout << a.top() << endl;
	  a.pop();
	  }
//-------------------------------------------------------------------------------------------------------------------------	
// reload the Stack into stack object a
    for (int i = 0; i < 12; ++i)
        a.push(p[i]);
//-------------------------------------------------------------------------------------------------------------------------
//make a copy from stack object a into stack object b and then display the top part and decrement the count
	system("PAUSE");
	cout << "display the contents of a copy from one stack object to another stack object: " << endl;
	Stack b = a;
	int w =b.size();
    for (int i = 0; i < w; ++i)
		{cout << b.top() << endl;
		  b.pop(); 
		} 
//-----------------------------------------------------------------------------------------------------------------------
// sum of the integers from the Stack.
	system("PAUSE");
	cout << endl << "display the sum of integers from a stack object: " << endl;
	sum(a);
		system("PAUSE");
	return 0;
//---------------------------------------------------------------------------------------------------------------------
}
//------------------------------------------------------------------------------------------------------------------------
// standalone function to sum the integers from the stack
void sum (Stack a)
{
	int z=0;
	int q =a.size();
	for (int i = 0; i < q; ++i)
	  {
	 z += a.top();
	  a.pop();
	}
	cout<< "the sum is : " <<  z << endl;
}