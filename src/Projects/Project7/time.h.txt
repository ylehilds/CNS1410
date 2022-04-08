// The Time class ... used to illustrate operator overloading
// A time object represents a point in time in hours, minutes, and seconds
// using a 24 hour clock. Interesting operations would be to
// o Subtract two times 
// o Compare two times
// o output a time
// o access one of hours, minutes, or seconds as if they were an array of integers
// Time is actually held in the object as a number of seconds past midnight
// Only a few selected operators are overloaded for demonstration purposes
// ----------------------------------------------------------------------------------

#include <iostream>
using namespace std;

// some constants
const int SIXTY = 60;
const int THREE_SIXTY = SIXTY * SIXTY;

class Atime
{
private:
	int seconds;
public:
	Atime (int = 0, int = 0, int = 0);   //defaults
	
	// getters for basic data elements
	int getHours( ) const;
	int getSeconds( ) const;
	int getMinutes( ) const;
	
	// overloaded operators ... only a sample of all possible
	
	// a unary member function
	Atime& operator++( );
	
	// a unary member function
	Atime operator++( int );
	
	// a binary member function - will use implement it using arithmetic assignment
	Atime operator-(const Atime&);
	
	// a comparison operator as a member function
	bool operator==(const Atime&);
	
	// overload [ ] to get one of hours, minutes, seconds
	int operator[ ](int);
};

// non-member function prototypes
ostream& operator<<(ostream&, const Atime&);
Atime& operator-=(Atime, const Atime&);

