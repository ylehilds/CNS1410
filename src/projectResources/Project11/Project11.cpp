#include <iostream>
#include<fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{ 
	ifstream file; 
	string input;
		while (input != "c:\hourly.txt")
		{
			cout << "Enter the file name for hourly employee data: ";
			cin >> input;
			file.open('c:\hourly.txt.c_str()');
			if (!file)
			{
				cout << "file was not opened" << endl;
			}
			else
			{
				cout << "file was opened" << endl;
			}
		}

	system("PAUSE");
	return 0;
	
}
