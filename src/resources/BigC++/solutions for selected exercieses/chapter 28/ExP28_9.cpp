#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

#include "sutil.h"

#include "p28.h"


void display_customer(MYSQL* connection, int customer) {
   string query = "SELECT name, address, city, state, zip "
         "FROM Customer WHERE Customer_Number = "+ int_to_string(customer);
   MYSQL_RES *result = fetch_mysql_data(connection, query.c_str());
   int rows = mysql_num_rows(result);
   if ( rows <= 0 ) {
      return;
   }

   MYSQL_ROW row = mysql_fetch_row(result);
   cout << row[0] <<"\n";
   cout << row[1] <<"\n";
   cout << row[2] <<", "<< row[3] <<" "<< row[4] <<"\n\n\n";

   mysql_free_result(result);
}

void display_invoice(MYSQL* connection, int invoice, double & total, double & paid) {

   // Fetch out the itemized detail
   string query = "Select p.Description, i.Quantity, p.Unit_Price, "
         "i.Quantity * p.Unit_Price "
         "FROM Product p, Item i "
         "WHERE p.Product_code = i.Product_code "
         "AND i.Invoice_Number = "+ int_to_string(invoice);
   MYSQL_RES *result = fetch_mysql_data(connection, query.c_str());
   if ( result == NULL ) {
      return;
   }

   int rows = mysql_num_rows(result);
   int fields = mysql_num_fields(result);
   if ( rows <= 0 ) {
      mysql_free_result(result);
      return;
   }

   // Initialize the field widths to the width of the labels
   int * fieldw = new int[fields];
   fieldw[0] = 4;
   fieldw[1] = 3;
   fieldw[2] = 5;
   fieldw[3] = 5;

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
   cout << left;
   cout << setw(fieldw[0]) <<"Item" << "  ";
   cout << setw(fieldw[1]) <<"Qty" << "   ";
   cout << setw(fieldw[2]) <<"Price" << "   ";
   cout << setw(fieldw[3]) <<"Total\n";

   total = 0;
   for ( int r = 0; r < rows; r++ ) {
      MYSQL_ROW row = mysql_fetch_row(result);
      double amount = string_to_double(row[3]);
      cout << left << setw(fieldw[0]) << row[0] << "  ";
      cout << right << setw(fieldw[1]) << row[1] << "  ";
      cout << "$" << setw(fieldw[2]) << row[2] << "  ";
      cout << "$" << setw(fieldw[3]) << amount <<"\n";
      total += amount;
   }
   delete fieldw;
   mysql_free_result(result);

   // Get the payment
   result = fetch_mysql_data(connection, "SELECT Payment FROM Invoice "
         "WHERE Invoice_Number = "+ int_to_string(invoice));
   MYSQL_ROW row = mysql_fetch_row(result);
   paid = string_to_double(row[0]);
   mysql_free_result(result);

   cout << "TOTAL: $"<< total <<"\n";
   cout << "PAID: $"<< paid <<"\n\n";

   return;
}


void display_charges(MYSQL* connection, int customer) {
   // Get the invoice list from the database
   string query = "SELECT Invoice_Number FROM Invoice "
         "WHERE Customer_Number = "+ int_to_string(customer);
   MYSQL_RES *result = fetch_mysql_data(connection, query.c_str());
   if ( result == NULL ) {
      return;
   }

   int invoice_n = mysql_num_rows(result);
   if ( invoice_n <= 0 ) {
      return;
   }

   // Go through each of the invoices, display them, and calculate the totals
   double sub_total = 0;
   double sub_paid = 0;
   double total = 0;
   double paid = 0;
   for ( int i = 0; i < invoice_n; i++ ) {
      MYSQL_ROW row = mysql_fetch_row(result);
      display_invoice(connection, string_to_int(row[0]), sub_total, sub_paid);
      total += sub_total;
      paid += sub_paid;
   }
   mysql_free_result(result);

   // Display the totals
   cout << "GRAND TOTAL: $"<< total <<"\n";
   cout << "\n";
   cout << "AMOUNT PAID: $"<< paid <<"\n";
   cout << "AMOUNT DUE: $"<< total - paid <<"\n";
}


void display_all_charges(MYSQL *connection) {  

   string sep = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

   // Generate the reports for each invoice
   MYSQL_RES *result = fetch_mysql_data(connection, "SELECT Customer_Number FROM Customer");
   if ( result != NULL ) {
      cout << sep << "\n";
      int rows = mysql_num_rows(result);
      for ( int i = 0; i < rows; i++ ) {
         MYSQL_ROW row = mysql_fetch_row(result);
         display_customer(connection, string_to_int(row[0]));
         display_charges(connection, string_to_int(row[0]));
         cout << sep << "\n";
      }
      mysql_free_result(result);
   }

   cout << "\n\n";
   return;
}


// Returns a number >= 0, or -1 if the user wants to search

