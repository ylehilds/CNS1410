#include "class.h"
Employee::Employee(string x, double a, double b, double c, string d, string h, double e)//parameterized constructor that initializes all employee information.
{
	empNumber = c;
	address = d;
	phoneNumber = h;
	deptNumber=e;
	name = x;
	weeklySalary = a; 
	commission = b;
}

void Employee :: set_sales(double sale) // setter
{
	sales = sale;
}
string Employee::getname() // getter
{
	return name;
}
double Employee :: getSales() // getter
{
	return sales;
}
double Employee :: CalcPay() // calculates the amount to be paid to employee
{
	double Pay, calculation;
	assert(sales >=0); // test the preconditions
	if (sales > 2500)
	{
		calculation = sales * commission;
		Pay = calculation;
		//assert(Pay == calculation);
		assert(Pay != 0); // test the postconditions
	}
	else if (sales <=2500)
	{
		Pay = weeklySalary;
		//assert(Pay == weeklySalary);
		assert(Pay != 0); // test the postconditions
	}
	return Pay;
}
