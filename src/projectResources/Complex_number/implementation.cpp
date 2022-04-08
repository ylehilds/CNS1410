// The ComplexNumber class implementation file
// Author: Roger deBry
// Date last modified: January 8, 2003
// Course: CNS 1350
// -----------------------------------------------------------

#pragma hdrstop
#include "cn.h"
#include <cmath>
using namespace std;

ComplexNumber::ComplexNumber( int rp, int ip )
{
   realPart = rp;
   imaginePart = ip;
}


ComplexNumber ComplexNumber::operator+( const ComplexNumber& rhcn )
{
   ComplexNumber tcn( realPart + rhcn.realPart, imaginePart + rhcn.imaginePart );
   return tcn;
}

ostream& operator << ( ostream& out, const ComplexNumber& cn )
{
   // write out the real part
   if( cn.realPart != 0 )
      cout << cn.realPart;
   if( cn.imaginePart != 0)
   {
      if( cn.imaginePart < 0 )
         cout << " - ";
      else
         cout << " + ";

      if( abs(cn.imaginePart) == 1)
         cout << "i";
      else
         cout << abs(cn.imaginePart) << "i";
   }
   return out;
}

