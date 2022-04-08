#include <iostream> 

using namespace std; 

int main() 
{  
   cout << "Please enter the amount due: "; 
   double amount_due; 
   cin >> amount_due; 

   cout << "Please enter the amount paid: "; 
   double amount_paid; 
   cin >> amount_paid; 

   /* Calculate the difference between the amount paid and the amount due. */ 

   double difference = amount_paid - amount_due; 

   /* Convert the difference into pennies. */ 
   
   int change = static_cast<int>(difference * 100);

   int dollars = change / 100; /* Number of dollars in change */ 
   change = change - (dollars * 100); /* Subtract dollars from change */ 
  
   int quarters = change / 25; /* Number of quarters in change */ 
   change = change - (quarters * 25); /* Subtract quarters from change */ 
  
   int dimes = change / 10; /* Number of dimes in change */ 
   change = change - (dimes * 10); /* Subtract dimes from change */ 
  
   int nickels = change / 5; /* Number of nickels in change */ 
   change = change - (nickels * 5); /* Subtract nickels from change */ 

   int pennies = change; /* What is left is the number of pennies */

   cout << "The change due to the customer is " 
      << dollars << " dollars, " << quarters << " quarters, " 
      << dimes << " dimes, " << nickels << " nickels, and " << pennies 
      << " pennies.\n"; 

   return 0; 
} 
  
