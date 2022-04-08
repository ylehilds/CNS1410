#include <iostream>
using namespace std;

class A {
	int n;
public:
	A (int x) {
		cout << "creating A with" << n << endl;
		n = x;
	}
		~A () {
			cout << "destroying A containing " << n << endl;
		}
		void display () {
			cout << "A part = " << n << endl;
		}
	};
	class B : public A {
		string  s;
		public: 
		B (int a, string b): A(a), s(b) {
			cout << "creating B with" << b<< endl;
			s=b;
		}
			~B()
			{
				cout << "destroying B containing " << n << endl;
			}
			void display () {
				A:: display();
				cout << "B part =  " << s << endl;
			}
		};
		class C : public A {
		B b1;
			B b2;
		public: 
			C (int a, int a1, string s1, int a2, string s2);
					b2(a2,s2), b1(a1, s1), A(a) {}
		};
		int main ()
		{
		B b(1, "two");
b.display();		
b.f();
C c(1,2,"two", 3, "three");
			return 0;
		}