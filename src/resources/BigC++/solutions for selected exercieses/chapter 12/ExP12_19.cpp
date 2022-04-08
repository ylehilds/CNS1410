#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NEWLINE_LENGTH = 2;

void reverse(fstream& f, long from, long to)
{
   while (from < to)
   {
      f.seekg(from, ios::beg);
      char c1;
      f.get(c1);
      f.seekg(to, ios::beg);
      char c2;
      f.get(c2);
      f.seekp(from, ios::beg);
      f.put(c2);
      f.seekp(to, ios::beg);
      f.put(c1);
      from++;
      to--;
   }
}

int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      cout << "Usage: ExP10_19 file";
      return 1;
   }
   fstream file;
   file.open(argv[1]);
   long begin = 0;
   while (!file.fail())
   {
      char ch;
      do 
         file.get(ch);
      while (!file.fail() && ch != '\n');
      if (!file.fail())
      {
         long end = file.tellg() - NEWLINE_LENGTH;
         reverse(file, begin, end);
         begin = end + NEWLINE_LENGTH;
         file.seekg(begin, ios::beg);
      }
   }
   file.close();
   return 0;
}
   
