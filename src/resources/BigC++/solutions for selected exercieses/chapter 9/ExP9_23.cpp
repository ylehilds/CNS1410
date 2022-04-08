#include <iostream>
#include <vector>

using namespace std;

int main()
{
   vector<int> square_input;

   cout << "Enter values:\n ";
   bool more = true;
   while (more)
   {
      int input;
      cin >> input;
      if (cin.fail())
         more = false;
      else
         square_input.push_back(input);
   }

   /* determine if n * n entries were entered
   */
   int n = static_cast<int>(sqrt(square_input.size()));
   if (n * n != square_input.size())
   {
      cout << "Not a square matrix.\n";
      return 0;
   }
  
   /* determine if each of the numbers 1,2, ... n*n occur exactly once
   */
   int i;
   int j;
   for (i = 1; i <= n * n; i++)
   {
      bool found = false;
      for (j = 0; !found && j < square_input.size(); j++)
         if (square_input[j] == i) found = true;
      if (!found)
      {
         cout << i << " is missing from the matrix.\n";
         return 0;
      }
   }
   
   /* construct a matrix out of the square_input vector */
   
   const int MAX_N = 20;
   if (n > MAX_N)
   {
      cout << "Sorry; can only process up to "
         << MAX_N << " by " << MAX_N << " squares.\n";
      return 1;
   }
   
   int magic_square[MAX_N][MAX_N];
   
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         magic_square[i][j] = square_input[i * n + j];

   int sum = 0;

   /* sum up each row */
   for (i = 0; i < n; i++)
   {
      int total = 0;
      for (int j = 0; j < n; j++)
         total = total + magic_square[i][j];
      if (i == 0) sum = total;
      else if (sum != total)
      {
         cout << "Not a magic square.\n";
         return 0;
      }
   }

   /* sum up each column */
   for (i = 0; i < n; i++)
   {
      int total = 0;
      for (int j = 0; j < n; j++)
         total = total + magic_square[j][i];
      if (sum != total)
      {
         cout << "Not a magic square.\n";
         return 0;
      }
   }
   
   /* sum up the first diagonal */
   int total = 0;
   for (i = 0; i < n; i++)
      total = total + magic_square[i][i];
   if (sum != total)
   {
      cout << "Not a magic square.\n";
      return 0;
   }
   /* sum up the second diagonal */
   total = 0;
   for (i = 0; i < n; i++)
      total = total + magic_square[i][n - 1 - i];
   if (sum != total)
   {
      cout << "Not a magic square.\n";
      return 0;
   }

   cout << "It is a magic square.\n";
   return 0;
}
