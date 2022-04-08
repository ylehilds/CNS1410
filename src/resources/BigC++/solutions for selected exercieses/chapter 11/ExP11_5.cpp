#include <iostream>

using namespace std;

#include "ccc_time.h"

class B
{
public:
   B();
   virtual int p(int n);
   int q(int n);
};

B::B() {}
int B::p(int n) { return n; }
int B::q(int n) { return n; }

class D : public B
{
public:
   D();
   virtual int p(int n);
   int q(int n);
};

D::D() {}
int D::p(int n) 
{
   int r; 
   for (int i = 0; i < n; i++) r = r + i; 
   return r; 
}

int D::q(int n)
{
   int r; 
   for (int i = 0; i < n; i++) r = r + i; 
   return r; 
}


int main()
{
   B* pd = new D;    /* pd will point to a D object */
   const long NTRIES = 30000000;

   cout << "Please wait...performing " << NTRIES << " iterations of dynamic binding calls.\n";
   Time start_dyn;
   long i;
   for (i = 0; i < NTRIES; i++)
      pd->p(10); /* use dynamic binding */

   Time end_dyn;

   cout << "Please wait...performing " << NTRIES << " iterations of static binding calls.\n";
   Time start_stat;
   for (i = 0; i < NTRIES; i++)
      pd->q(10);        /* use static binding */

   Time end_stat;

   cout << "Time for dynamically bound calls: " << end_dyn.seconds_from(start_dyn) << "\n";
   cout << "Time for statically bound calls: " << end_stat.seconds_from(start_stat) << "\n";

   return 0;
}
