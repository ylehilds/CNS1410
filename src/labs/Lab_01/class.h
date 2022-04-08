#include <string>
using namespace std;
class Employee
{
private: 
	double  weeklySalary; 
	double  commission; 
	string name; 
	double empNumber;
	string address;
	string phoneNumber;
	double deptNumber;
	double sales;
	
public:
// Parameterized Constructor 
// Purpose: Initializes the class information of the employee
// Parameters: 3 strings and 4 doubles
// Returns: none
// Pre-conditions: none 
// Post-conditions: none 
	Employee(string, double, double, double, string, string, double); 
// CalcPay( ) Employee class function.
// Purpose: This function is to calculate the amount of money to be paid to the employee 
// decides if employee will get only salary or salary + commission, depending of his sale performance.
// Inputs: The function gets the sale amount recorded by setSales()
// function to the Employee class.
// Returns: The function returns the calculated sale amount to be paid to the employee.
// Preconditions: The sales cannot be less than zero.
// Postconditions: The return value cannot be zero.
// ----------------------------------------------------------- 
	double CalcPay();
// setSales( ) stand alone function
// Purpose: This function is to prompt and record the amount of sales amount for an employee 
// and returns the amount of sales
// Inputs: The function takes One Employee class Pointer.
// The amountof money is recorded in the class object.
// Returns: The function returns the sale amount as a double.
// Preconditions: The Pointer argument cannot be NULL.
// Postconditions: The return value cannot be less than zero.
// ----------------------------------------------------------- 
	double setSales(Employee);
// Purpose: getter, get the name of employee from the private class
// Parameters: none
// Returns: private information name
// Pre-conditions: none 
// Post-conditions: none 
	string getname();
// Purpose: getter, get the sales amount of employee from the private class
// Parameters: none
// Returns: private information sales
// Pre-conditions: none 
// Post-conditions: none 	
	double getSales();
// Purpose: setter, set the sales amount of employee to the private class data member sales
// Parameters: none
// Returns: private information sales
// Pre-conditions: none 
// Post-conditions: none 	
	void set_sales(double);
};
