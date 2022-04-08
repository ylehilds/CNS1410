// Complex Number Class - Demonstrates Operator Overloading
// Author: Roger deBry
// Date last modified: January 8, 2003
// Course: CNS 1350
// -----------------------------------------------------------
#include <iostream>
using namespace std;
#ifndef cnH
#define cnH
class ComplexNumber
{
   private:
      int realPart;
      int imaginePart;
   public:
      ComplexNumber( int, int );
      ComplexNumber operator+( const ComplexNumber& );
      friend ostream& operator<< (ostream&, const ComplexNumber& );
};
#endif

