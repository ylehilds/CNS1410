/*#include <iostream>
using namespace std;
class dividebyzero
{
};
double divide (double x, double y);
int main()
{
	double input, input1;
	string answer;
	do
	{
	cout<< "Please input a number" ;
	cin >> input;
	cout<< endl << "Please input another number"; 
	cin >> input1;
	try
	{
	cout <<"the division of the 2 numbers is: "<< divide(input, input1) << endl;
	}
	catch (dividebyzero& z)
	{
		cout << "can not divide by zero";
	}
	
	cout << "whould you like to try again? " << endl;
	cin >> answer;
	}while (answer !="no");
	return 0;
}

double divide (double x, double y)
{
	if (y ==0)
	{
		throw dividebyzero();
	}
	double temp = x/y;
	return temp;
}


#include <iostream>
using namespace std;
class dividebyzero
{
public:
	dividebyzero()
	:message("no div by zero\n")
	{}
	const char* what() const {return message;}
private: 
	const char* message;
};
double divide (double x, double y);
int main()
{
	double input, input1;
	string answer;
	do
	{
	cout<< "Please input a number" ;
	cin >> input;
	cout<< endl << "Please input another number"; 
	cin >> input1;
	try
	{
	cout <<"the division of the 2 numbers is: "<< divide(input, input1) << endl;
	}
	catch (dividebyzero& z)
	{
		cout << z.what();
	}
	
	cout << "whould you like to try again? " << endl;
	cin >> answer;
	}while (answer !="no");
	return 0;
}

double divide (double x, double y)
{
	if (y ==0)
	{
		throw dividebyzero();
	}
	double temp = x/y;
	return temp;
}


#include <iostream>
using namespace std;
class constructor
{
	int value;
public:
	constructor()
	{
		cout << "I was created" << endl;
	}
	~constructor()
	{
		cout << "I was destroyed" << endl;
	}
};
int main()
{
	constructor lehi;
	return 0;
}


#include <iostream>
using namespace std;
int main()
{
	cin.exceptions(ios_base:: badbit | ios::failbit);
	int a, number1;
	do{
	try
	{
		cout <<"input a number: " << endl;
		cin >> number1;
		cout << "you typed : " << number1 << endl;
	}
	catch (ios_base::failure q)
	{
		cin.clear();
		cin.ignore(80,'\n');
		cout <<"you typed a wrong input" << endl;
	}
	}while (number1 != 0);
		return 0; 
}

#include <iostream>
using namespace std;
template <class T>
T biggest (T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	float my, mine;
	cout << "please input a number" ; 
	cin >> my ;
	cout << "please input another number" ;
	cin >> mine;
	
	cout << "the bigger number from those two numners is: "<< biggest(my,mine); 
	return 0;
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
bool howmany(int i) {return (i>=0);} 
bool overtime (int i) {return (i>40);}
bool zero (int i) {return (i==0);}
int main ()
{
	vector <int> lehi;
	int hours;
	ifstream read;
	read.open("c:\\hourly.txt");
	while (!read.eof())
	{
		read >> hours;
		lehi.push_back(hours);
	}
	
	vector <int> :: iterator p1;
	vector <int> :: iterator p2;
	
	p1 = lehi.begin();
	p2 = lehi.end();
	
	int num = count_if (p1,p2,howmany);
	cout << "the amount of workers are: " << num << endl;
	int num1 = count_if (p1,p2,overtime);
	cout << "the amount of workers who worked overtime are: " << num1 << endl;
	int num2 = count_if (p1,p2,zero);
	cout << "the amount of workers who did not work are: " << num2 << endl;
	system ("PAUSE");
	return 0;
}