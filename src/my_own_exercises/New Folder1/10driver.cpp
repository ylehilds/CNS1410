#include "list.h"
//#include <iostream>
//using namespace std; 

int main() 
{	
	/*Node<double> test(50.0);
	//Node<T>* newNode = new Node<T>(n);
	Node<double>* testPtr = new Node<double>(45.0);
	List<Node<double> > testList;
	testList.push_back(test);*/
	
	List<double> testList;
	for(int i = 0; i < 5; ++i)
	{
		testList.push_back(i/10.0);
	}
	Iterator<double> test = testList.begin();
	Iterator<double> testend = testList.end();
	
	while(test != testend)
	{
		cout << *test << endl;
		++test;
	}
	cout << endl;
	system("PAUSE");
}
