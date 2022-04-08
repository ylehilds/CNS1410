// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002   
// Professor: Charles Allison
// Project: Project Four
// Date Written: September 22nd, 2007 
// -------------------------------------- 

// I declare that the following source code was written 
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
#include "class.h"
#include <string>
#include <iomanip>
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
void printCheck(Employee* pointer)
{
	cout << "Employee Number: " << pointer->get_empNumber()<< endl;
	cout << "Name: " << pointer->get_name()<< endl;
	cout << "address: " << pointer->get_address()<< endl;
	cout << "phone: " << pointer->get_phoneNumber()<< endl; 
	cout << "ssn: " << pointer->get_socialSecurityNumber()<< endl;
	cout << fixed << setprecision(2) << "Net Pay: $" << pointer->calcSalary() <<endl << endl;
}
void doPayroll(vector <Employee*>& E1)
{
	for (int i=0; i<E1.size(); i++)
	{
		printCheck (E1[i]);
	}

}

int main()
{
	system("TITLE Polymorphism Project");
	system("COLOR E");
	cout << "Student: Lehi Alcantara "  << endl <<"section: 002" <<endl <<"Project Four" << endl <<endl;
	vector <Employee*> E1;
	
	Employee* derived1 = new Salaried (1,"Laura Bush", "1600 Pennsylvania Ave.", "(202) 123-4567","511-89-1000", 10000);
	E1.push_back(derived1);
		
	Employee* derived2 = new Sales (2, "Muffin Man", "34 Drury Lane","(801) 345-9876", "623-90-4567" , 5000.0, 65000.0, 0.4);
	E1.push_back(derived2);
		
	Employee* derived3 = new Hourly (3, "Tony Blair", "27 Downing Street" ,"1-44-345-8765", "512-90-5454", 34.50, 50.0 );
	E1.push_back(derived3); 
	
	Employee* derived4 = new PartTime (4, "Mephistopheles" , "7734 Upside Down Street" ,"(914) 212-2287",  "512-63-5151", 22.0, 30.0, 25 );
	E1.push_back (derived4);
	
	ofstream write;
	write.open("c://data.txt");
	for (int i=0; i<E1.size(); i++)
	{
		E1[i]->writeData(write);
		write << endl;
	}
	
	write.close();
  //if (write.is_open() == false)
  //{
	//  cout << "the close file worked";
  //}
	E1.clear();
	delete derived1;
	delete derived2;
	delete derived3;
	delete derived4;
	ifstream read;
	read.open("c://data.txt");
	Employee* pointer;
	while (read)
	{
		int type;
		read >> type;
		if (!read)// data validation, to check for any bad data
		{
			//cout << "end of file reached";
			break;
		}
		switch (type)
		{
		case 1:
			pointer =new Salaried();
			break; 
		case 2:
			pointer = new Sales();
			break;
		case 3:
			pointer =new Hourly();
			break;
		case 4:
			pointer =new PartTime();
			break;
		}
		pointer->readData(read);
		E1.push_back(pointer);
	}
	doPayroll(E1);
	for (int i=0; i<E1.size(); i++)
	{
		delete E1[i]; 
	}
	//if (read.is_open() == true)
  //{
	//  cout << "the opening file worked";
  //}
	
	system("PAUSE");
	return 0;
}

