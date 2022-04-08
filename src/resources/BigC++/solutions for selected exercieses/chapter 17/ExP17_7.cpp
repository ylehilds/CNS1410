#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// note, comparison doesn't make sense, should have said multiplication

class Poly
{
public:
   Poly();
   Poly(double a);
   Poly(double a, double b);
   Poly(vector<double>& ic);
   int degree() const;
   double coeff(int i) const;
private:
   vector<double> c;
};

Poly::Poly()
{
   c.resize(0, 0.0);
}

Poly::Poly(double a)
{
  c.resize(1, 0.0);
  c[0] = a;
}

Poly::Poly(double a, double b)
{
  c.resize(2, 0.0);
  c[0] = a;
  c[1] = b;
}

Poly::Poly(vector<double>& ic)
{
   c.resize(ic.size());
   for (int i = 0; i < ic.size(); i++)
      c[i] = ic[i];
}

int Poly::degree() const
{
   return c.size()-1;
}

double Poly::coeff(int i) const
{
   if ((i >= 0) && (i <= degree()))
   	return c[i];
   return 0.0;
}

Poly operator+(const Poly& left, const Poly& right)
{
   int md = left.degree();
   if (right.degree() > md) md = right.degree();
   vector<double> coeffs(md+1, 0.0);
   for (int i = 0; i <= md; i++)
      coeffs[i] = left.coeff(i) + right.coeff(i);
   return Poly(coeffs);
}

Poly operator*(const Poly& left, const Poly& right)
{
   int md = left.degree() + right.degree();
   cout << "degrees" << left.degree() << right.degree() << md << "\n";
   vector<double> coeffs(md+1, 0.0);
   for (int i = 0; i <= left.degree(); i++)
      for (int j = 0; j <= right.degree(); j++)
	 coeffs[i+j] += left.coeff(i) * right.coeff(j);
   return Poly(coeffs);
}

ostream& operator<<(ostream& out, const Poly& a)
{
   cout << a.coeff(0);
   for (int i = 1; i <= a.degree(); i++)
      cout << " + " << a.coeff(i) << "*X^" << i;
   return cout;
}

int main() {
  Poly a(2, 3);
  Poly b(3, 4);
  cout << (a * b) << "\n";
}
