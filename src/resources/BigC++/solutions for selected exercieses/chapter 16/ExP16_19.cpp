#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
   vector<int> v(4);
   v[0] = 1;
   v[1] = 2;
   v[2] = 3;
   v[3] = 4;
   for (int i = 1; i <= 10; i++)
   {
      random_shuffle(v.begin(), v.end());
      for (int j = 0; j < 4; j++)
      {
         cout << v[j] << " ";
      }
      cout << "\n";
   }

   return 0;
}
