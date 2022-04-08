// File: proj03.cpp
// Instructor: Chuck Allison
// Course: CNS 1410 Section: 002
// Project: Project Three
// Date: September 18, 2007

// I declare that the following source code was written 
// solely by me. I understand that copying any source 
// code, in whole or in part, constitutes cheating, and 
// that I will receive a zero on this project if I am 
// found in violation of this policy. 

// _____________________________________

//------------------------------------------------------

//using namespace std;
#include "proj12.h"
#include <vector>
Employee::Employee()
{
	empNumber = 0;
	name = "";	
	address = "";
	phoneNumber = "";
	title = "";
}
Employee::Employee(int empN, string n, string addr, string phoneN, string t)
{
	empNumber = empN;
	name = n;
	address = addr;
	phoneNumber = phoneN;
	title = t;
}
Employee::~Employee()
{
}
void Employee::readData(ifstream& theFile)
{
	string garbage;
	theFile >> empNumber;
	getline(theFile, garbage, '\n');
	getline(theFile, name, '\n');
	getline(theFile, address, '\n');
	getline(theFile, phoneNumber, '\n');
	getline(theFile, title, '\n');
}
void Employee::writeData(ofstream& theFile)
{
	theFile << "Employee Number: " << empNumber << "\nName: " << name << "\nAddress: " << address << "\nPhone Number: "
	<< phoneNumber << "\nTitle: " << title;
}
int Employee::getEmpNumber()
{
	return empNumber;
}
void Employee::setEmpNumber(int n)
{
	empNumber = n;
}
string Employee::getAddress()
{
	return address;
}
void Employee::setAddress(string a)
{
	address = a;
}
string Employee::getPhoneNumber()
{
	return phoneNumber;
}
void Employee::setPhoneNumber(string pn)
{
	phoneNumber = pn;
}
string Employee::getName()
{
	return name;
}
void Employee::setName(string n)
{
	name = n;
}
string Employee::getTitle()
{
	return title;
}
Salaried::Salaried()
{
	salary = 0;
}
Salaried::Salaried(int empN, string n, string addr, string phoneN, string t,  double ws)
	:Employee(empN, n, addr, phoneN, t)
	{
		salary = ws;
	}
Salaried::~Salaried()
{
}
int Salaried::getType()
{
	return 1;
}
void Salaried::readData(ifstream& theFile)
{
	string garbage;
	Employee::readData(theFile);
	theFile >> salary;	
}
void Salaried::writeData(ofstream& theFile)
{
	Employee::writeData( theFile );
	theFile << "\nNet Pay: " << calcSalary() << endl << endl;
}
double Salaried::calcSalary()
{
	double fedTaxDeduction = (salary * FEDTAX);
	double stateTaxDeduction = (salary * STATETAX);
	double salBenDeduction = (salary * SALARIEDBENIFITS);
	return (salary - fedTaxDeduction - stateTaxDeduction - salBenDeduction);
}
double Salaried::getSalary()
{
	return salary;
}
void Salaried::setSalary(double ws)
{
	salary = ws;
}
Sales::Sales()
{
	amount = 0;
	commission = 0;
}
Sales::Sales(int empN, string n, string addr, string phoneN, string t, double ws, double c)
	:Salaried(empN, n, addr, phoneN, t, ws)
	{
		amount = 0;
		commission = c;
	}
	
Sales::~Sales()
{
}
int Sales::getType()
{
	return 2;
}
void Sales::readData(ifstream& theFile)
{
	string garbage;
	Salaried::readData(theFile);	
	theFile >> commission;
	getline(theFile, garbage, '\n');	
}
void Sales::writeData(ofstream& theFile)
{
	Employee::writeData( theFile );
	theFile << "\nNet Pay: " << calcSalary() << endl << endl;
}
double Sales::calcSalary()
{
	double salesCommission = amount * commission;
	
	if (salary > salesCommission)
	{
		double fedTaxDeduction = (salary * FEDTAX);
		double stateTaxDeduction = (salary * STATETAX);
		double salBenDeduction = (salary * SALARIEDBENIFITS);
		return (salary - fedTaxDeduction - stateTaxDeduction - salBenDeduction);
	}
	else
	{
		double fedTaxDeduction = (salesCommission * FEDTAX);
		double stateTaxDeduction = (salesCommission * STATETAX);
		double salBenDeduction = (salesCommission * SALARIEDBENIFITS);
		return salesCommission - fedTaxDeduction - stateTaxDeduction - salBenDeduction;
	}
}
double Sales::getAmount()
{
	return amount;
}
void Sales::setAmount(double ws)
{
	amount = ws;
}
double Sales::getCommission()
{
	return commission;
}
void Sales::setCommission(double c)
{
	commission = c;
}
Hourly::Hourly()
{
	hourlyRate = 0;
	hoursWorked = 0;
}
Hourly::Hourly(int empN, string n, string addr, string phoneN, string t, double hr)
	:Employee(empN, n, addr, phoneN, t)
	{
		hourlyRate = hr;
		hoursWorked = 0;
	}
	
