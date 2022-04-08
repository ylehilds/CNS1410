// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 
// Professor:  
// Project: Lab One
// Date Written: 
// --------------------------------------

// I declare that the following source code was written 
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.
#include <iostream>
#include "class.h"
#include <cassert> 
using namespace std;
string Employee::getname( )
{
	return name;
}
double Employee :: CalcPay(double money_made)
{
	assert(money_made >=0);
	//assert(money_made == 'a'|| money_made == 'b'|| money_made == 'c'|| money_made == 'd'|| money_made == 'e'|| money_made == 'f'|| money_made == 'g'|| money_made == 'h'|| money_made == 'i'|| money_made == 'j'|| money_made == 'k'|| money_made == 'l'|| money_made == 'm'|| money_made == 'n'|| money_made == 'o'|| money_made == 'p'|| money_made == 'q'|| money_made == 'r'|| money_made == 's'|| money_made == 't'|| money_made == 'u'|| money_made == 'v'|| money_made == 'x'|| money_made == 'y'|| money_made == 'w'|| money_made == 'z' || money_made == 'A'|| money_made == 'B'|| money_made == 'C'|| money_made == 'D'|| money_made == 'E'|| money_made == 'F'|| money_made == 'G'|| money_made == 'H'|| money_made == 'I'|| money_made == 'J'|| money_made == 'K'|| money_made == 'L'|| money_made == 'M'|| money_made == 'N'|| money_made == 'O'|| money_made == 'P'|| money_made == 'Q'|| money_made == 'R'|| money_made == 'S'|| money_made == 'T'|| money_made == 'U'|| money_made == 'V'|| money_made == 'X'|| money_made == 'Y'|| money_made == 'W'|| money_made == 'Z');
	if (money_made > 2500.0)
	{
		return money_made * commission;
	}
	if (money_made <=2500)
	{
		return weeklySalary;
	}
}

double setSales(Employee *pointer)
{
	assert (pointer != NULL);
	double sales;
	cout << "Employee name: " << pointer->getname() << endl << "Enter sales for this week: ";
	cin >> sales;
	cout << endl;
	cout << "Pay for " << pointer->getname() << " is " << pointer->CalcPay(sales) << endl;
}
Employee::Employee(string x, double a, double b, double c, string d, string h, double e)
{
	empNumber = c;
	address = d;
	phoneNumber = h;
	deptNumber=e;
	name = x;
	weeklySalary = a; 
	commission = b;
}

int main () 
{
	Employee *weeklySales = new Employee("I.M. Great",1000.0,0.4,1,"12 Madison Ave","123-4567",100);
	setSales(weeklySales);
	system ("PAUSE");
	
	
return 0;
}

