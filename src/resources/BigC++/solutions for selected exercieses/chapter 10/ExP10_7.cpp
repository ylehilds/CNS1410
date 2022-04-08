#include <iostream>

/**
   Reverses the values in an array
   @param a the array
*/
void reverse(double a[], int a_size)
{
   double* p = a;
   double* q = a + a_size - 1;
   while (p < q)
   {
      double temp = *p;
      *p = *q;
      *q = temp;
      p++;
      q--;
   }
}

int main()
{
   double data[] = { 1, 4, 9, 16, 25 };
   reverse(data, 5);
   for (int i = 0; i < 5; i++)
      cout << data[i] << "\n";
   return 0;
}
