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
#include "linked_list_header.h"

using namespace std; 
template<class T>
void printList(Node<T>*);
int main() {
	cout << "Student: Lehi Alcantara "  << endl <<"section: 002" <<endl <<"Project Two" << endl <<endl;
	int input =1;
	int input1 =2;
	int input2 =3;
	int input3 =4;
	int input4 =5;
	int input5 =6;
	int input6 =7;
	int input7 =8; 
	int input8 =9; 
	int input9 =10;
	int input10 =11;
	int input11 =12;
 List<int> theList;
 Node<int>* p1 = new Node; 
 p1->setQty(input1);
 Node<int>* p2 = new Node;
 p2->setQty(input3);
 Node<int>* p3 = new Node;
 p3->setQty(input5);
 Node<int>* p4 = new Node;
 p4->setQty(input7);
 theList.push_back(p1); 
 theList.push_back(p2);
 theList.push_back(p3);
 theList.push_back(p4); 
  
 //cout << theList.getCount() << endl;
cout << "The Original List: " << endl << endl;
Node* iter = theList.getFirst();
printList(iter);
system("PAUSE");
return 0; 
 
}
template<class T>
void printList(Node<T>* iter)
{
while (iter != 0) {
  cout << iter->getQty() << ' '
       << iter->getItem() << endl;
  iter = iter->getNext();
 }
}
//-------------------------------------------------------------------------

