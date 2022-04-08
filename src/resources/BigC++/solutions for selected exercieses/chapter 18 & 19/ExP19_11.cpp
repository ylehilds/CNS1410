// The following illustrates the idea. Here the funciton read
// has been changed to throw an exception on error.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "ccc_time.h"

class Date
{
public:
   Date();
   Date(int y, int m, int d);
   void print() const;
   bool before(Date other) const;
   bool equals(Date other) const;
private:
   int day;
   int month;
   int year;
};

class Appointment
{
public:
   Appointment();
   Appointment(Date w, Time s, Time e);
   void read();
   void print() const;
   bool before(Appointment other) const;
   bool same_start(Appointment other) const;
private:
   string description;
   Date when;
   Time start;
   Time end;
};

Date::Date()
{
   day = 1;
   month = 1;
   year = 1;
}

Date::Date(int y, int m, int d)
{
   day = d;
   month = m;
   year = y;
}

void Date::print() const
{
   cout << year << "/" << month << "/" << day;
}

bool Date::equals(Date other) const
{
   return day == other.day && month == other.month
      && year == other.year;
}

bool Date::before(Date other) const
{
   return year < other.year || year == other.year
      && (month < other.month || month == other.month
      && day < other.day);
}

Appointment::Appointment()
{
}

Appointment::Appointment(Date w, Time s, Time  e)
{
   when = w;
   start = s;
   end = e;
}

void Appointment::read()
{
   int y;
   int m;
   int d;
   int sh;
   int sm;
   int eh;
   int em;
   cout << "Enter appointment in the format\n"
      << "year month day start_hours start_minutes end_hours end_minutes description:\n";
   if (!(cin >> y >> m >> d >> sh >> sm >> eh >> em))
	throw "invalid appointment format";
   getline(cin, description);
   when = Date(y, m, d);
   start = Time(sh, sm, 0);
   end = Time(eh, em, 0);
}

bool Appointment::before(Appointment other) const
{
   return when.before(other.when)
      || when.equals(other.when)
      && start.seconds_from(other.start) < 0;
}

bool Appointment::same_start(Appointment other) const
{
   return when.equals(other.when) && start.seconds_from(other.start) == 0;
}

void Appointment::print() const
{
   when.print();
   cout << " " << start.get_hours() << ":";
   if (start.get_minutes() < 10) cout << "0";
   cout << start.get_minutes()
      << " - " << end.get_hours() << ":";
   if (end.get_minutes() < 10) cout << "0";
   cout << end.get_minutes() << description << "\n";
}

class Schedule
{
public:
   void add(Appointment a);
   void remove(Date when, Time start);
   void print() const;
private:
   vector<Appointment> appointments;
};

void Schedule::add(Appointment a)
{
   for (int i = 0; i < appointments.size(); i++)
   {
      if (a.before(appointments[i]))
      {
         appointments.push_back(Appointment());
         for (int j = appointments.size(); j > i; j--)
            appointments[j] = appointments[j - 1];
         appointments[i] = a;
         return;
      }
   }
   appointments.push_back(a);
}

void Schedule::remove(Date when, Time start)
{
   Appointment dummy(when, start, start);
   for (int i = 0; i < appointments.size(); i++)
   {
      if (appointments[i].same_start(dummy))
      {
         for (int j = i + 1; i < appointments.size(); j++)
            appointments[j - 1] = appointments[j];
         appointments.pop_back();
      }
   }
}

void Schedule::print() const
{
   for (int i = 0; i < appointments.size(); i++)
      appointments[i].print();
}

int main()
{
   Schedule schedule;
   bool more = true;

   while (more)
   {
      string input;
      cout << "Add  Remove  Print  Quit (a/r/p/q): ";
      cin >> input;
      if (input == "a")
      {
         Appointment a;
         a.read();
         schedule.add(a);
      }
      else if (input == "r")
      {
         int y, m, d, sh, sm;
         cout << "Specify appointment in the format\n"
            << "year month day start_hours start_minutes:\n";
         cin >> y >> m >> d >> sh >> sm;
         string dummy;
         getline(cin, dummy);
         schedule.remove(Date(y, m, d), Time(sh, sm, 0));
      }
      else if (input == "p")
      {
         schedule.print();
      }
      else if (input == "q")
         more = false;
   }
   return 0;
}
