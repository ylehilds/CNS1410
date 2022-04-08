#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
   Employee(string n) : name(n) { }
   string get_name() { return name; }
private:
   string name;
};

class OptionalEmployee
{
public:
   OptionalEmployee();
   void set(Employee* t);
   Employee* get() const;
   bool exists() const;
   OptionalEmployee(const OptionalEmployee& b);
   ~OptionalEmployee();
   OptionalEmployee& operator=(const OptionalEmployee& b);
private:
   Employee* p;
};

OptionalEmployee::OptionalEmployee() { p = NULL; }

void OptionalEmployee::set(Employee* t) 
{ 
   delete p; 
   p = t;
}

Employee* OptionalEmployee::get() const { return p; }

bool OptionalEmployee::exists() const { return p != NULL; }

OptionalEmployee::OptionalEmployee(const OptionalEmployee& b)
{
   if (b.p == NULL) p = NULL;
   else p = new Employee(*b.p);
}

OptionalEmployee::~OptionalEmployee()
{
   delete p;
}

OptionalEmployee& OptionalEmployee::operator=(const OptionalEmployee& b)
{
   delete p;
   if (b.p == NULL) p = NULL;
   else p = new Employee(*b.p);
}

class Department
{
public:
   OptionalEmployee secretary;
};

int main()
{
   Department d;
   if (d.secretary.exists())
      cout << "we have a secreatary: " << d.secretary.get()->get_name() << "\n";
   else
      cout << "we do not have a secreatary\n";
   d.secretary.set(new  Employee("Fred"));
   if (d.secretary.exists())
      cout << "we have a secreatary: " << d.secretary.get()->get_name() << "\n";
   else
      cout << "we do not have a secreatary\n";
   return 0;
}
