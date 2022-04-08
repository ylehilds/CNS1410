#include <iostream>

using namespace std;

class Account
{
public:
   Account();
   Account(double bal);
   void deposit(double amount);
   void withdraw(double amount);
   double get_balance() const;
   void add_interest(double rate);

private:
   double balance;
};

Account::Account()
{
}

Account::Account(double bal)
{
   balance = bal;
}

void Account::deposit(double amount)
{
   balance = balance + amount;
}

void Account::withdraw(double amount)
{
   if (balance >= amount)
      balance = balance - amount;
   else
/*
   Charge a $5 penalty fee if attempting to withdraw
   more than the current balance.
*/
      balance = balance - 5;
}

double Account::get_balance() const
{
    return balance;
}

void Account::add_interest(double rate)
{
    balance = balance * (1 + rate / 100);
}

int main()
{
   double initial_investment = 10000;
   double final_amount = 2 * initial_investment;

   Account my_account(initial_investment);

   int months = 1;
   double rate = 6;      /* 6% rate per year */

   while (my_account.get_balance() < final_amount)
   {
      my_account.add_interest(rate / 12);
      months++;
   }
   
   cout << "It took " << months << " months for $" << initial_investment <<
      " to double at " << rate * 100 << "% annual interest.\n";

   cout << "Account balance: " << my_account.get_balance() << "\n";
   return 0;   
}
