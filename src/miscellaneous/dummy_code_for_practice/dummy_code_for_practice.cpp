/*
#include <iostream>
using namespace std;
void reverse(char* word)
{
	int size = strlen(word);
	char *p1 = word;
	for (int i=0;i<size; i++)
	{
		char temp;
		temp = p1[i];
		p1[i] = p1[size-1];
		p1[size-1] = temp;
		size--;
	}
}
int main()
{
	cout << "Please enter a phrase" << endl;
	char input[80];
	cin.getline(input,79);
	reverse(input);
	cout << endl << input << endl;
	system("PAUSE");
	return 0;
}
*/
