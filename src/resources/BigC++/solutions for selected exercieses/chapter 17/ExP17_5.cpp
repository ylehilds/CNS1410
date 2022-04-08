#include <iostream>

using namespace std;

class Complex {
public:
   Complex(double r, double i);
   Complex operator+(const Complex& right) const;
   Complex operator-(const Complex& right) const;
   Complex operator*(const Complex& right) const;
   Complex& operator+=(const Complex& right);
   Complex& operator*=(const Complex& right);
   friend ostream& operator<<(ostream& out, const Complex& right);
private:
   double real, imag;
};

Complex::Complex(double r, double i) : real(r), imag(i) { }

Complex Complex::operator+(const Complex& right) const
{
   return Complex(real + right.real, imag + right.imag);
}

Complex Complex::operator-(const Complex& right) const
{
   return Complex(real - right.real, imag - right.imag);
}

Complex Complex::operator*(const Complex& right) const
{
   return Complex(real * right.real - imag * right.imag,
      real * right.imag + imag * right.real);
}

ostream& operator<<(ostream& out, const Complex& right)
{
   out << "[" << right.real << "," << right.imag << "]";
   return out;
}

Complex& Complex::operator+=(const Complex& right)
{
   real += right.real;
   imag += right.imag;
   return *this;
}

Complex& Complex::operator*=(const Complex& right)
{
   Complex clone(*this);
   Complex result = clone * right;
   real = result.real;
   imag = result.imag;
   return *this;
}

int main()
{
   Complex a(2, 3);
   Complex b(3, 4);
   cout << a << b << (a + b) << (a - b) << (a * b) << "\n";
}
