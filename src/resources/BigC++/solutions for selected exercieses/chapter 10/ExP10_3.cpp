#include <iostream>
#include <string>
#include <vector>

class BankAccount
{
public:
   /**
      Constructs a bank account with a zero balance.
   */
   BankAccount();
   /**
      Deposits money into this account.
      @param amount the amount to deposit.
   */
   void deposit(double amount);
   /**
      Withdraws money from this account.
      @param amount the amount to withdraw.
   */
   void withdraw(double amount);
   /**
      Gets the balance of this account.
      @return the balance
   */
   double get_balance() const;
private:
   double balance;
};


class Employee
{
public:
   /**
      Constructs an employee with a given name, salary, and
      bank account.
      @param n the name
      @param s the annual salary
      @param a a pointer to the bank account
   */
   Employee(string n, double s, BankAccount* a);
   /**
      Deposits one month's salary into the bank account.
   */
   void deposit_monthly_salary();
   /**
      Prints this employee's information to cout.
   */
   void print() const;
private:
   string name;
   double salary;
   BankAccount* account;
};

BankAccount::BankAccount()
{
   balance = 0;
}

void BankAccount::deposit(double amount)
{
   balance = balance + amount;
}

void BankAccount::withdraw(double amount)
{
   balance = balance - amount;
}

double BankAccount::get_balance() const
{
   return balance;
}

Employee::Employee(string n, double s, BankAccount* a)
{
   name = n;
   salary = s;
   account = a;
}

void Employee::deposit_monthly_salary()
{
   const int MONTHS_PER_YEAR = 12;
   account->deposit(salary / MONTHS_PER_YEAR);
}

void Employee::print() const
{
   cout << "Employee[name=" << name << ",salary="
      << salary << ",account balance=" <<
      account->get_balance() << "]\n";
}

int main()
{
   vector<Employee> staff;
   bool more = true;
   string previous_lname = "q";
   BankAccount* previous_account = NULL;
   while (more)
   {
      string lname;
      cout << "Enter last name, q to quit: ";
      getline(cin, lname);
      if (lname == "q") more = false;
      else
      {
         string fname;
         cout << "Enter first name: ";
         getline(cin, fname);
         cout << "Enter salary: ";
         double salary;
         cin >> salary;
         string dummy;
         getline(cin, dummy);
         if (lname != previous_lname) 
         {
            previous_account = new BankAccount();
            previous_lname = lname;
         }
         staff.push_back(Employee(lname + ", " + fname,
            salary, previous_account));
      }
   }
   for (int i = 0; i < staff.size(); i++)
      staff[i].deposit_monthly_salary();
   for (int i = 0; i < staff.size(); i++)
      staff[i].print();
   return 0;
}
