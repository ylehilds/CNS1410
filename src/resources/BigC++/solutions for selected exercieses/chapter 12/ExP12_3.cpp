#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
   cout << "Filename: ";
   string f;
   getline(cin, f);
   ifstream in;
   in.open(f.c_str());

   vector<int> freqs('Z' - 'A' + 1);
   int i;
   for (i = 0; i < freqs.size(); i++)
      freqs[i] = 0;
      
   int total = 0;
   bool more = true;
   while (more)
   {
      char ch;
      in.get(ch);
      if (in.fail()) more = false;
      else
      {
         ch = toupper(ch);
         if ('A' <= ch && ch <= 'Z')
         {
            freqs[ch - 'A']++;
            total++;
         }
      }
   }

   in.close();

   if (total != 0)
   {
      for (i = 0; i < freqs.size(); i++)
      {
         char c = 'A' + i;
         cout << c << ":" 
              << (100.0 * freqs[i] / total) << "%" << "\n";
      }
   }

   return 0;
}
