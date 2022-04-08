// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002   
// Professor: Charles Allison
// Project: Project two
// Date Written: September 8th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.

#include <iostream>
#include "header.h"
using namespace std; 
void printList(Node*);
int main() {
	cout << "Student: Lehi Alcantara "  << endl <<"section: 002" <<endl <<"Project Two" << endl <<endl;
 List theList;
 Node* p1 = new Node; 
 p1->setItem("milk");
 p1->setQty("1 gallon of");
 Node* p2 = new Node;
 p2->setItem("bread");
 p2->setQty("2 loaves");
 Node* p3 = new Node;
 p3->setItem ("eggs");
 p3->setQty("1 dozen");
 Node* p4 = new Node;
 p4->setItem ("bacon");
 p4->setQty("1 package");
 theList.push_back(p1); 
 theList.push_back(p2);
 theList.push_back(p3);
 theList.push_back(p4); 
  
 //cout << theList.getCount() << endl;
cout << "The Original List: " << endl << endl;
Node* iter = theList.getFirst();
printList(iter);
Node* p5 = new Node;
p5-> setItem ("hamburger");
p5->setQty ("2 pounds");
Node* p6 = new Node;
p6-> setItem ("hamburger buns");
p6->setQty ("1 dozen of");
//theList.insertNode ( p1, p5 );
theList.push_front (p5);
//theList.insertNode(p2, p6);
theList.push_front(p6);
cout << endl << "After adding to the front of the List: " << endl << endl;
iter = theList.getFirst();
printList(iter); 
cout << endl << "After removing first and last items from the list" << endl;
delete theList.pop_back();
delete theList.pop_front();
cout << endl;
iter = theList.getFirst(); 
printList(iter);
system("PAUSE");
return 0; 
 
}
void printList(Node* iter)
{
while (iter != 0) {
  cout << iter->getQty() << ' '
       << iter->getItem() << endl;
  iter = iter->getNext();
 }
}
//-------------------------------------------------------------------------

