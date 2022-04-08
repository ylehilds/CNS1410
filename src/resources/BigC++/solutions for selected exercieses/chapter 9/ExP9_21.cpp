#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
   Student();
   Student(string n, int m, int d);
   string get_name() const;
   int get_birth_month() const;
   int get_birth_day() const;
   void print() const;

private:
   string name;
   int birth_day;
   int birth_month;
};

Student::Student()
{
   birth_day = 1;
   birth_month = 1;
}

Student::Student(string n, int m, int d)
{
   name = n;
   birth_month = m;
   birth_day = d;
}

string Student::get_name() const
{
  return name;
}

int Student::get_birth_month() const
{
   return birth_month;
}

int Student::get_birth_day() const
{
   return birth_day;
}

void Student::print() const
{
   cout << name << "Birthday: " << birth_month << "/"
      << birth_day << "\n";
}


int main()
{
   vector<Student> friends;

   string answer;
   do
   {
      cout << "Enter firstname lastname birthday (as month day)\n";
      string firstname;
      string lastname;
      int m;
      int d;
      cin >> firstname >> lastname >> m >> d;
      Student s(lastname + ", " + firstname, m, d);
      friends.push_back(s);
      cout << "Do you want to enter more friends? (y/n): ";
      cin >> answer;
   }
   while (answer == "y");

   cout << "What is the current month? (1...12) ";
   int current_month;
   cin >> current_month;

   for (int i = 0; i < friends.size(); i++)
   {
      int m = friends[i].get_birth_month();
      if (m == current_month)
      {
         cout << friends[i].get_name() <<
            " has a birthday this month on the " << friends[i].get_birth_day() << ".\n";
      }
   }

  return 0;
}
