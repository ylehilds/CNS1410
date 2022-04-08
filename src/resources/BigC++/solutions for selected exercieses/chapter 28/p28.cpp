#include <iostream>
#include <iomanip>

#include "p28.h"

// Return a new MySQL connection.
// Returns NULL upon failure.
// NOTE: The connection must be closed by the caller.

MYSQL * get_mysql_connection() {
	MYSQL* connection = mysql_init(NULL);

	if (mysql_real_connect(connection, NULL, "biguser", "bigpassword",
			"bigcpp", 0, NULL, 0) == NULL)
	{
		cerr << "Error: " << mysql_error(connection) << "\n";
		return NULL;
	}

	return connection;
}


// Execute the given query in MySQL.  Print out any errors that occur.

void exec_mysql_command(MYSQL* connection, string command)
{

	if (mysql_query(connection, command.c_str()) != 0)
	{
		cerr << "Error: " << mysql_error(connection) << "\n";
		return;
	}
}


// Fetch the data for a given SELECT query.
// Returns NULL upon failure.
// NOTE: The caller is responsible for freeing the result set.

MYSQL_RES* fetch_mysql_data(MYSQL* connection, string command)
{
	if (mysql_query(connection, command.c_str()) != 0)
	{
		cout << "Error: " << mysql_error(connection) << "\n";
		return NULL;
	}

	return mysql_store_result(connection);
}


// Display the data for the given command
void display_mysql_data(MYSQL* connection, string command)
{
	if (mysql_query(connection, command.c_str()) != 0)
	{
		cout << "Error: " << mysql_error(connection) << "\n";
		return;
	}

	MYSQL_RES* result = mysql_store_result(connection);
	if (result == NULL) return;

	int rows = mysql_num_rows(result);
	int fields = mysql_num_fields(result);

	// Initialize the field widths to zero
	int * fieldw = new int[fields];
	for ( int i = 0; i < fields; i++ )
	{
		fieldw[i] = 0;
	}

	// Calculate the maximum column widths
	for (int r = 1; r <= rows; r++)
	{
		MYSQL_ROW row = mysql_fetch_row(result);
		unsigned long *lengths = mysql_fetch_lengths(result);
		for (int f = 0; f < fields; f++)
		{
			if ( lengths[f] > fieldw[f] ) {
				fieldw[f] = lengths[f];
			}
		}
	}

	// Go back to the beginning of the data set
	mysql_data_seek(result, 0);

	// Print out the data with the columns aligned
	for (int r = 1; r <= rows; r++)
	{
		MYSQL_ROW row = mysql_fetch_row(result);
		for (int f = 0; f < fields; f++)
		{
			string field(row[f]);
			if (f > 0) cout << "  ";
			cout << setw(fieldw[f]) << left << field;
		}
		cout << "\n";
	}

	delete fieldw;

	mysql_free_result(result);
}


// Get a number from the user and return it.  This handles incorrect input.
int get_int(string prompt) {
	cout << prompt;

	int id;
	cin >> id;
	while ( cin.fail() ) {
		cout << "Error: Invalid number.\n";
		cout << prompt;
		cin.clear();
		cin.ignore();
		cin >> id;
	}

	if ( isspace(cin.peek()) ) {
		cin.get();
	}

	return id;
}


// Get a number from the user that represents an option from the menu.  The
// number will be returned and is guranteed to be in the range [low, high].
int get_command(int low, int high) {
	cout << "\noption: ";

	int command;
	cin >> command;
	while ( cin.fail() || command < low || command > high ) {
		cerr << "Error: Invalid command, please choose a number from the menu.\n";
		cout << "option: ";
		cin.clear();
		cin.ignore();
		cin >> command;
	}

	if ( isspace(cin.peek()) ) {
		cin.get();
	}

	return command;
}

