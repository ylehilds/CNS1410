#include <iostream>
#include <string>
#include <vector>

using namespace std;


#include "ccc_time.h"

class Date
{
public:
   Date();
   Date(int y, int m, int d);
   void print() const;
   bool equals(Date other) const;
private:
   int day;
   int month;
   int year;
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

class Appointment
{
public:
   Appointment();
   Appointment(string desc, Time s, Time e);
   void print() const;
   void read();
   virtual bool occurs_on(int year, int month, int day) const;
private:
   string description;
   Time start;
   Time end;
};

Appointment::Appointment()
{
}

Appointment::Appointment(string desc, Time s, Time e)
{
   description = desc;
   start = s;
   end = e;
}

void Appointment::print() const
{
   cout << " " << start.get_hours() << ":";
   if (start.get_minutes() < 10) cout << "0";
   cout << start.get_minutes()
      << " - " << end.get_hours() << ":";
   if (end.get_minutes() < 10) cout << "0";
   cout << end.get_minutes() << " " << description << "\n";
}

void Appointment::read()
{
   int sh;
   int sm;
   int eh;
   int em;
   cout << "Enter start_hours start_minutes end_hours end_minutes description:\n";
   cin >> sh >> sm >> eh >> em;
   getline(cin, description);
   start = Time(sh, sm, 0);
   end = Time(eh, em, 0);
}

/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/
bool Appointment::occurs_on(int year, int month, int day) const
{
   return false;
}

class Onetime : public Appointment
{
public:
   Onetime();
   Onetime(string desc, Date d, Time s, Time e);
   void read();
   virtual bool occurs_on(int year, int month, int day) const;
private:
   Date when;
};

Onetime::Onetime()
{
}

Onetime::Onetime(string desc, Date d, Time s, Time e) 
:  Appointment(desc, s, e)
{
   when = d;
}

void Onetime::read()
{
   Appointment::read();
   cout << "Enter year month day: ";
   int year;
   int month;
   int day;
   cin >> year >> month >> day;
   when = Date(year, month, day);   
}

/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/
bool Onetime::occurs_on(int year, int month, int day) const
{
   return when.equals(Date(year, month, day));
}

class Daily : public Appointment
{
public:
   Daily();
   Daily(string desc, Time s, Time e);
   virtual bool occurs_on(int year, int month, int day) const;
};

Daily::Daily()
{
}

Daily::Daily(string desc, Time s, Time e) 
: Appointment(desc, s, e)
{
}

/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/
bool Daily::occurs_on(int year, int month, int day) const
{
   return true;
}

class Monthly : public Appointment
{
public:
   Monthly();
   Monthly(string desc, int d, Time s, Time e);
   void read();
   virtual bool occurs_on(int year, int month, int day) const;
private:
   int day;
};

Monthly::Monthly()
{
}

Monthly::Monthly(string desc, int d, Time s, Time e) 
:  Appointment(desc, s, e)
{
   day = d;
}

void Monthly::read()
{
   Appointment::read();
   cout << "Enter day: ";
   int d;
   cin >> d;
   day = d;
}

bool Monthly::occurs_on(int year, int month, int d) const
/**
   Determines if the appointment occurs on the given date.
   @param year a year value
   @param month a month value of 1 for Jan, to 12 for Dec
   @param day a day value
   @return true if the appointment occurs on the given date
*/

{
   return day == d;
}

int main()
{
   vector<Appointment*> schedule;
   bool more = true;

   while (more)
   {
      string input;
      cout << "Daily  Monthly  Onetime  Check  Quit (d/m/o/c/q): ";
      cin >> input;
      if (input == "d")
      {
         Daily* a = new Daily();
         a->read();
         schedule.push_back(a);
      }
      else if (input == "m")
      {
         Monthly* a = new Monthly();
         a->read();
         schedule.push_back(a);
      }
      else if (input == "o")
      {
         Onetime* a = new Onetime();
         a->read();
         schedule.push_back(a);
      }
      else if (input == "c")
      {
         cout << "Enter year month day: ";
         int year;
         int month;
         int day;
         cin >> year >> month >> day;
   
         cout << "You have these appointments: \n";
         for (int i = 0; i < schedule.size(); i++)
            if (schedule[i]->occurs_on(year, month, day))
               schedule[i]->print();
      }
      else if (input == "q")
         more = false;
   }
   return 0;
}
