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
	
public:
	Employee(string, double, double, double, string, string, double); 
	double CalcPay(double);
	double setSales(Employee);
	string getname();
	double setter_sales(double);
	
};
