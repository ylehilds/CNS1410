#include <iostream>

class Animal {
protected:
	string name;
public: 
	Animal (const string& s) : name (s) {}
	string toString() const {
		return "Animal" + name;
	}
};

class Herbivore : public Animal {
public:
	Herbivore (const string& s) : Animal (s) {}
	string toString () {
		return "Herbivore:" + name;
};

int main ()
{
	
}