#include <iostream>
using namespace std;
void reverse (char[]);
int main ()
{
	cout << "Please insert a statement and I will reverse it." << endl;
	char statement[100];
	cin.getline(statement, 99);
	cout << statement << endl;
	reverse(statement);
	cout << "reversed is : " << statement<< endl;
system("PAUSE");
	return 0;
}
void reverse (char statement[99])
{
	int length = strlen(statement);
	char *start = statement;
	char *end = statement;
	for (int i=0; i < length - 1; i++)
	{
	char temp = start[i];
	start[i] = end[length-1];
	end[length-1] = temp;
	length--;
	}
}