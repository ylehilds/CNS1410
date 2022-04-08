#include <iostream>

using namespace std;

int main()
{
   const int BUFFER_CAPACITY = 1000;
   const int LINES_CAPACITY = 100; 
   char buffer[BUFFER_CAPACITY];
   char* lines[LINES_CAPACITY];
   int buffer_size = 0;
   int lines_size = 0;

   bool more = true;
   bool newline = true;
   while (more)
   {
      char c = cin.get();
      if (cin.fail()) more = false;
      else if (buffer_size >= BUFFER_CAPACITY) more = false;
      if (newline)
      {
         if (lines_size < LINES_CAPACITY)
         {
            lines[lines_size] = buffer + buffer_size;
            lines_size++;
            newline = false;
         }
         else more = false;
      }
      if (more)
      {
         if (c == '\n')
         {
            buffer[buffer_size] = '\0';
            buffer_size++;
            newline = true;
         }
         else
         {
            buffer[buffer_size] = c;
            buffer_size++;
         }
      }
   }
   buffer[BUFFER_CAPACITY - 1] = '\0';
   for (int i = lines_size - 1; i >= 0; i--)
      cout << lines[i] << "\n";
   return 0;
}
