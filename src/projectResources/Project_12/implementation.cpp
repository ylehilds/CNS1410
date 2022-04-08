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
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Salaried::Salaried()
{
	datatype =1;
}
Salaried::Salaried (int empTypeX, int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double weeklySalaryX)
	: Employee(empTypeX, empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX)
{
	weeklySalary = weeklySalaryX;
	datatype = 1;
}

double Salaried::calcSalary()
{
	assert (weeklySalary >= 0);
	double money1 =  weeklySalary - (20.0/100)*weeklySalary - (7.5/100)*weeklySalary - (5.24/100)*weeklySalary;
	assert ( money1 >= 0);
	return money1;
	
}
Sales::Sales()
{
	datatype=2;
}
Sales::Sales (int empTypeX, int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double weeklySalaryX, double commissionX)
	: Salaried (empTypeX, empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX, weeklySalaryX)
{
	commission = commissionX;
	datatype=2;
}
double Sales::calcSalary()
{
	//assert (weeklySales >=0);
	assert(commission >=0);
	//if (weeklySalary > weeklySales * commission)
	//{
		//double money2 =  weeklySalary - (20.0/100)*weeklySalary - (7.5/100)*weeklySalary - (5.24/100)*weeklySalary;
		//assert(money2 >= 0);
		//return money2;
	//}
	//else
	//{
		//double money3 =  weeklySales * commission - (20.0/100)*weeklySales * commission - (7.5/100)*weeklySales * commission - (5.24/100)*weeklySales * commission;
		//assert(money3 >= 0);
		//return money3;
	//}
}
Hourly::Hourly()
{
	datatype=3;
}
Hourly::Hourly (int empTypeX, int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX, double hourlyRateX)
	: Employee(empTypeX, empNumberX,nameX, addressX, phoneNumberX, socialSecurityNumberX)
{
	hourlyRate = hourlyRateX;
	datatype=3;
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


Employee::Employee()
{
}
Employee::Employee (int empTypeX, int empNumberX,string nameX, string addressX, string phoneNumberX, string socialSecurityNumberX)
{
	empType = empTypeX;
	empNumber = empNumberX;
	name = nameX;
	address = addressX;
	phoneNumber = phoneNumberX;
	socialSecurityNumber = socialSecurityNumberX;
	
}
int Employee :: get_empType()
{
	return empType;
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


void Employee ::writeData(ofstream& write ) 
{
	write << datatype << endl << empNumber <<  endl <<name <<  endl << address<<  endl <<phoneNumber << endl << socialSecurityNumber;
}
void Salaried ::writeData(ofstream& write )  
{
	this->Employee::writeData(write);
	write << endl << weeklySalary ;
}
void Sales ::writeData(ofstream& write ) 
{
	this->Salaried::writeData(write);
	write << endl << weeklySales << endl << commission ;
}
void Hourly ::writeData(ofstream& write ) 
{
	this->Employee::writeData(write);
	write << endl << hoursWorked << endl << hourlyRate;

}

void Employee ::readData(ifstream& read ) 
{
	read >> empNumber; 
	read.ignore(80, '\n');
	getline(read,name);
	getline (read,address);
	getline(read,phoneNumber);
	getline(read,socialSecurityNumber);
}
void Salaried ::readData(ifstream& read )  
{
	this->Employee::readData(read);
	read >> weeklySalary ;
}
void Sales ::readData(ifstream& read ) 
{
	this->Employee::readData(read);
	read >> weeklySales >> commission ;
}
void Sales ::readDatasales(ifstream& readsales ) 
{
	this->Salaried::readData(readsales);
	readsales >> weeklySales;
}
void Hourly ::readData(ifstream& read ) 
{
	this->Employee::readData(read);
	read >> hoursWorked;

}



