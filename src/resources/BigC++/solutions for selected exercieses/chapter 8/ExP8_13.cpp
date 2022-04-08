/* I got name = "", salary = 1.02289e-306
*/

#include <iostream>

using namespace std;

#include "ccc_empl.h"

Employee read_employee()
{
   cout << "Please enter the name: ";
   string name;
   getline(cin, name);
   cout << "Please enter the salary: ";
   double salary;
   cin >> salary;
   Employee r(name, salary);
   return r;
}

int main()
{
   Employee e = read_employee();
   cout << "Name is " << e.get_name() << " salary is " << e.get_salary() << ".\n";

   Employee f = read_employee();
   cout << "Name is " << f.get_name() << " salary is " << f.get_salary() << ".\n";

   return 0;
}
