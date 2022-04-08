#include <iostream>
using namespace std;
double factorial(double number)
{
	if (number > 1)
		return number*factorial(number-1);
	return number; 
}
int main()
{
	string answer;
	do
	{
	double number;
	cout << "what is the number?" << endl;
	cin >> number;
	cout << "the factorial is: " << factorial(number) << endl;
	
	cout << "would you like to try again?" << endl;
	cin >> answer;
	} while (answer=="yes");
	return 0;
	system ("PAUSE");
}
