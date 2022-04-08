#include <iostream>
#include <mysql.h>

using namespace std;

#include "sutil.h"
#include "p28.h"

int main(void)
{
   MYSQL* connection = get_mysql_connection();

   // Create the database
   exec_mysql_command(connection, "CREATE TABLE Car (manufacturer CHAR(20), "
      "type CHAR(20), model_year CHAR(4), fer DECIMAL(3,2))");
   
   // Fill the database with data
   exec_mysql_command(connection, "INSERT INTO Car VALUES ('Ford', 'Ranger', '2002', 2.9)");
   exec_mysql_command(connection, "INSERT INTO Car VALUES ('Toyota', 'Camry', '2001', 2.5)");
   exec_mysql_command(connection, "INSERT INTO Car VALUES ('Honda', 'Civic', '2002', 3.0)");
   exec_mysql_command(connection, "INSERT INTO Car VALUES ('Honda', 'Accord', '2002', 3.4)");

   // Print the average
   MYSQL_RES *result = fetch_mysql_data(connection, "SELECT AVG(fer) AS Average FROM Car");
   MYSQL_ROW row = mysql_fetch_row(result);
   cout << "The average fuel efficiency: "<< string_to_double(row[0]) <<"\n";

   // Clean up
   exec_mysql_command(connection, "DROP TABLE Car");
   mysql_close(connection);

   return 0;
}

