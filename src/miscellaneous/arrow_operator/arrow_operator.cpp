# include "header.h"
# include <iostream>
#include <string>
using namespace std;  
int main ()
{
	Record *p;
	p = new Record;
	p->number = 2001;
	p->grade = 'A';
	p->next = NULL;
	p-> item = "Wilbur's brother Orville" ;
	cout << p->number << endl;
	cout << p->grade << endl;
	cout <<p->next << endl;
	cout <<p->item << endl;
	system ("PAUSE");
	return 0;
}