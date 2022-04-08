#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{  
   cout << "Enter the drive letter: "; 
   string drive; 
   cin >> drive; 

   cout << "Enter the path (\\[dir-name]\\...[dir-name]): "; 
   string path; 
   cin >> path; 

   cout << "Enter the file name without extension: "; 
   string filename; 
   cin >> filename; 

   cout << "Enter the file extension: "; 
   string extension; 
   cin >> extension; 

   cout << "The complete file name is " << drive + ":" + path + "\\" 
      + filename + "." + extension + "\n"; 

   return 0; 
} 
  
