#include <iostream>

using namespace std;

#include "ccc_empl.h"

class Programmer : public Employee
{
public:
   /**
      Constructs a programmer with a given name and salary.
      @param name the name
      @param salary the salary
   */
   Programmer(string name, double salary);
   string get_name() const;
};

Programmer::Programmer(string name, double salary)
   : Employee(name, salary) {}

string Programmer::get_name() const
{
   return Employee::get_name() + " (Programmer)";
}
