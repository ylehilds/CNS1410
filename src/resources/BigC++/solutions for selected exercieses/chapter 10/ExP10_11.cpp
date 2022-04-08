#include <iostream>
#include <cstring>

/**
   Concatenates two character arrays into a result array.
   @param a the first character array
   @param b the second character array
   @param result the array to hold the concatenation
   @param result_maxlength the maximum length of the result
   (not counting the '\0' terminator)
*/
void concat(const char a[], const char b[], char result[],
   int result_maxlength)
{
   int n = strlen(a);
   strncpy(result, a, result_maxlength);
   if (n < result_maxlength)
      strncat(result + n, b, result_maxlength - n); 
   result[result_maxlength] = '\0';
}

int main()
{
   char a[] = "Woozle";
   char b[] = "Heffalump";
   char c[5];
   char d[10];
   char e[20];
   concat(a, b, c, 5);
   concat(a, b, d, 10);
   concat(a, b, e, 20);
   cout << c << "\n";
   cout << d << "\n";
   cout << e << "\n";
   return 0;
}
