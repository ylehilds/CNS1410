#include <iostream>
#include <string>
using namespace std;
int main()
{
	enum month {january=1, february, march, april, may, june, july, august, september, october, november, december};
	cout << "Pick a month to see the holiday in that month. Enter 1 for january, 2 for february... \n"; 
	string holiday;
	int selection;
	cin >> selection;
	switch(selection)
	{
	case january:
		holiday = " 1 -> new years, 18 -> Martin Luther King Jr.";
		break;
	case february:
		holiday = " 14 -> Valentine's day, 15-> President's day";
		break;
	case march:
		holiday = " 17 -> Saint Patrick's day";
		break;
	case april:
	holiday = " 4 -> Easter";
	break;
case may:
	holiday = " 9 -> mom's day, 31 -> Memorial day";
	break;

		case june:
		holiday = " 20 -> Father's day.";
		break;
	case july:
		holiday = " 4 -> Independence day";
		break;
	case august:
		holiday = " nothing :-(";
		break;
	case september:
	holiday = " 6 -> Labor day";
	break;
case october:
	holiday = " 11 -> Columbus day, 31 -> Halloween";
	break;
	
		case november:
	holiday = " 11 -> Veterans day, 25 -> Thanksgiving";
	break;
case december:
	holiday = " 2 -> Hanukkah, 25 -> Christmas";
	break;
default:
	holiday = " nada";
	break;
	}
	cout << holiday <<"\n";
	system("PAUSE");
	return 0;
	
}
