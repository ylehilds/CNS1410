#include <iostream>
#include "array.h"
using namespace std;

int main() {
	system ("TITLE LEHI ALCANTARA'S PROJECT 08 - CNS 1410");
	system("COLOR E");
    Array a;
    for (int i = 1; i < 13; ++i)
        a.push_back(i);
    for (int i = 0; i < a.size(); ++i)
        cout << a.at(i) << endl;
	for (int i = 1; i < 13; ++i)
        a.pop_back(i);
	for (int i = 0; i < a.size(); ++i)
        cout << a.at(i) << endl;
    Array b(a);
    for (int i = 0; i < b.size(); ++i)
        cout << b.at(i) << endl;
}

