// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002   
// Professor: Charles Allison
// Project: Project three
// Date Written: September 15th, 2007
// --------------------------------------

// I declare that the following source code was written 
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
#include "class.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;
int main()
{
	cout << "Student: Lehi Alcantara "  << endl <<"section: 002" <<endl <<"Project Three" << endl <<endl;
	
	Salaried derived1 (1,"Laura Bush", "1600 Pennsylvania Ave.", "(202) 123-4567","511-89-1000", 10000);
	cout << "Employee Number: " << derived1.get_empNumber()<< endl;
	cout << "Name: " << derived1.get_name()<< endl;
	cout << "address: " << derived1.get_address()<< endl;
	cout << "phone: " << derived1.get_phoneNumber()<< endl; 
	cout << "ssn: " << derived1.get_socialSecurityNumber()<< endl;
	cout << fixed << setprecision(2) << "Net Pay: $" << derived1.calcSalary() <<endl << endl;
	
	Sales derived2 (2, "Muffin Man", "34 Drury Lane","(801) 345-9876", "623-90-4567" , 5000.0, 65000.0, 0.4);
	cout << "Employee Number: " << derived2.get_empNumber()<< endl;
	cout << "Name: " << derived2.get_name()<< endl;
	cout << "address: " << derived2.get_address()<< endl;
	cout << "phone: " << derived2.get_phoneNumber()<< endl;
	cout << "ssn: " << derived2.get_socialSecurityNumber()<< endl;
	cout << fixed << setprecision(2) << "Net Pay: $" << derived2.calcSalary()<< endl << endl;
	
	Hourly derived3 (3, "Tony Blair", "27 Downing Street" ,"1-44-345-8765", "512-90-5454", 34.50, 50.0 );
	cout << "Employee Number: " << derived3.get_empNumber()<< endl;
	cout << "Name: " << derived3.get_name()<< endl;
	cout << "address: " << derived3.get_address()<< endl;
	cout << "phone: " << derived3.get_phoneNumber()<< endl;
	cout << "ssn: " << derived3.get_socialSecurityNumber()<< endl;
	cout << fixed << setprecision(2) <<"Net Pay: $" << derived3.calcSalary() <<endl << endl;
	
	PartTime derived4 (4, "Mephistopheles" , "7734 Upside Down Street" ,"(914) 212-2287",  "512-63-5151", 22.0, 30.0, 25 );
	cout << "Employee Number: " << derived4.get_empNumber()<< endl;
	cout << "Name: " << derived4.get_name()<< endl;
	cout << "address: " << derived4.get_address()<< endl;
	cout << "phone: " << derived4.get_phoneNumber()<< endl;
	cout << "ssn: " << derived4.get_socialSecurityNumber()<< endl;
	cout << fixed << setprecision(2) <<"Net Pay: $" << derived4.calcSalary() <<endl << endl;
	system("PAUSE");
	return 0;
}
