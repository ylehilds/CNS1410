#include <cassert>
#include <iostream>
using namespace std;

class Rational {
    int num, denom;
    static int gcd(int m, int n);
public:
    Rational(int num, int denom = 1) {
        assert(denom != 0);
        int div = gcd(num, denom);
        this->num = num/div;
        this->denom = denom/div;
    }
    Rational operator-() const {
        return Rational(-num,denom);
    }
    Rational& operator++() {
        num += denom;
        int div = gcd(num,denom);
        num /= div;
        denom /= div;
        return *this;
    }
    Rational operator++(int) {
        Rational result(num,denom);
        ++*this;
        return result;
    }
    friend Rational operator+(const Rational& lhs, const Rational& rhs);
    friend Rational operator-(const Rational& lhs, const Rational& rhs);
    friend Rational operator*(const Rational& lhs, const Rational& rhs);
    friend Rational operator/(const Rational& lhs, const Rational& rhs);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator!=(const Rational& lhs, const Rational& rhs);
    friend ostream& operator<<(ostream& os, const Rational& rhs);
    friend istream& operator>>(istream& is, Rational& rhs);
/*    operator int() const {
        return num/denom;
    }*/
};

inline Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num*rhs.denom + lhs.denom*rhs.num, lhs.denom*rhs.denom);
}

inline Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num*rhs.denom - lhs.denom*rhs.num, lhs.denom*rhs.denom);
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num*rhs.num, lhs.denom*rhs.denom);
}

inline Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num*rhs.denom, lhs.denom*rhs.num);
}

inline bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.num == rhs.num && lhs.denom == rhs.denom;
}

inline bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs==rhs);
}

inline ostream& operator<<(ostream& os, const Rational& rhs) {
    return os << rhs.num << '/' << rhs.denom;
}

inline istream& operator>>(istream& is, Rational& rhs) {
    char slash;
    is >> rhs.num >> slash;
    if (slash != '/')
        is.setstate(ios::failbit);
    return is >> rhs.denom;
}

int Rational::gcd(int m, int n) {
    return n == 0 ? m : gcd(n,m%n);
}

int main() {
    Rational r1(2,3);
    Rational r2(3,4);
    Rational r3 = r1 + r2;
    cout << r3 << endl;
    Rational r4 = -r3;
    cout << r4 << endl;
    Rational r5 = r1 + 3;
    cout << r5 << endl;
    Rational r6 = 3 + r1;
    cout << r6 << endl;
    cin >> r6;
    cout << r6 << endl;
    cout << ++r6 << endl;
    cout << r6++ << endl;
    cout << r6 << endl;
/*    int i = r6;
    int i = r4;
    cout << i << endl;*/
}

