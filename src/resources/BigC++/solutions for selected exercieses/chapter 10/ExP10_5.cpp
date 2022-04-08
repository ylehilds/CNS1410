#include <iostream>

/**
   Computes the average of the values in an array
   @param a the array
   @param a_size the number of elements in the array
   @return the average, or 0 if the array is empty
*/
double average(double a[], int a_size)
{
   double sum = 0;
   double* p = a;
   for (int i = 0; i < a_size; i++)
   {
      sum = sum + *p;
      p++;
   }
   if (a_size == 0) return 0; else return sum / a_size;
}

int main()
{
   double data[] = { 1, 4, 9, 16, 25 };
   cout << average(data, 5) << "\n";
   return 0;
}
