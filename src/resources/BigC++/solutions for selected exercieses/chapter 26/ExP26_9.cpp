#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/** 
   Converts a string to an integer, e.g. "3" -> 3.
   @param s a string representing an integer
   @return the equivalent integer
*/   
int string_to_int(string s)
{  
   istringstream instr(s);
   int n;
   instr >> n;
   return n;
}

/**
  Encrypter is the base class for the Strategy design pattern
  Each subclass must know how to encrypt or descript a file
*/
class Encrypter 
{
public:
   virtual void encrypt_file(istream& in, ostream& out, bool decrypt) = 0;
};

/**
  A CaesarEncrypter is the strategy class the embodies
  the Caesar cypher idea
*/

class CaesarEncrypter : public Encrypter
{
public:
   CaesarEncrypter(string k);
   virtual void encrypt_file(istream& in, ostream& out, bool decrypt);
private: 
   int key;
   char encrypt(char ch);
   char decrypt(char ch);
   int remainder(int a, int n);
};

CaesarEncrypter::CaesarEncrypter(string k)
{
   key = string_to_int(k);
}

/**
   Computes correct remainder for negative dividend.
   @param a an integer
   @param n an integer > 0
   @return the mathematically correct remainder r such that
      a - r is divisible by n and 0 <= r and r < n
*/
int CaesarEncrypter::remainder(int a, int n)
{  
   if (a >= 0)
      return a % n;
   else
      return n - 1 - (-a - 1) % n;
}

char CaesarEncrypter::encrypt(char ch)
{
   const int NLETTER = 'Z' - 'A' + 1;
   if ('A' <= ch && ch <= 'Z')
      return static_cast<char>(
         'A' + remainder(ch - 'A' + key, NLETTER));
   if ('a' <= ch && ch <= 'z')
      return static_cast<char>(
         'a' + remainder(ch - 'a' + key, NLETTER));
   return ch;
}

char CaesarEncrypter::decrypt(char ch)
{
   key = -key;
   char result = encrypt(ch);
   key = -key;
   return result;
}

void CaesarEncrypter::encrypt_file
   (istream& in, ostream& out, bool dec)
{
   char ch;
   while (in.get(ch))
      if (dec)
         out.put(encrypt(ch));
      else
         out.put(decrypt(ch));
}

/**
  A Playfair class is the strategy that embodies the playfair
  cypher concept
*/

class PlayfairEncrypter : public Encrypter
{
public:
   PlayfairEncrypter(string k);
   virtual void encrypt_file(istream& in, ostream& out, bool decrypt);
private: 
   void crypt(char& s, char& t);
   bool found(char s);
   char square[5][5];
};

bool PlayfairEncrypter::found(char s)
{
   for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
         if (square[i][j] == s)
            return true;
   return false;
}

PlayfairEncrypter::PlayfairEncrypter(string k)
{
   string in = k + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int i;
   int row = 0;
   int col = 0;
     
   for (i = 0; i < in.length(); i++)
   {
      char s = toupper(in[i]);
      if (s == 'J') s = 'I';
      if (!found(s))
      {
         square[row][col] = s;
         col++;
         if (col == 5)
         {
            row++;
            col = 0;
         }
      }
   }
}
   
void PlayfairEncrypter::crypt(char& s, char& t)
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
         if (square[i][j] == s)
         {
            r1 = i;
            c1 = j;
         }
         if (square[i][j] == t)
         {
            r2 = i;
            c2 = j;
         }
      }

   if (r1 == -1 || r2 == -1) 
      return;
      /* one of them wasn't a letter */
   s = square[r1][c2];
   t = square[r2][c1];
}

void PlayfairEncrypter::encrypt_file
   (istream& in, ostream& out, bool decrypt)
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
      crypt(c1, c2);
      out.put(c1);
      out.put(c2);
   }
}

/**
   Prints usage instructions.
   @param program_name the name of this program
*/
void usage(string program_name)
{  
   cout << "Usage: " << program_name
      << " [-d] [-kn] infile outfile\n";
   exit(1);
}

/**
   Prints file opening error message
   @param filename the name of the file that could not be opened
*/
void open_file_error(string filename)
{  
   cout << "Error opening file " << filename << "\n";
   exit(1);
}

int main(int argc, char* argv[])
{  
   bool decrypt = false;
   int key = 3;
   int nfile = 0; /* the number of files specified */
   ifstream infile;
   ofstream outfile;
   //Encrypter* crypter = new CaesarEncrypter("3");
   Encrypter* crypter = new PlayfairEncrypter("playfair");

   if (argc < 3 || argc > 5) usage(string(argv[0]));

   int i;
   for (i = 1; i < argc; i++)
   {  
      string arg = string(argv[i]);
      if (arg.length() >= 2 && arg[0] == '-')
      /* it is a command line option */
      {  
         char option = arg[1];
         if (option == 'd')
         decrypt = true;
         else if (option == 'k')
	 //crypter = new CaesarEncrypter(arg.substr(2, arg.length() - 2));
	 crypter = new PlayfairEncrypter(arg.substr(2, arg.length() - 2));
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

   if(nfile != 2) usage(string(argv[0]));

   crypter->encrypt_file(infile, outfile, decrypt);
   infile.close();
   outfile.close();
   return 0;
}
