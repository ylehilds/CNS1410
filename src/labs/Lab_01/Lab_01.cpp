// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002
// Professor: Chuck Alisson
// Project: Lab One
// Date Written: 08/25/07
// --------------------------------------

// I declare that the following source code was written 
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am
// found in violation of this policy.
#include <iostream>
#include "class.h"
#include <cassert>  // necessary when using assertions
using namespace std;
double setSales(Employee *pointer) // record sales amount.
{
	assert (pointer != NULL); // test the preconditions
	double sales;
	cout << "Employee name: " << pointer->getname() << endl << "Enter sales for this week: ";
	cin >> sales;
	cout << endl;
	pointer->set_sales(sales);
	assert(pointer->getSales() >=0); // test the postconditions
	return pointer->getSales();
}

int main () // driver main method, creates dynamically an object of the Employee class, call setSales & CalcPay functions and displays the amount to be paid to the employee.
{
	Employee *weeklySales = new Employee("I.M. Great",1000.0,0.4,1,"12 Madison Ave","123-4567",100);
	setSales(weeklySales);
	weeklySales->CalcPay();
	cout << "Pay for " << weeklySales->getname() << " is " << weeklySales->CalcPay() << endl;
	system ("PAUSE");
	
	
return 0;
}

