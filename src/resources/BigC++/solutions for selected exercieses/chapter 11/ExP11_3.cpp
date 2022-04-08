#include <iostream>
#include <string>

using namespace std;

#include "ccc_empl.h"

class Manager : public Employee
{
public:
   Manager();
   Manager(string n, double s, string d);
   string get_department() const;
   void print() const;
private:
   string department;
};

Manager::Manager()
{
}

Manager::Manager(string n, double s, string d) 
:  Employee(n, s)
{
   department = d;
}

string Manager::get_department() const
{
   return department;
}

void Manager::print() const
{
   cout << get_name() << " works in the " << get_department() 
   << " department and earns a salary of $" 
   << get_salary() << "\n";
}

class Executive : public Manager
{
public:
   Executive();
   Executive(string n, double s, string d);
   void print() const;
};

Executive::Executive()
{
}

Executive::Executive(string n, double s, string d) 
:  Manager(n, s, d)
{
}

void Executive::print() const
{
   cout << "Executive ";
   Manager::print();
}

int main()
{
   Executive m = Executive("Bigwig, Bill", 136000.0, "Sales");
   m.print();
   return 0;
}
