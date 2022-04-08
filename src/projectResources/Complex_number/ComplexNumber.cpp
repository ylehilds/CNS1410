#include <iostream>
using namespace std;

#include "cn.h"
#pragma hdrstop

int main( )
{
   cout << "Complex Number Test ...\n";
   int rp;
   int ip;

   cout << "Enter an integer for the real part of the 1st number: ";
   cin >> rp;
   cout << "Enter an integer for the imaginary part of the 1st number: ";
   cin >> ip;
   ComplexNumber cn1( rp, ip );

   cout << "Enter an integer for the real part of the 2nd number: ";
   cin >> rp;
   cout << "Enter an integer for the imaginary part of the 2nd number: ";
   cin >> ip;
   ComplexNumber cn2( rp, ip );

   // Print them out and their sum
   cout << "\nFirst Complex Number: " << cn1;
   cout << "\nSecond Complex Number: " << cn2;
   cout << "\nTheir sum: " << (cn1 + cn2 );
   cin.ignore( 80, '\n');
   cin.get( );
   return 0;
}
//---------------------------------------------------------------------------
 
