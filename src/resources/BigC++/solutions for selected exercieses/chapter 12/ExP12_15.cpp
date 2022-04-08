#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      cout << "Usage: ExP10_14 sourcefile targetfile";
      return 1;
   }
   ifstream in;
   in.open(argv[1]);
   ofstream out;
   out.open(argv[2]);
   bool more = true;
   while (more)
   {
      char ch;
      in.get(ch);
      if (in.fail()) more = false;
      else out.put(ch);
   }
   in.close();
   out.close();
   return 0;
}
