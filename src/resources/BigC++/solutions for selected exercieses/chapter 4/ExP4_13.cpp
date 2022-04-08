#include <iostream>
#include <string>

using namespace std;

int main()
{  
   cout << "Please enter three strings: ";      

   string s1;
   string s2;             
   string s3;

   cin >> s1 >> s2 >> s3;      
          
   string swap;
          
   if (s1 < s2)
   {
      if (s1 < s3) /* s1 is smallest */
      {
         cout << s1 << "\n";
         if (s2 < s3)
         {  
            cout << s2 << "\n";
            cout << s3 << "\n";
         }
         else
         {  
            cout << s3 << "\n";
            cout << s2 << "\n";
         }
      }
      else /* s3 is smallest */
      {
         cout << s3 << "\n";
         cout << s1 << "\n";
         cout << s2 << "\n";
      }
   }
   else if (s2 < s3) /* s2 is smallest */
   {  
      cout << s2 << "\n";
      if (s1 < s3)
      {  
         cout << s1 << "\n";
         cout << s3 << "\n";
      }
      else
      {  
         cout << s3 << "\n";
         cout << s1 << "\n";
      }
   }
   else /* s3 is smallest */
   {  
      cout << s3 << "\n";
      cout << s2 << "\n";
      cout << s1 << "\n";
   }
   
   return 0;
}
    
