#include <iostream>
#include <string>

using namespace std;

int main()
{  
   cout <<  "Enter a numeric grade: ";
   double input;
   cin >> input;
    
    string letter;
   
   int grade = static_cast<int>(input + 0.5);
      // round to nearest integer
   if (grade == 4) letter = "A";
   else if (grade == 3) letter = "B";
   else if (grade == 2) letter = "C";
   else if (grade == 1) letter = "D";
   else letter = "F";
   
   double modifier = input - grade;
   
   if (modifier < -0.15) letter = letter + "-";
   else if (modifier >= 0.15) letter = letter + "+";
        
   cout << "The letter grade is " << letter << "\n";
      
   return 0;
}
