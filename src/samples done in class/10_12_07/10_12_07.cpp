#include <iostream>
# include <sstream>
#include <string>
using namespace std; 
string tostring ()
{
	cout << "enter a number" << endl;
	int n;
	cin >> n;
	ostringstream os;
	os << "you entered the number" << n;
	return os;
}

int main{
	
	tostring();
}