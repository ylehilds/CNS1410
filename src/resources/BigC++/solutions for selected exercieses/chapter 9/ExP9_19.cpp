#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transaction
{
public:
   Transaction();
   void read();
   int get_day();
   double get_amount();
   void print();
private:
   int day;
   double amount;
   string description;
};

Transaction::Transaction()
{
   amount = 0;
}

void Transaction::read()
{
   cin >> day >> amount;
   getline(cin, description);
}

int Transaction::get_day()
{
   return day;
}

double Transaction::get_amount()
{
   return amount;
}

void Transaction::print()
{
   cout << day << " " << amount << " " << description << "\n";
}

const int MAX_DAY = 30;

class Statement
{
public:
   Statement();
   void read();
   void compute_balances();
   void print();
   double get_average_daily_balance();
   double get_minimum_daily_balance();
private:
   vector<Transaction> transactions;
   vector<double> daily_balances;
};

Statement::Statement()
{  
}

void Statement::read()
{
   cout << "Enter transactions in the format\ndate amount description:\n";
   bool more = true;
   while (more)
   {
      Transaction t;
      t.read();
      if (cin.fail())
         more = false;
      else
         transactions.push_back(t);
   }
   compute_balances();
}

void Statement::compute_balances()
{
   int day;
   int i = 0;
   double balance = 0;
   for (day = 1; day <= MAX_DAY; day++)
   {
      while (i < transactions.size() && transactions[i].get_day() == day)
      {
         balance = balance + transactions[i].get_amount();
         i++;
      }
      daily_balances.push_back(balance);
   }
}

double Statement::get_average_daily_balance()
{
   int day;
   double balance_sum = 0;
   for (day = 0; day < daily_balances.size(); day++)
      balance_sum = balance_sum + daily_balances[day];
   return balance_sum / MAX_DAY;
}

double Statement::get_minimum_daily_balance()
{
   int day;
   double minimum_balance = daily_balances[0];
   for (day = 1; day < daily_balances.size(); day++)
      if (daily_balances[day] < minimum_balance)
         minimum_balance = daily_balances[day];
   return minimum_balance;
}

void Statement::print()
{
   int day;
   int i = 0;
   double balance = 0;
   
   for (day = 1; day <= MAX_DAY; day++)
   {
      cout << "Day: " << day << " Balance: " << daily_balances[i - 1] << "\n";
      while (i < transactions.size() && transactions[i].get_day() == day)
      {
         transactions[i].print();
         i++;
      }
   }
   
   const double INTEREST = 0.005;
   cout << "Interest on minimum daily balance: "
      << get_minimum_daily_balance() * INTEREST << "\n";
   cout << "Interest on average daily balance: "
      << get_average_daily_balance() * INTEREST << "\n";
}

int main()
{
   Statement stat;
   stat.read();
   stat.print();

   return 0;
}
