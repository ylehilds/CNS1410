#ifndef __P28_H__

#define __P28_H__

#include <string>
#include <mysql.h>

using namespace std;

MYSQL * get_mysql_connection(void);
void exec_mysql_command(MYSQL* connection, string command);
MYSQL_RES* fetch_mysql_data(MYSQL* connection, string command);
void display_mysql_data(MYSQL* connection, string command);

int get_int(string prompt);
int get_command(int low, int high);

#endif
