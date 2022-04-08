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

int main()
{
   cout << "Please enter the data file name: ";
   string filename;
   cin >> filename;
   cout << "Enter the raise percentage: ";
   double raise;
   cin >> raise;

   fstream fs;
   fs.open(filename.c_str());
   fs.seekg(0, ios::end); /* go to end of file */
   int nrecord = fs.tellg() / RECORD_SIZE;
   
   int pos;
   for (pos = 0; pos < nrecord; pos++)
   {
      Employee e;
      fs.seekg(pos * RECORD_SIZE, ios::beg); 
      read_employee(e, fs);
      raise_salary(e, raise);
      write_employee(e, cout);
      fs.seekp(pos * RECORD_SIZE, ios::beg); 
      write_employee(e, fs);
   }

   fs.close();
   return 0;
}
