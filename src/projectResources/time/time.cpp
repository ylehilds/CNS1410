#include "time.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main ( )
{
	Atime t1(2, 5, 3);
	cout << "\nhours = " << t1.getHours( );
	cout << "\nminutes = " << t1.getMinutes( );
	cout << "\nseconds = " << t1.getSeconds( );
	cout << endl;
	cout << t1;
	cout << endl;
	cout << setfill('0') << setw(2) <<t1[0] << ":" << t1[1] << ":" << t1[2] << endl;
	
	Atime t2(3, 5, 3);
	if (t1 == t2)
		cout << "\nTime t1 is equal to time t2...\n";
	else
		cout << "\nTime t1 is not equal to time t2...\n";
	
	Atime t3 = t2 - t1;
	cout << t3 << endl;
	
	
	system("PAUSE");
	return 0;
}

