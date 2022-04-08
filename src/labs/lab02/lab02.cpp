// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002
// Professor: Charles Allison
// Project: Lab Two
// Date Written: August 29, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.


// string reversal program
// lab #2
// pointer practice
// *************************
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void reverse(char*);

int main ( )
{
	char buffer[80];
	
	cout << "String reversal program";
	cout << "\nType in a short string of words.";
	cout << "\nI will reverse them.";
	cout << "\n";
	cin.getline(buffer, 79);
	
	cout << "\nYou typed " << buffer;
	reverse (buffer);
	cout << "\nReversed: " << buffer;
	
	cout << endl;
	system("PAUSE");
	return 0;
}


void reverse(char* string) // function implementation to reverse the words
// it is basically a swap function that does that only until the middle of the statement
{
	int length = strlen(string);
	char *start = string;
	char *end = string;
	for (int i = 0; i < length ; i++)
	{
		char temp = start[i];
		start[i] = end[length-1];
		end[length-1] = temp;
		length--;
	}
	
// You write this code
}
