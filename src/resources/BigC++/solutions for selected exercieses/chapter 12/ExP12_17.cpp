#include <fstream>
#include <string>

using namespace std;

bool find(string s, string t)
{
   int i;
   int imax = t.length() - s.length();
   for (i = 0; i <= imax; i++)
   {
      if (s == t.substr(i, s.length())) return true;
   }
   return false;
}

int main(int argc, char* argv[])
{
   if (argc < 3)
   {
      cout << "Usage: ExP10_17 keyword sourcefile1 sourcefile2 . . .";
      return 1;
   }
   for (int i = 2; i < argc; i++)
   {
      ifstream in;
      in.open(argv[i]);
      bool more = true;
      while (more)
      {
         string line;
         getline(in, line);
         if (in.fail()) 
            more = false;
         else if (find(argv[1], line))
            cout << argv[i] << ": " << line << "\n";
      }
      in.close();
      return 0;
   }
}
