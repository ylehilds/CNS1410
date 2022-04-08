#include <iostream>
using namespace std;

class A {
    int n;
public:
    A(int x) : n(x) {
        cout << "Creating A with " << x << endl;
    }
    ~A() {
        cout << "Destroying A containing " << n << endl;
    }
    void display() const {
        cout << "A part = " << n << endl;
    }
    void f() {
        cout << "A function in A\n";
    }
};

class B : public A {
    string s;
public:
    B(int a, string b) : A(a), s(b) {
        cout << "Creating B with " << b << endl;
    }
    ~B() { 
        cout << "Destroying B containing " << s << endl;
    }
    void display() const {
        A::display();
        cout << "B part = " << s << endl;
    }
};

class C : public A {
    B b1;
    B b2;
public:
    C(int a, int a1, string s1, int a2, string s2) :
        A(a), b1(a1,s1), b2(a2, s2) {}
};

int main() {
    C c(1, 2, "two", 3, "three");
}