int get_number_or_search() {
   cout << ": ";
   
   int num = 0;
   char c;
   bool done = false;

   do {
      c = cin.get();
      while ( isspace(c) ) {
         c = cin.get();
      }

      if ( c == 's' || c == 'S' ) {
         num = -1;
         done = true;
      } else {
         cin.putback(c);
         cin >> num;
         if ( cin.fail() ) {
            cout << "Error: Invalid number.\n";
            cout << ": ";
            cin.clear();
            cin.ignore();
         } else {
            if ( num > 0 ) {
               done = true;
            } else {
               cout << "Error: Invalid number.\n";
            }
         }
      }
   } while ( !done );

   if ( isspace(cin.peek()) ) {
      cin.get();
   }

   return num;
}


void search_for_customer(MYSQL *connection) {
   bool done = false;
   int customer = 0;

   char name[100];
   cout << "\nPlease type part of the customer name\n";
   cout << ": ";

   cin.getline(name, 100);

   string query = "SELECT * FROM Customer WHERE Name like '%";
   query += name;
   query += "%'";

   cout << "\nResults:\n";
   display_mysql_data(connection, query);
   cout << "\n";

   return;
}


void search_for_product(MYSQL *connection) {
   bool done = false;
   int customer = 0;

   char desc[100];
   cout << "\nPlease type part of the product description\n";
   cout << ": ";

   cin.getline(desc, 100);

   string query = "SELECT * FROM Product WHERE Description like '%";
   query += desc;
   query += "%'";

   cout << "\nResults:\n";
   display_mysql_data(connection, query);
   cout << "\n";

   return;
}


bool has_results(MYSQL *connection, string query) {
   MYSQL_RES *result = fetch_mysql_data(connection, query);
   if ( result == NULL ) {
      return false;
   }

   bool answer = false;
   if ( mysql_num_rows(result) > 0 ) {
      return true;
   }
   mysql_free_result(result);

   return answer;
}


bool customer_exists(MYSQL *connection, int customer) {
   string query = "SELECT Customer_Number FROM Customer "
         "WHERE Customer_Number = "+ int_to_string(customer);
   return has_results(connection, query);
}


bool product_exists(MYSQL *connection, char *product) {
   string query = "SELECT Product_Code FROM Product "
         "WHERE Product_Code = '";
   query += product;
   query += "'";
   return has_results(connection, query);
}


void add_invoice(MYSQL *connection) {
   cout << "\n\n       Adding Invoice\n\n\n";

   // Get the customer information
   int customer = -1;
   bool invalid_customer = true;
   do {
      cout << "Please enter the customer id, or type 'S' to search\n";
      customer = get_number_or_search();
      if ( customer == -1 ) {
         search_for_customer(connection);
      } else if ( customer_exists(connection, customer) ) {
         invalid_customer = false;
      } else {
         cout << "Error: invalid customer id\n";
      }
   } while (invalid_customer);


   // Get the next highest invoice number
   int invoice = 1;
   string query = "SELECT MAX(Invoice_Number)+1 FROM Invoice";
   MYSQL_RES *result = fetch_mysql_data(connection, query);
   if ( result != NULL ) {
      int rows = mysql_num_rows(result);
      if ( rows > 0 ) {
         MYSQL_ROW row = mysql_fetch_row(result);
         invoice = string_to_int(row[0]);
      }
      mysql_free_result(result);
   }

   // Put a record for the invoice into the database
   query = "INSERT INTO Invoice VALUES ("+ int_to_string(invoice) +","
         + int_to_string(customer) +",0.0)";
   exec_mysql_command(connection, query);


   bool done = false;
   char c;
   do {
      // Get the product information
      char product[100];
      bool invalid_product = true;
      do {
         cout << "\nPlease enter a product id, or type 'S' to search\n";
         cout << ": ";
         cin.getline(product, 100);
         if ( product[0] == 's' || product[0] == 'S' ) {
            search_for_product(connection);
         } else if ( product_exists(connection, product) ) {
            invalid_product = false;
         } else {
            cout << "Error: Invalid product id '"<< product <<"'\n";
         }
      } while (invalid_product);


      // Get the quantity
      cout << "Please enter a quantity\n";
      int quantity = get_int(": ");

      // Insert the values into the database
      query  = "INSERT INTO Item VALUES ("+ int_to_string(invoice) +",'";
      query += product;
      query += "',"+ int_to_string(quantity) +")";
      exec_mysql_command(connection, query);

      // See if they want to add more
      cout << "Add more products? (y/n): ";
      c = cin.get();
      while ( isspace(c) ) {
         c = cin.get();
      }
      if ( c == 'n' || c == 'N' ) {
         done = true;
      }

   } while (!done);

   cout <<"\n\n";
}


int main(void) {
   // Connect to the database
   MYSQL* connection = get_mysql_connection();
   if ( connection == NULL ) {
      return 1;
   }

   bool done = false;

   while ( ! done ) {
      cout << "*** MAIN MENU ***\n";
      cout << "1. Add invoice\n";
      cout << "2. Display all charges\n";
      cout << "3. Quit\n";

      int command = get_command(1,3);

      switch ( command ) {
         case 1: add_invoice(connection); break;
         case 2: display_all_charges(connection); break;
         case 3: done = true; break;
      }
   }

   mysql_close(connection);

   return 0;
}

