#include <iostream>
#include <string>
using namespace std;
class Animal { 
protected:
	string name;
public: 
	Animal (const string& s) : name (s) {}
	string toString() const {
		return "Animal " + name;
	}
};

class Herbivore : public Animal {
public:
	Herbivore (const string& s) : Animal (s) {}
	string toString () {
		return "Herbivore: " + name;
	}
};
void identity (Animal *p) {
	cout << p->toString () << endl; }
int main ()
{
	Herbivore herb ("herb");
	identity(&herb);
	cout << herb.toString() << endl;
	return 0;
}
