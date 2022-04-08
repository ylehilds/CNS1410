// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002   
// Professor: Charles Allison
// Project: Project Eleven
// Date Written: November 18, 2007 
// --------------------------------------

// I declare that the following source code was written 
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
#include <numeric>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <iterator> 
using namespace std;
double sum = 0;
double counter=0;
bool howmany (int i) { return (i>=0);}
bool zero (int i) {return (i == 0);}
bool overtime (int i) {return (i>40);}
class Average
{
    private:
        long count;
        long sum;
     public:
		Average( ) : count(0), sum(0) { }
        void operator( ) (int element)
		{
			if (element>40)
				{
				   count++;
				   sum += element;
				}
		}
        double value( ) 
		{
            return static_cast<double>(sum) / static_cast<double>(count);
        }
};

int main()
{
	cout << "Author: Lehi Alcantara" << endl;
	cout << "Section: 002" << endl;
	cout << "Project Eleven" << endl;
	cout << "------------------------------------------------------------------------------"<< endl;
	string name;
	ifstream File;
	vector <int> jobHours;
do 
	{
		cout << "Enter in the file name for hourly employee data, or Type \"Quit\" to quit: " << endl;
		cin >> name;
		if (name == "Quit")
		{
			return 0;
		}
		if (name != "c:\\hourly.txt")
		{
			cout << "invalid file! " << endl;
		}
		
	} while (name != "c:\\hourly.txt");
	
	File.open(name.c_str());
	if (File.fail())
	{
		cout << "\nError opening file.";
		exit(1);
	}
	int hoursWorked=0;
	while(!File.eof())
	{
		 
		File >> hoursWorked;
		//cout << hoursWorked << endl;
		if (File.bad()) 
		{ 
			cout << "bad data or file is corrupted" << endl;
		}
		jobHours.push_back(hoursWorked);
		//cout << jobHours[hours++] << endl;
	} 
	File.close();
	vector <int>::iterator p1;
	vector <int>::iterator p2;
	p1 = jobHours.begin( );
	p2 = jobHours.end( );
	
	int num = count_if(p1,p2, howmany);
	cout << "the number of employees are: " << num << endl;
	
	int num1= count_if(p1,p2, zero);
	cout << "the number of employees who did not work this pay period: " << num1 << endl;
	
	int num2= count_if(p1,p2, overtime);
	cout << "the number of employees who worked overtime this pay period: " << num2 << endl;
	
	Average avrg = for_each (p1,p2, Average());
	cout << "the average number of overtime hours this pay period is " << avrg.value( ) << endl; 
	 
	vector <int>::const_iterator maximun  = max_element(p1, p2);
	cout << "The most hours anyone worked this pay period is: " << *maximun << endl;
	
	system("PAUSE");
	return 0;
}




