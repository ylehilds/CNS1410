#include <iostream>
#include <fstream>
#include "class.h"
using namespace std;
int main ()
{
	system("title Lehi read and write test");
	system("color e");
	ofstream test;
	test.open("c:/test.txt");
	test << "I'm the best" << endl  << "Oh, yeah!";
	ifstream read;
	read.open("c:/test.txt");
	string x, y;
	getline(read ,x);
	read.ignore();
	getline (read , y);
	cout << x << y;
	return 0;
}