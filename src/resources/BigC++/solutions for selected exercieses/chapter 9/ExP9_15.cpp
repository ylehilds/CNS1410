#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void rand_seed()
{
   int seed = static_cast<int>(time(0));
   srand(seed);
}

int rand_int(int a, int b)
{
   return a + rand() % (b - a + 1);
} 

vector<int> random_permutation(int n)
{
   int i;
   vector<int> numbers(n);
   for (i = 1; i <= n; i++)
      numbers[i - 1] = i;
   vector<int> r(n);
   for (i = 1; i <= n; i++)
   {
      int a = rand_int(0, n - i);
      r[i - 1] = numbers[a];
      numbers[a] = numbers[n - i];
         /* move last number into the a slot */
   }
   return r;   
}

void print(vector<int> a)
{
   int i;
   for (i = 0; i < a.size(); i++)
      cout << a[i] << " ";
   cout << "\n";
}

int main()
{
   rand_seed();
   int i;
   for (i = 1; i <= 10; i++)
      print(random_permutation(10));
}
