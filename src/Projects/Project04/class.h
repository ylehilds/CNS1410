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

#ifndef HEADER_H
#define HEADER_H
#include <string>
using namespace std;
class Employee
{  
protected:
	int empNumber;
	string name;
	string address;
	string phoneNumber;
	string socialSecurityNumber;
	int datatype;
	
public:
// default Constructor 
// Purpose: initializes the data member datatype;
// Parameters: none
// Returns: none
// Pre-conditions:none
// Post-conditions: none  
	Employee();
// Parameterized Constructor 
// Purpose: initializes all the data members of Employee class;
// Parameters: one int and 4 strings
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Employee(int, string, string, string, string);
// virtual destructor
// Purpose: destroys the Employee and derived classes 
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none 
	virtual ~Employee(){}
// pure virtual function
// Purpose:function that can be overriden on derived classes
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	virtual double calcSalary()=0;
// virtual function reads data 
// Purpose:function that can be overriden on derived classes
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none	
	virtual void readData(ifstream&) ;
// virtual function that writed data
// Purpose:function that can be overriden on derived classes
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	virtual void writeData(ofstream&) ;
	
// getter
// Purpose: gets the employee number
// Parameters: none
// Returns: employee number
// Pre-conditions: none 
// Post-conditions: none 	
	int get_empNumber();
// getter
// Purpose: gets the address information
// Parameters: none
// Returns: address
// Pre-conditions: none 
// Post-conditions: none 	
	string get_address();
// getter
// Purpose: gets the phone number information
// Parameters: none
// Returns: phone number
// Pre-conditions: none 
// Post-conditions: none 	
	string get_phoneNumber();
// getter
// Purpose: gets the social security number information
// Parameters: none
// Returns: the social security number
// Pre-conditions: none 
// Post-conditions: none 	
	string get_socialSecurityNumber();
// getter
// Purpose: gets the name of employee information
// Parameters: none
// Returns: employee name
// Pre-conditions: none 
// Post-conditions: none 		
	string get_name();
	
};

class Salaried : public Employee
{
protected:
	double weeklySalary;
public:
// default Constructor 
// Purpose: initializes the data member datatype;
// Parameters: none
// Returns: none
// Pre-conditions:none
// Post-conditions: none  
	Salaried();
// Parameterized Constructor
// Purpose: initializes all the data members of Salaried class by the base class Employee;
// Parameters: one int and 4 strings and one double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Salaried (int, string, string, string, string, double);
// destructor
// Purpose: destroys the Salaried class 
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none 
	~Salaried(){}
// function writes its own data instead of using the database one
// Purpose:function that writes its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void writeData(ofstream&);
// function reads its own data instead of using the database one
// Purpose:function that reads its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void readData(ifstream&); 
// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: weeklySalary more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary();
};

class Sales : public Salaried
{
protected:
	double weeklySales;
	double commission;
public:
// default Constructor 
// Purpose: initializes the data member datatype;
// Parameters: none
// Returns: none
// Pre-conditions:none
// Post-conditions: none 
	Sales();
// Parameterized Constructor
// Purpose: initializes all the data members of Sales class by class Salaried which gets the employee base class to initialize its data members;
// Parameters: one int and 4 strings and three double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Sales (int, string, string, string, string, double, double, double);
// destructor
// Purpose: destroys the Sales class 
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none 
	~Sales(){}

// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: weeklySales and commission are more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary();
// function writes its own data instead of using the database one
// Purpose:function that writes its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void writeData(ofstream&); 
// function reads its own data instead of using the database one
// Purpose:function that reads its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void readData(ifstream&); 
	
};
class Hourly : public Employee
{
protected:
	double hoursWorked;
	double hourlyRate ;
public:
// default Constructor 
// Purpose: initializes the data member datatype;
// Parameters: none
// Returns: none
// Pre-conditions:none
// Post-conditions: none 
	Hourly();
// Parameterized Constructor
// Purpose: initializes all the data members of Hourly class by the base class Employee;
// Parameters: one int and 4 strings and two double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none
	Hourly (int, string, string, string, string, double, double);
// destructor
// Purpose: destroys the Hourly class 
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none 
	~Hourly(){}
// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: hourlyRate and hourlyWorked are more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary( );
// function writes its own data instead of using the database one
// Purpose:function that writes its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void writeData(ofstream&); 
// function reads its own data instead of using the database one
// Purpose:function that reads its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void readData(ifstream&); 
	
};
class PartTime  : public Hourly 
{
protected:
	int maxHours;
public:
// default Constructor 
// Purpose: initializes the data member datatype;
// Parameters: none
// Returns: none
// Pre-conditions:none
// Post-conditions: none 
	PartTime();
// Parameterized Constructor 
// Purpose: initializes all the data members of PartTime class by the class Hourly, which gets the base class Employee to initialize its data;
// Parameters: one int and 4 strings and three double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	PartTime (int, string, string, string, string, double, double, int);
// destructor
// Purpose: destroys the PartTime class 
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none 
	~PartTime(){}
// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: maxHours is more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary( );
// function writes its own data instead of using the database one
// Purpose:function that writes its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void writeData(ofstream&); 
// function reads its own data instead of using the database one
// Purpose:function that reads its own data
// Parameters: has to be a stream type
// Returns: none
// Pre-conditions: none
// Post-conditions: none
	void readData(ifstream&); 
	
};
#endif
