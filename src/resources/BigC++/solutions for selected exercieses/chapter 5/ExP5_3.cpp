#include <iostream>

using namespace std;

/**
   Swaps values of the parameters provided the first parameter.
   @param a first input value
   @param b second input value
*/
void sort2(int& a, int& b)
{
   if (a > b)
   {
      int temp = a;
      a = b;
      b = temp;
   }
}

/**
   Sorts three integer values into ascending order.
   @param a first input value
   @param b second input value
   @param c third input value
*/
void sort3(int& a, int& b, int& c)
{
   sort2(a, b);    /* sort the first two; now a <= b */
   sort2(b, c);    /* sort the last two; now b <= c */
   sort2(a, b);    /* sort the first two in case b and c were swapped */
}

int main()
{
   int v = 3;
   int w = 4;
   int x = 1;
   sort3(v, w, x);
   cout << "After applying sort3, v, w, and x are: " 
      << v << " " << w << " " << x << "\n";

   return 0;
}
