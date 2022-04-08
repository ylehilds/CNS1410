#include <fstream>
#include <string>

using namespace std;

void count(ifstream& in)
{
   long chars = 0;
   long words = 0;
   long lines = 0;
   bool more = true;
   bool insideWord = false;

   while (more)
   {
      char ch;
      in.get(ch);
      if (in.fail())
         more = false;
      else
      {
         chars++;
         if (ch == '\n') lines++;
         if (ch == ' ' || ch == '\n' || ch == '\t')
         {
            if (insideWord)
               words++;
            insideWord = false;
         }
         else
            insideWord = true;
      }
   }
   cout << chars << " characters, "
      << words << " words, "
      << lines << " lines.\n";
}


int main()
{
   bool more = true;
   while (more)
   {
      cout << "Enter filename: ";
      string fname;
      cin >> fname; 
      ifstream input_data;
      input_data.open(fname.c_str());
      if (input_data.fail())
         more = false;
      else
      {
         count(input_data);
         input_data.close();
      }
   }
   return 0;
}
   
