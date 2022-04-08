#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool found(char square[5][5], char s)
{
   for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
         if (square[i][j] == s)
            return true;
   return false;
}

void make_encryption_key(string k, char out[5][5])
{
   string in = k + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int i;
   int row = 0;
   int col = 0;
     
   for (i = 0; i < in.length(); i++)
   {
      char s = toupper(in[i]);
      if (s == 'J') s = 'I';
      if (!found(out, s))
      {
         out[row][col] = s;
         col++;
         if (col == 5)
         {
            row++;
            col = 0;
         }
      }
   }
}
   
void usage()
{
   cout << "Usage: crypt [-d] [-kn] infile outfile";
}


void open_file_error(string filename)
{
   cout << "Error opening file " << filename;
}

void crypt(char& s, char& t, char key[5][5])
{
   int r1 = -1;
   int r2 = -1;
   int c1 = -1;
   int c2 = -1;
   int i;
   int j;

   s = toupper(s);
   t = toupper(t);
   if (s == 'J') s = 'I';
   if (t == 'J') t = 'I';

   for (i = 0; i < 5; i++)
      for (j = 0; j < 5; j++)
      {
         if (key[i][j] == s)
         {
            r1 = i;
            c1 = j;
         }
         if (key[i][j] == t)
         {
            r2 = i;
            c2 = j;
         }
      }

   if (r1 == -1 || r2 == -1) 
      return;
      /* one of them wasn't a letter */
   s = key[r1][c2];
   t = key[r2][c1];
}

void crypt_file(ifstream& in, ofstream& out, char key[5][5])
{
   int n = 0;
   while (true)
   {
      char c1;
      in.get(c1);
      if (in.fail()) return;
      char c2;
      in.get(c2);
      if (in.fail()) { out.put(c1); return; }
      crypt(c1, c2, key);
      out.put(c1);
      out.put(c2);
   }
}


int main(int argc, char* argv[])
{
   bool decrypt = false;
   string k;
   int nfile = 0;
   ifstream infile;
   ofstream outfile;

   if (argc < 3 || argc > 4) usage();

   int i;
   for (i = 1; i < argc; i++)
   {
      string arg = string(argv[i]);
      if (arg.length() >= 2 && arg[0] == '-')
      /* it is a command line option */
      {
         char option = arg[1];
         if (option == 'k')
            k = arg.substr(2, arg.length() - 2);
      }
      else
      {
         nfile++;
         if (nfile == 1)
         {
            infile.open(arg.c_str());
            if (infile.fail()) open_file_error(arg);
         }
         else if (nfile == 2)
         {
            outfile.open(arg.c_str());
            if (outfile.fail()) open_file_error(arg);
         }
      }
   }

   if (nfile != 2) usage();

   char key[5][5];
   make_encryption_key(k, key);

   crypt_file(infile, outfile, key);
   infile.close();
   outfile.close();
   return 0;
}

