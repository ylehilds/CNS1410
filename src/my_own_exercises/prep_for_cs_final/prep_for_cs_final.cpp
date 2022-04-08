#include <iostream>
#include <cmath>
using namespace std;
class test
{
	int value;
public:
	test()
	{
		value =10;
	}
	test(int n)
	{
		value = n;
	}
	int getvalue(){
		return value;
}
friend const int operator+(test& cool, test& dude);
friend const int operator-(test& cool, test& dude);
friend const int operator>(test& cool, test& dude);
};
const int operator+(test& cool, test& dude)
{
	int temp = cool.getvalue() + dude.getvalue();
	return temp;
}
const int operator-(test& cool, test& dude)
{
	int temp = abs(cool.getvalue() - dude.getvalue());
	return temp;
}
const int operator>(test& cool, test& dude)
{
	bool temp = (cool.getvalue() > dude.getvalue());
	return temp;
}
int add(int x)
{
	x+=x;
	return x;
}
int main()
{
	test mano, mano1(5);
	if (mano > mano1)
	{
		cout << "mano is bigger than mano1" << endl;
	}
	cout << "the difference from mano and mano1 is: " << mano - mano1 << endl;
	cout << "the addition from mano and mano1 is: " << mano + mano1 << endl;
}