#include <fstream>
#include <string>

using namespace std;

string lookup(string className, string key)
{
   ifstream in;
   string filename = className + ".txt";
   in.open(filename.c_str());
   bool more = true;
   string r;
   while (more)
   {
      string id;
      in >> id;
      string grade;
      in >> grade;
      if (in.fail()) 
         more = false;
      else if (id == key)
      {
         r = grade;
         more = false;
      }
   }
   in.close();
   return r;
}

int main()
{
   cout << "Please enter the student ID: ";
   string id;
   cin >> id;
   cout << "Student ID " + id;
   ifstream in;
   in.open("classes.txt");
   bool more = true;
   while (more)
   {
      string className;
      getline(in, className);
      if (in.fail()) 
         more = false;
      else 
      {
         string grade = lookup(className, id);
         if (grade != "")
            cout << " " << className << " " << grade << "\n";
      }
   }
   in.close();
   return 0;
}
