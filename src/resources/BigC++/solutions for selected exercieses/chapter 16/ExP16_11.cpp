#include <iostream>
#include <cassert>
#include <list>

using namespace std;

class Term
{ 
public:
   Term();
   Term(double c, int d);
   int get_degree() const;
   double get_coefficient() const;
private:
   int degree;
   double coefficient;
};

Term::Term()
{
   degree = 0;
   coefficient = 0;
}

Term::Term(double c, int d)
{
   coefficient = c;
   degree = d;
}

int Term::get_degree() const
{
   return degree;
}

double Term::get_coefficient() const
{
   return coefficient;
}

class Polynomial
{ 
public:
   Polynomial();
   Polynomial(Term t);
   void add(Polynomial p);
   void add_term(Term t);
   Polynomial multiply(Polynomial p);
   void print();
private:
   list<Term> terms;
};

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(Term t)
{
   if (t.get_coefficient() != 0)
      terms.push_back(t);
}

void Polynomial::add(Polynomial p)
{
   list<Term>::iterator ppos;
   for (ppos = p.terms.begin(); ppos != p.terms.end(); ppos++)
      add_term(*ppos);
}
   
void Polynomial::add_term(Term t)   
{
   list<Term>::iterator tpos = terms.begin();
   while (tpos != terms.end() && (*tpos).get_degree()
      < t.get_degree()) tpos++;
   /* now tpos either points to a term with the same
      degree as t or to a higher one.
   */
   if (tpos != terms.end() && (*tpos).get_degree()
      == t.get_degree())
   {
      Term n(t.get_coefficient() + (*tpos).get_coefficient(),
         t.get_degree());
      list<Term>::iterator npos = tpos;
      npos++;
      terms.erase(tpos);
      if (n.get_coefficient() != 0)
         terms.insert(npos, n);
   }
   else
      terms.insert(tpos, t);
}

Polynomial Polynomial::multiply(Polynomial p)
{
   list<Term>::iterator ppos;
   list<Term>::iterator tpos;
   Polynomial r;
   for (ppos = p.terms.begin(); ppos != p.terms.end(); ppos++)
      for (tpos = terms.begin(); tpos != terms.end(); tpos++) 
   {
      r.add_term(Term((*ppos).get_coefficient() * (*tpos).get_coefficient(),
         (*ppos).get_degree() + (*tpos).get_degree()));
   }    
   return r;
}

void Polynomial::print()
{
   list<Term>::iterator pos;
   for (pos = terms.begin(); pos != terms.end(); pos++)
   {
      double c = (*pos).get_coefficient();
      int d = (*pos).get_degree();
      if (c > 0) cout << "+";
      cout << c;
      if (d > 0) cout << "*x";
      if (d > 1) cout << "^" << d;
   }
   cout << "\n";
}

int main()
{
   Polynomial p(Term(-10,0));

   p.add(Polynomial(Term(-1,1)));
   p.add(Polynomial(Term(9,2)));
   p.add(Polynomial(Term(5,3)));
   p.add(Polynomial(Term(2,4)));

   /* print all values */
   p.print();

   Polynomial q = p.multiply(p);
   q.print();

   return 0;
}