Hourly::~Hourly()
{
}
int Hourly::getType()
{
	return 3;
}
void Hourly::readData(ifstream& theFile)
{
	string garbage;
	Employee::readData(theFile);
	
	theFile >> hourlyRate;
	getline(theFile, garbage, '\n');
}
void Hourly::writeData(ofstream& theFile)
{
	Employee::writeData( theFile );
	theFile << "\nNet Pay: " << calcSalary() << endl << endl;
}
double Hourly::calcSalary()
{
	double fullTime = 40;
	if(hoursWorked <= fullTime)
	{
		double wagePay = hourlyRate * hoursWorked;
		double fedTaxDeduction = (wagePay * FEDTAX);
		double stateTaxDeduction = (wagePay * STATETAX);
		return (wagePay - fedTaxDeduction - stateTaxDeduction);
	}
	else
	{
		double timePlusHalf = hourlyRate * 1.5;
		double regular = 40;
		double overTime = hoursWorked - 40;
		double overTimePay = (hourlyRate * regular) + (overTime * timePlusHalf);
		double fedTaxDeduction = (overTimePay * FEDTAX);
		double stateTaxDeduction = (overTimePay * STATETAX);
		return (overTimePay - fedTaxDeduction - stateTaxDeduction);
	}
}
double Hourly::getHourlyRate()
{
	return hourlyRate;
}
void Hourly::setHourlyRate(double hr)
{
	hourlyRate = hr;
}
double Hourly::getHoursWorked()
{
	return hoursWorked;
}
void Hourly::setHoursWorked(double hw)
{
	hoursWorked = hw;
}
void Hourly::plusSetHoursWorked(double hw)
{
	hoursWorked += hw;
}
void printEmp(ofstream& writer, Employee* e)
{
	if(dynamic_cast<Salaried*>(e))
	{
		e->writeData(writer);
	}
	else if(dynamic_cast<Sales*>(e))
	{
		e->writeData(writer);
	}
	else if(dynamic_cast<Hourly*>(e))
	{
		e->writeData(writer);
	}
}
Employee* readEmp(ifstream& read)
{
	string garbage;
	Employee* emp;
	if(read.good())
	{
		int identify = 0;
		read >> identify;
		getline(read, garbage, '\n');
		switch(identify)
		{
		case 1:
			{
				Employee* newEmp = new Salaried();
				newEmp->readData(read);
				emp = newEmp;
				break;
			}
		case 2:
			{
				Employee* newEmp = new Sales();
				newEmp->readData(read);
				emp = newEmp;
				break;
			}
		case 3:
			{
				Employee* newEmp = new Hourly();
				newEmp->readData(read);
				emp = newEmp;
				break;
			}
		}
	}
	return emp;
}
int getMinsFromMid(int hour, int min, char AorP)
{
	int minInHour = 60;
	int twelveHours = 720;
	int minsFromMid = 0;
	minsFromMid = (hour * minInHour) + min;
	if(AorP == 'p')
	{
		return minsFromMid += twelveHours;
	}
	else
		return minsFromMid;
}
double getHours(ifstream& read)
{
	string garbage;
	int SThour, STmin, EThour, ETmin, begMinFromMid, endMinFromMid, minsWorked;
	double timeWorked;
	char begAorP, endAorP;
	read >> SThour >> STmin >> begAorP >> EThour >> ETmin >> endAorP;
	getline(read, garbage, '\n');
	//convert hours to total minutes
	begMinFromMid = getMinsFromMid(SThour, STmin, begAorP);
	endMinFromMid = getMinsFromMid(EThour, ETmin, endAorP);
	minsWorked = endMinFromMid - begMinFromMid;
	timeWorked = static_cast<double>(minsWorked) / 60;
	return timeWorked;
}
void assignHours(ifstream& read, vector<Employee*> group)
{
	int empNum;
	double hours;
	Hourly* hourlyPtr;
	int i = 0;
	read >> empNum;
	hours = getHours(read);
	if(read.good())
	{
		while(group[i]->getEmpNumber() != empNum)
		{
			++i;
		}
	}
	hourlyPtr = dynamic_cast<Hourly*>(group[i]);
	if(hourlyPtr != 0)
		hourlyPtr->plusSetHoursWorked(hours);
}
double getAmount(ifstream& read)
{
	string garbage;
	double amount;
	read >> amount;
	getline(read, garbage, '\n');
	return amount;
}
void assignAmount(ifstream& read, vector<Employee*> group)
{
	int empNum;
	double amount;
	Sales* salesPtr;
	int i = 0;
	read >> empNum;
	amount = getAmount(read);
	if(!read.eof())
	{
		while(group[i]->getEmpNumber() != empNum)
		{
			++i;
		}
	}
	salesPtr = dynamic_cast<Sales*>(group[i]);
	if(salesPtr != 0)
		salesPtr->setAmount(amount);
}
