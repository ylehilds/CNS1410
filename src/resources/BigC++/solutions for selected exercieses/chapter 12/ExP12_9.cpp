#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

#include "ccc_empl.h"

const int NEWLINE_LENGTH = 2; /* or 1 on Unix */
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;

/**
   Converts a string to a floating-point value, e.g. "3.14" -> 3.14.
   @param s a string representing a floating-point value
   @return the equivalent floating-point value
*/
double string_to_double(string s)
{
   istringstream instr(s);
   double x;
   instr >> x;
   return x;
}

/**
   Raises an employee salary. 
   @param e employee receiving raise
   @param by the percentage of the raise
*/
void raise_salary(Employee& e, double percent)
{
   double new_salary = e.get_salary() * (1 + percent / 100);
   e.set_salary(new_salary);
}

/**
   Reads an employee record from a file.
   @param e filled with the employee
   @param fs the file stream to read from
*/
void read_employee(Employee& e, istream& fs)
{
   string line;
   getline(fs, line);
   if (fs.fail()) return;
   string name = line.substr(0, 30);
   double salary = string_to_double(line.substr(30, 10));
   e = Employee(name, salary);
}

/**
   Writes an employee record to a file.
   @param e the employee record to write
   @param fs the file stream to write to
*/
void write_employee(Employee e, ostream& fs)
{
   fs << e.get_name()
      << setw(10 + (30 - e.get_name().length()))
      << fixed << setprecision(2)
      << e.get_salary()
      << "\n";
}

void find(fstream& fs, int nrecord)
{
   cout << "Enter the name of the employee to find: ";
   string name;
   getline(cin, name);
   int first = 0;
   int last = nrecord - 1;
   while (first <= last)
   {
      int mid = (first + last) / 2;
      fs.seekg(mid * RECORD_SIZE, ios::beg);
      Employee e;
      read_employee(e, fs);
      string ename = e.get_name().substr(0, name.length());
      if (name == ename)
      {
         cout << "Found " << e.get_name() << " " << e.get_salary() << "\n";
         return;
      }
      else if (name < ename)                    
      {
         last = mid - 1;
      }
      else
      {
         first = mid + 1;
      }
   }
   cout << "Not found.\n";
}

int main()
{
   cout << "Please enter the data file name: ";
   string filename;
   cin >> filename;
   fstream fs;
   fs.open(filename.c_str());
   fs.seekg(0, ios::end); /* go to end of file */
   int nrecord = fs.tellg() / RECORD_SIZE;
   find(fs, nrecord);
   bool more = true;
   while (more)
   {
      cout << "Find  Quit (f/q)";
      string cmd;
      cin >> cmd;
      if (cmd == "f")
         find(fs, nrecord);
      else if (cmd == "q")
         more = false;
   }
   fs.close();
   return 0;
}
