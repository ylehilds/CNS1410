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
Salaried::Salaried (int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double weeklySalaryX)
	: Employee(empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX)
{
	weeklySalary = weeklySalaryX;
}
double Salaried::calcSalary()
{
	assert (weeklySalary >= 0);
	double money1 =  weeklySalary - (20.0/100)*weeklySalary - (7.5/100)*weeklySalary - (5.24/100)*weeklySalary;
	assert ( money1 >= 0);
	return money1;
	
}

Sales::Sales (int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double weeklySalaryX, double weeklySalesX, double commissionX)
	: Salaried (empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX, weeklySalaryX)
{
	weeklySales = weeklySalesX;
	commission = commissionX;
}
double Sales::calcSalary()
{
	assert (weeklySales >=0);
	assert(commission >=0);
	if (weeklySalary > weeklySales * commission)
	{
		double money2 =  weeklySalary - (20.0/100)*weeklySalary - (7.5/100)*weeklySalary - (5.24/100)*weeklySalary;
		assert(money2 >= 0);
		return money2;
	}
	else
	{
		double money3 =  weeklySales * commission - (20.0/100)*weeklySales * commission - (7.5/100)*weeklySales * commission - (5.24/100)*weeklySales * commission;
		assert(money3 >= 0);
		return money3;
	}
}

Hourly::Hourly (int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double hourlyRateX, double hoursWorkedX)
	: Employee(empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX)
{
	hourlyRate = hourlyRateX;
	hoursWorked = hoursWorkedX;
}
double Hourly::calcSalary()
{
	assert (hourlyRate >= 0);
	assert (hoursWorked >=0);
	if (hoursWorked > 40)
	{
		double hoursWorkedLessOvertime = 40;
		double overtime = hoursWorked - 40;
		double overtime_money = overtime * hourlyRate*1.5 ;
		double total_amount_money_made = (hoursWorkedLessOvertime*hourlyRate + overtime_money);
		double money4 =  total_amount_money_made - (20.0/100)*total_amount_money_made  - (7.5/100)*total_amount_money_made ;
		assert(money4 >= 0);
		return money4;
	}
	else
	{
		double money5 =  hoursWorked*hourlyRate - (20.0/100)*hoursWorked*hourlyRate - (7.5/100)*hoursWorked*hourlyRate ;
		assert(money5 >= 0);
		return money5;
	}
	

}



PartTime::PartTime (int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double hourlyRateX, double hoursWorkedX, int maxHoursX)
	: Hourly(empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX, hourlyRateX, hoursWorkedX)
{
	maxHours = maxHoursX;
}
double PartTime::calcSalary()
{
	assert(maxHours >=0);
	if (hoursWorked > 25) 
	{
		double hours_paid = 25;
		double money6 =  hours_paid*hourlyRate - (20.0/100)* hours_paid*hourlyRate -(7.5/100)*hours_paid*hourlyRate;
		assert(money6 >= 0);
		return money6;
	}
	else 
	{
		double money7 =  hoursWorked*hourlyRate - (20.0/100)* hoursWorked*hourlyRate -(7.5/100)*hoursWorked*hourlyRate;
		assert(money7 >= 0);
		return money7;

	}

}

Employee::Employee (int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX)
{
	empNumber = empNumberX;
	name = nameX;
	address = addressX;
	phoneNumber = phoneNumberX;
	socialSecurityNumber = socialSecurityNumberX;
}
int Employee :: get_empNumber()
{
	return empNumber;
}
string Employee :: get_address()
{
	return address;
}
string Employee :: get_phoneNumber()
{
	return phoneNumber;
}
string Employee :: get_socialSecurityNumber()
{
	return socialSecurityNumber;
}
string Employee :: get_name()
{
	return name;
}
