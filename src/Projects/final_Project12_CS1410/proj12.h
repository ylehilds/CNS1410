// File: proj03.h
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

#ifndef PROJ03_H
#define PROJ03_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const double FEDTAX = 0.2;
const double STATETAX = .075;
const double SALARIEDBENIFITS = .0524;

using namespace std;

class Employee
{
protected:
	int empNumber;
	string name;
	string address;
	string phoneNumber;
	string title;
	
public:
	Employee();
	// Employee
	// Purpose: Constuctor 
	// Parameters: int, string, string, string, string
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	Employee(int, string, string, string, string);
	
	virtual ~Employee();
	
	virtual int getType() = 0;
	
	virtual void readData(ifstream&);
	virtual void writeData(ofstream&);
	
	// CalcSalary
	// Purpose: To calculate an employee's pay
	// Parameters: None
	// Returns: double
	// Pre-conditions: None
	// Post-conditions: None
	virtual double calcSalary() = 0;
	
	int getIdentifier();
	void setIdentifier(int);
	
	// getEmpNumber
	// Purpose: To access an employee's number
	// Parameters: None
	// Returns: int
	// Pre-conditions: None
	// Post-conditions: None
	int getEmpNumber();
	
	// setEmpNumber
	// Purpose: To change an employeee's number
	// Parameters: int
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setEmpNumber(int);
	
	// getAddress
	// Purpose: To access an employee's address
	// Parameters: None
	// Returns: string
	// Pre-conditions: None
	// Post-conditions: None
	string getAddress();
	
	// setAddress
	// Purpose: To change an employee's address
	// Parameters: string
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setAddress(string);
	
	// getPhoneNumber
	// Purpose: To access an employee's Phone number
	// Parameters: None
	// Returns: string
	// Pre-conditions: None
	// Post-conditions: None
	string getPhoneNumber();
	
	// setPhoneNumber
	// Purpose: To change an employee's phone number
	// Parameters: string
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setPhoneNumber(string);
	
	// getName
	// Purpose: To access an employee's name
	// Parameters: None
	// Returns: string
	// Pre-conditions: None
	// Post-conditions: None
	string getName();
	
	// setName
	// Purpose: To change an employee's name
	// Parameters: string
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setName(string);	
	string getTitle();
};
class Salaried : public Employee
{
protected:
	double salary;
public:
	Salaried();
	// Salaried
	// Purpose: Constructor
	// Parameters: int, string, string, string, string, double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	Salaried(int, string, string, string, string, double);
	
	~Salaried();
	
	int getType();
	
	// calcSalary
	// Purpose: To calculate an employee's pay
	// Parameters: 
	// Returns: 
	// Pre-conditions: None
	// Post-conditions: None
	double calcSalary();
	
	// readData
	// Purpose: read data from an ifstream and assign data members
	// Parameters: ifstream&
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void readData(ifstream&);
	
	// writeData
	// Purpose: write data to file through a ofstream
	// Parameters: ofstream&
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void writeData(ofstream&);
	
	// getSalary
	// Purpose: To access the Salary attribute
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	double getSalary();
	
	// setSalary
	// Purpose: to change the Salary attribute
	// Parameters: double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setSalary(double);
};
class Sales : public Salaried
{
protected:
	double amount;
	double commission;
public:
	
	// Sales
	// Purpose: defalut constructor
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	Sales();
	
	// Sales
	// Purpose: constructor
	// Parameters: int, string, string, string, string, double, double, double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	Sales(int, string, string, string, string, double, double);
	
	// ~Sales
	// Purpose: destructor
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	~Sales();
	
	// getType
	// Purpose: accesses a number that identifies an object
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	int getType();
	
	// readData
	// Purpose: To read information from a file and assign it to data attributes
	// Parameters: ifstream
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void readData(ifstream&);
	
	// writeData
	// Purpose: To write data to a file
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void writeData(ofstream&);
	
	// calcSalary
	// Purpose: To calculate an employee's pay
	// Parameters: None
	// Returns: double
	// Pre-conditions: None
	// Post-conditions: None
	double calcSalary();
	
	// getAmount
	// Purpose: To access an employee's amount
	// Parameters: None
	// Returns: double
	// Pre-conditions: None 
	// Post-conditions: None
	double getAmount();
	
	// setAmount
	// Purpose: To change an employee's amount
	// Parameters: double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setAmount(double);
	
	// getCommission
	// Purpose: To access an employee's commission
	// Parameters: None
	// Returns: double
	// Pre-conditions: None
	// Post-conditions: None
	double getCommission();
	
	// setCommission
	// Purpose: To change an employee's commission
	// Parameters: double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setCommission(double);
};
class Hourly : public Employee
{
protected:
	double hourlyRate;
	double hoursWorked;
public:
	Hourly();
	// Hourly
	// Purpose: Constructor
	// Parameters: int, string, string, string, string, double, double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	Hourly(int, string, string, string, string, double);
	
	// ~Hourly
	// Purpose: Destructor
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	~Hourly();
	
	// getType
	// Purpose: To identify an object
	// Parameters: None
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	int getType();
	
	// readData
	// Purpose: To read information from a file and assign it to data attributes
	// Parameters: ifstream&
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void readData(ifstream&);
	
	// writeData
	// Purpose: To write data to a file
	// Parameters: ofstream&
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void writeData(ofstream&);
	
	// calcSalary
	// Purpose: To calculate an employee's pay
	// Parameters: None
	// Returns: double
	// Pre-conditions: None
	// Post-conditions: None
	double calcSalary();
	
	// getHourlyRate
	// Purpose: To access an employee's hourlyRate
	// Parameters: None
	// Returns: double
	// Pre-conditions: None
	// Post-conditions: None
	double getHourlyRate();
	
	// setHoulyRate
	// Purpose: To change an employee's hourlyRate
	// Parameters: double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setHourlyRate(double);
	
	// getHoursWorked
	// Purpose: To access an employee's hoursWorked
	// Parameters: None
	// Returns: double
	// Pre-conditions: None
	// Post-conditions: None
	double getHoursWorked();
	
	// setHoursWorked
	// Purpose: To change an employee's hoursWorked
	// Parameters: double
	// Returns: None
	// Pre-conditions: None
	// Post-conditions: None
	void setHoursWorked(double);
	
	void plusSetHoursWorked(double hw);
};
Employee* readEmp(ifstream& read);
void assignHours(ifstream& read, vector<Employee*> group);
void assignAmount(ifstream& read, vector<Employee*> group);
void printEmp(ofstream&, Employee*);
#endif
