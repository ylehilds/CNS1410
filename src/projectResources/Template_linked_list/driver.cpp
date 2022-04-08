// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002    
// Professor: Charles Allison  
// Project: Project Ten
// Date Written: September 14th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.

#include <iostream>
#include <string>
#include "linked_header.h"
using namespace std;

template<class T>

void display(List<T>& x) {

for (Iterator<float> iter = x.begin(); iter != x.end(); ++iter)

cout << *iter << endl;

cout << "size = " << x.size() << endl;

} 

int main() {
system ("TITLE LEHI ALCANTARA'S PROJECT 09 - CNS 1410");
system("COLOR E"); 
cout << "Student: Lehi Alcantara "  << endl <<"section: 002" <<endl <<"Project Ten" << endl <<endl;
	

List<float> lst;

for (int i = 0; i < 5; ++i)

lst.push_back(i/10.0);

display(lst);

List<float> lst2(lst);

display(lst2);

List<float> lst3;

cout << "size = " << lst3.size() << endl;

lst3 = lst;

display(lst3);
system ("PAUSE");
return 0;
}

/* Output:

0

0.1

0.2

0.3

0.4

size = 5

0

0.1

0.2

0.3

0.4

size = 5

size = 0

0

0.1

0.2

0.3

0.4

size = 5

*/

