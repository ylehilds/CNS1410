#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
   Person();
   Person(string pname, int page);
   string get_name() const;
   int get_age() const;
private:
   string name;
   int age; /* 0 if unknown */
};

Person::Person()
{
}

Person::Person(string pname, int page)
{
   name = pname;
   age = page;
}

string Person::get_name() const
{
   return name;
}

int Person::get_age() const
{
   return age;
}

void main()
{
   Person f("Fred", 20);
   cout << f.get_name() << " is " <<
      f.get_age() << " years old.\n";
}   
