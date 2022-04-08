#include <iostream>

using namespace std;

#include "ccc_empl.h"

int main()
{  
   string first_name;                     
   cout << "Enter the first name: ";
   cin >> first_name;

   string last_name;
   cout << "Enter the last name: ";
   cin >> last_name;

   double salary = 0;
   cout << "Enter the salary: ";
   cin >> salary;

   /* construct the Employee object and name the object the_employee       */

   Employee the_employee( last_name + ", " + first_name, salary );

   /* give the employee a 5% salary increment */

   the_employee.set_salary( the_employee.get_salary() * 1.05 );

   /* output the new information using Employee member functions           */

   cout << "The employee " << the_employee.get_name() <<  " now earns $" 
      << the_employee.get_salary() << "\n";

   return 0;
}

