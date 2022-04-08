// Although the nested class trick does avoid multiple inheritance,
// it introduces more classes and pointers.

#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
   Student (string iid);
   string get_id() const;
private:
   string id;
};

Student::Student(string iid) : id(iid) { }

string Student::get_id() const
{
   return id;
}

class Employee {
public:
   Employee (string iid);
   string get_id() const;
private:
   string id;
};

Employee::Employee(string iid) : id(iid) { }

string Employee::get_id() const
{
   return id;
}

class TeachingAssistant
{
public:
   TeachingAssistant(string sid, string eid);
   string get_id() const;
   string student_id() const;
   Student* asStudent();
   Employee* asEmployee();
private:
   class StudentPart;
   StudentPart *s_part;
   class EmployeePart;
   EmployeePart *e_part;
};

class TeachingAssistant::StudentPart : public Student
{
public:
   StudentPart(TeachingAssistant*, string sid);
private:
   TeachingAssistant* ta_part;
};

TeachingAssistant::StudentPart::StudentPart(TeachingAssistant* ta, string sid)
   : Student(sid)
{
   ta_part = ta;
}

class TeachingAssistant::EmployeePart : public Employee
{
public:
   EmployeePart(TeachingAssistant* ta, string eid);
private:
   TeachingAssistant* ta_part;
};

TeachingAssistant::EmployeePart::EmployeePart(TeachingAssistant* ta, string eid)
   : Employee(eid)
{
   ta_part = ta;
}

TeachingAssistant::TeachingAssistant(string sid, string eid)
   : s_part(new StudentPart(this, sid)), e_part(new EmployeePart(this, eid)) { }

string TeachingAssistant::get_id() const
{
   return e_part->get_id();
}

string TeachingAssistant::student_id() const
{
   return s_part->get_id();
}

Student* TeachingAssistant::asStudent()
{
   return s_part;
}

Employee* TeachingAssistant::asEmployee()
{
   return e_part;
}

int main() {
   Student* fred = new Student("fred");
   Employee* jane = new Employee("jane");
   cout << "id for fred " << fred->get_id() << "\n";
   cout << "id for jane " << jane->get_id() << "\n";
   TeachingAssistant* beth = new TeachingAssistant("bethsid", "betheid");
   cout << "id for beth " << beth->get_id() << "\n";

   vector<Student*> students;
   students.push_back(fred);
   students.push_back(beth->asStudent());
   for (int i = 0; i < students.size(); i++)
      cout << "student " << students[i]->get_id() << "\n";

   vector<Employee*> employees;
   employees.push_back(jane);
   employees.push_back(beth->asEmployee());
   for (int i = 0; i < employees.size(); i++)
      cout << "employee " << employees[i]->get_id() << "\n";
}
