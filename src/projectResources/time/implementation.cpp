#include "time.h"
#include <cassert>
using namespace std;

// constructor with defaults
Atime::Atime (int hrs ,int mins, int secs)
{
	seconds = hrs * SIXTY * SIXTY + mins * SIXTY + secs;
}
	
// getters for basic data elements
int Atime::getHours( ) const
{
	return seconds/(THREE_SIXTY);
}

int Atime::getMinutes( ) const
{
	return (seconds % THREE_SIXTY) / SIXTY;
}

int Atime::getSeconds( ) const
{
	return seconds % THREE_SIXTY  % SIXTY;
}
	
// overloaded operators ... only a sample of all possible
	
// a unary member function
// add one second
Atime& Atime::operator++( )
{
	seconds++;
	return *this;
}
	
	// a unary non-member function
	// void operator++(int, Time&)
Atime Atime::operator++( int )
{
	Atime tempT = *this;
	seconds++;
	return tempT;
}
	
	// a binary member function - will use implement it using arithmetic assignment
Atime Atime::operator-(const Atime& t)
{
	Atime tempT;
	tempT.seconds = seconds - t.seconds;
	return tempT;
}
	
	// an arithmentic assignment operator
Atime& operator-=(Atime& lhT, const Atime& rhT) 
{
	Atime temp = lhT - rhT;
	lhT = temp;
	return lhT;
}
	
// a comparison operator as a member function
bool Atime::operator==(const Atime& t)
{
	if (seconds == t.seconds)
		return true;
	else
		return false;
}
	
// overload [ ] to get one of hours, minutes, seconds
// element [0] is hours, [1] is minutes, [2] is seconds
int Atime::operator[ ](int n)
{
	assert(n < 3 && n > -1);
	if (n == 0)
		return getHours( );
	else if (n == 1)
		return getMinutes( );
	else
		return getSeconds( );
}
	
// overload stream insertion
ostream& operator<<(ostream& out, const Atime& t)
{
	out << t.getHours( ) << ":" << t.getMinutes( ) << ":" << t.getSeconds( );
	return out;
}

