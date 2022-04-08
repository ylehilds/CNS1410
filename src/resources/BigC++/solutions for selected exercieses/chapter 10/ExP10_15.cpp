#include <iostream>

using namespace std;

int main()
{
   int buffer_capacity = 1000;
   int lines_capacity = 100; 
   char* buffer = new char[buffer_capacity];
   char** lines = new char*[lines_capacity];
   int buffer_size = 0;
   int lines_size = 0;

   bool more = true;
   bool newline = true;
   while (more)
   {
      char c = cin.get();
      if (cin.fail()) more = false;
      else
      {
         if (buffer_size >= buffer_capacity) 
         {
            char* new_buffer = new char[2 * buffer_capacity];
            for (int i = 0; i < buffer_capacity; i++)
               new_buffer[i] = buffer[i];
            for (int i = 0; i < lines_size; i++)
               lines[i] = new_buffer + (lines[i] - buffer);
            buffer = new_buffer;
            buffer_capacity = 2 * buffer_capacity;
         }
         if (newline)
         {
            if (lines_size >= lines_capacity)
            {
               char** new_lines = new char*[2 * lines_capacity];
               for (int i = 0; i < lines_capacity; i++)
                  new_lines[i] = lines[i];
               lines = new_lines;
               lines_capacity = 2 * lines_capacity;
            }
            lines[lines_size] = buffer + buffer_size;
            lines_size++;
            newline = false;
         }
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
   for (int i = lines_size - 1; i >= 0; i--)
      cout << lines[i] << "\n";
   return 0;
}
