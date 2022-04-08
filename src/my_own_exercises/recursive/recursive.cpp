#include <iostream>
using namespace std;
int wpower (int n, int p)
{
   if (p > 0)
      return ( wpower (n, p-1) * n);  
   else
      return (1);
}

int main()
{
	cout << wpower(2,6);
	return 0;
}