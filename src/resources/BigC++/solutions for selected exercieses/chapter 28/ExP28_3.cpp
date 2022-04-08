#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

#include "ccc_empl.h"
#include "sutil.h"

#include "p28.h"

/** 
   Raises an employee salary.
   @param e employee receiving raise
   @param percent the percentage of the raise
*/
void raise_salary(Employee& e, double percent)
{  
   double new_salary = e.get_salary() * (1 + percent / 100);
   e.set_salary(new_salary);
}

int main()
{  
   const int NAME_SIZE = 32;

   // Connect to the database
   MYSQL* connection = get_mysql_connection();

   // Create the employee table
   string query  = "CREATE TABLE Employee ( Name CHAR("
                   + int_to_string(NAME_SIZE)
               + "), Salary DECIMAL(8,2) )";
   exec_mysql_command(connection, query.c_str());

   // Fill it with data
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Johnson, Marianne', '36118.95')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Sanchez, Linda', '31695.00')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Lee, John', '32798.90')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Baldassarian, George S.', '25895.00')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Karamanlaki, Alexander', '27508.95')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Schmidt, Otto', '29316.00')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Stroustrup, Bjarne', '24495.00')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Keller, Chris', '23318.04')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Carter 3rd, Hodding', '26632.00')");
   exec_mysql_command(connection, "INSERT INTO Employee VALUES ('Techasaratoole, Shirley', '25795.00')");

   // Get all the employee information
   MYSQL_RES *result = fetch_mysql_data(connection,
         "SELECT Name, Salary FROM Employee");

   // If there is no data, we simply quit
   if (result == NULL) {
      mysql_close(connection);
      return 0;
   }

   // Display the employee information
   int rows = mysql_num_rows(result);
   int fields = mysql_num_fields(result);
   for (int r = 0; r < rows; r++)
   {
      MYSQL_ROW row = mysql_fetch_row(result);
      cout << r <<". " << setw(NAME_SIZE) << left << row[0] << " "
           << setw(-1) << row[1] << "\n";
   }

   // See what record the user wants to update
   cout << "Please enter the record to update: (0 - " << rows - 1 << ") ";
   int pos;
   cin >> pos;

   if ( cin.fail() || pos < 0 || pos > (rows-1) ) {
      cout << "Error: Invalid record\n";
      return 1;
   }

   // Fetch the selected record
   mysql_data_seek(result, pos);
   MYSQL_ROW row = mysql_fetch_row(result);
   string name = row[0];
   double salary = string_to_double(row[1]);
   mysql_free_result(result);

   // Create an object and update it
   const double SALARY_CHANGE = 5.0;
   Employee e = Employee(name, salary);
   raise_salary(e, SALARY_CHANGE);

   // Update the record in the database
   cout << "Updating...\n";
   query = "UPDATE Employee SET Salary = "+ double_to_string(e.get_salary());
   exec_mysql_command(connection, query.c_str());

   // Display the update information
   result = fetch_mysql_data(connection, "SELECT Name, Salary FROM Employee "
         "WHERE Name = '"+ name +"'");
   rows = mysql_num_rows(result);
   for (int r = 0; r < rows; r++)
   {
      MYSQL_ROW row = mysql_fetch_row(result);
      cout << setw(NAME_SIZE) << left << row[0] << " "
           << setw(-1) << row[1] << "\n";
   }
   mysql_free_result(result);


   exec_mysql_command(connection, "DROP TABLE Employee");

   mysql_close(connection);

   return 0;
}
