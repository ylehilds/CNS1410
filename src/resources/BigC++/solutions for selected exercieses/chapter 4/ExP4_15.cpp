#include <iostream>
#include <string>

using namespace std;

int main()
{  
   cout <<  "Enter initial balance for checking account: ";
   double checking;
   cin >> checking;
   
   if (cin.fail())
   {  
      cout << "Input error.\n";
      return 1;
   }
   
   if (checking < 0) 
   {  
      cout << "Input error.\n";
      return 1;
   }
                
   cout <<  "Enter initial balance for savings account: ";
   double savings;
   cin >> savings;
   
   if (cin.fail())
   {  
      cout << "Input error.\n";
      return 1;
   }

   if (savings < 0) 
   {  
      cout << "Input error.\n";
      return 1;
   }
                
   cout <<  "What transaction would you like: ";
   cout <<  "Type 'deposit', 'withdrawal', or 'transfer': ";
   string transaction;
   cin >> transaction;      
 
   bool transaction_error = true;
   if (transaction == "deposit") transaction_error = false;
   else if (transaction == "withdrawal") transaction_error = false;
   else if (transaction == "transfer") transaction_error = false;
   if (transaction_error)
   {
      cout << "Wrong transaction type.\n";
      return 1;
   }
 
  
   if (transaction == "deposit")
      cout << "Into which account: ";
   else
      cout << "From which account: "; 

   cout <<  "Type 'checking' or 'savings': ";
   string account;
   cin >> account;      
   bool account_error = true;
   if (account == "checking") account_error = false;
   else if (account == "savings") account_error = false;
   if (account_error)
   {
      cout << "Wrong account type.\n";
      return 1;
   }
 
   cout <<  "Enter amount: ";
   double amount;
   cin >> amount;
   
   if (cin.fail())
   {  
      cout << "Input error.\n";
      return 1;
   }
   
   if (amount <= 0) 
   {  
      cout << "Input error.\n";
      return 1;
   }

   if (transaction == "deposit")
   {  
      if (account == "checking")
         checking = checking + amount;
      else 
         savings = savings + amount;
   }
   else 
   {  
      if (account == "checking")
      {  
         if (checking >= amount)          
            checking = checking - amount;
         else
         {
            cout <<  "Withdrawal causes an overdraft, transaction canceled : \n";   
            return 1;
         }
      }
      else
      {  
         if(savings >= amount)
            savings = savings - amount;
         else
         {
            cout <<  "Withdrawal causes an overdraft, transaction canceled : \n"; 
            return 1;
         }
      }   
   }

   if (transaction == "transfer")
   {  
      if (account == "checking")
         savings = savings + amount;
      else
         checking = checking + amount;
   }
   
   cout <<  "Checking: $" << checking << "\n";
   cout <<  "Savings: $" << savings << "\n";

   return 0;  
}
