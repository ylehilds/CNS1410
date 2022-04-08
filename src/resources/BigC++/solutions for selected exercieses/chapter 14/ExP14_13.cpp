#include <iostream>

using namespace std;

/**
   Moves n disks from the "from" peg to the "to" peg.
   @param from peg number where the disks start
   @param to peg number where the disks end up
   @param n the number of disks to move
*/
void hanoi(int from, int to, int n)
{  
   if (n == 1) /* one disk to move */
      cout << "Move disk from peg " << from << " to peg " << to << "\n";
   else
   {  
      int third = 6 - (from + to);
         /* because from, to, third are a permutation
            of 1, 2, 3, they add up to 6
         */
      hanoi(from, third, n - 1);
      hanoi(from, to, 1);
      hanoi(third, to, n - 1);
   }
}

int main()
{  
   cout << "Enter the number of disks to move: ";
   int n;
   cin >> n;

   hanoi(1, 3, n);

   return 0;
}
