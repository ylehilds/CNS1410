#include "classes.h"
#include <iostream>
using namespace std;
void print(Node*);
int main()
{
	system ("TITLE Linked List by Lehi Alcantara");
	system("COLOR E");
	cout << "the original list is: " << endl;
	Node* p1 = new Node;
	p1->setQuantity("1 gallon");
	p1->setItem("milk");
	//cout << p1->getQuantity();
	//cout << p1->getItem();
	Node* p2 = new Node;
	p2->setQuantity("2 loaves");
	p2->setItem("bread");
	Node* p3 = new Node;
	p3->setQuantity("1 dozen");
	p3->setItem("eggs");
	Node* p4 = new Node;
	p4->setQuantity("1 package");
	p4->setItem("bacon");
	Node* p5 = new Node;
	p5->setQuantity("2 pounds");
	p5->setItem("hamburger");
	Node* p6 = new Node;
	p6->setQuantity("1 dozen");
	p6->setItem("hamburger buns");
	List theList;
	theList.push_back(p1); 
	theList.push_back(p2);
	theList.push_back(p3);
	theList.push_back(p4); 
	Node* iter = theList.getfirst();
	print(iter);
	cout << "after adding two more items we get: " << endl;
	theList.push_front(p5); 
	theList.push_front(p6); 
	iter = theList.getfirst();
	print(iter);
	return 0;
}
void print(Node* q)
{
	while (q !=0)
	{
		cout << q->getQuantity() << ' '<< q->getItem() << endl;
		q = q->getNext();
	}
}