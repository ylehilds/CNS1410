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

#ifndef HEADER_H
#define HEADER_H
#include <string>
using namespace std;
class Employee
{  
private:
	int empNumber;
	string name;
	string address;
	string phoneNumber;
	string socialSecurityNumber;
	
public:
// Parameterized Constructor
// Purpose: initializes all the data members of Employee class;
// Parameters: one int and 4 strings
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Employee(int, string, string, string, string);
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
// Parameterized Constructor
// Purpose: initializes all the data members of Salaried class by the base class Employee;
// Parameters: one int and 4 strings and one double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Salaried (int, string, string, string, string, double);
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
private:
	double weeklySales;
	double commission;
public:
// Parameterized Constructor
// Purpose: initializes all the data members of Sales class by class Salaried which gets the employee base class to initialize its data members;
// Parameters: one int and 4 strings and three double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Sales (int, string, string, string, string, double, double, double);
// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: weeklySales and commission are more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary( );
};
class Hourly : public Employee
{
protected:
	double hoursWorked;
	double hourlyRate ;
	
public:
// Parameterized Constructor
// Purpose: initializes all the data members of Hourly class by the base class Employee;
// Parameters: one int and 4 strings and two double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	Hourly (int, string, string, string, string, double, double);
// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: hourlyRate and hourlyWorked are more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary( );
};
class PartTime  : public Hourly 
{
private:
	int maxHours  ;
public:
// Parameterized Constructor 
// Purpose: initializes all the data members of PartTime class by the class Hourly, which gets the base class Employee to initialize its data;
// Parameters: one int and 4 strings and three double
// Returns: none
// Pre-conditions: has to be in order
// Post-conditions: none 
	PartTime (int, string, string, string, string, double, double, int);
// Pay calculator
// Purpose: calculates the right amount of pay for a specific employee type
// Parameters: none
// Returns: amount of money to be paid to employee
// Pre-conditions: maxHours is more or equal to zero
// Post-conditions: calculation of pay is more or equal to zero 
	double calcSalary( );
};
#endif
