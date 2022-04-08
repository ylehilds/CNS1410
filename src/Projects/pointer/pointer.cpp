#include <iostream>
using namespace std;
int main()
{
	int size;
	cout << "Please inser the number of integers that you would like me to reverse the order: " << endl;
	cin >> size;
	int *Pointer = new int [size];
	
		
	for (int i=0; i < size; i++)
	{
		int number;
		cout << "Please inser the number: " << endl;
		cin >> number;
		Pointer[i] = number;
	}
	int length = size;
	int j = length -1;
	for (int i  = 0; i < length-1; i++)
	{
		if (i>=j) 
		{
			break;
		}
		int temp = Pointer[i];
		Pointer[i] = Pointer[j];
		Pointer [j] = temp;
		j--;
	}
	for (int i=0; i < size; i++)
	{
		cout << Pointer[i] << endl;
	}
	delete [] Pointer;
	system("PAUSE");
	return 0;
}
