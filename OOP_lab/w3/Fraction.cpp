#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
};
Fraction::Fraction(int numerator, int denominator)
{
    this->denominator = denominator;
    this->numerator = numerator;
}
Fraction::Fraction(const Fraction &x)
{
    *this = x;
}
void Fraction::setNumerator(int numerator) { this->numerator = numerator; }
int Fraction::getNumerator() { return numerator; }
void Fraction::setDenominator(int denominator) { this->denominator = denominator; }
int Fraction::getDenominator() { return denominator; }
void Fraction::input()
{
    cin >> numerator >> denominator;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void simplifyFraction(int &numerator, int &denominator)
{
    int commonDivisor = gcd(numerator, denominator);

    numerator /= commonDivisor;
    denominator /= commonDivisor;
}

void Fraction::display()
{
    cout << numerator << "/" << denominator << " = " << (double)numerator / denominator << '\n';
}
Fraction &Fraction::operator=(const Fraction &x)
{
    if (this == &x)
        return *this;
    if (x.numerator == 0 && x.denominator == -1)
        return *this;
    this->numerator = x.numerator;
    this->denominator = x.denominator;
    return *this;
}
Fraction Fraction::operator*(const Fraction &x)
{
    int num = numerator * x.numerator;
    int den = denominator * x.denominator;
    simplifyFraction(num, den);
    return Fraction(num, den);
}

Fraction Fraction::operator+(const Fraction &x)
{
    int num = numerator * x.denominator + x.numerator * denominator;
    int den = denominator * x.denominator;
    simplifyFraction(num, den);
    return Fraction(num, den);
}
Fraction operator*(int x, const Fraction &f)
{
    int num = x * f.numerator;
    int den = f.denominator;
    simplifyFraction(num, den);
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction &x)
{
    int num = numerator * x.denominator - x.numerator * denominator;
    int den = denominator * x.denominator;
    simplifyFraction(num, den);
    return Fraction(num, den);
}
Fraction Fraction::operator-(int x)
{
    return *this - Fraction(x, 1);
}

Fraction Fraction::operator/(const Fraction &x)
{
    if (x.numerator == 0)
    {
        cout << "Cannot divide by zero!\n";
        return Fraction(0, -1);
    }
    int num = numerator * x.denominator;
    int den = denominator * x.numerator;
    simplifyFraction(num, den);
    return Fraction(num, den);
}
bool Fraction::operator>(const Fraction &x) 
{
    return numerator * x.denominator > denominator * x.numerator;
}
bool Fraction::operator<(const Fraction &x)
{
    return numerator * x.denominator < denominator * x.numerator;
}
bool Fraction::operator==(const Fraction &x)
{
    return numerator * x.denominator == denominator * x.numerator;
}
bool Fraction::operator!=(const Fraction &x)
{
    return !(numerator * x.denominator == denominator * x.numerator);
}
bool Fraction::operator>=(const Fraction &x)
{
    if (numerator * x.denominator < denominator * x.numerator)
        return 0;
    return 1;
}
bool Fraction::operator<=(const Fraction &x)
{
    if (numerator * x.denominator > denominator * x.numerator)
        return 0;
    return 1;
}
Fraction &Fraction::operator*=(const Fraction &x)
{
    *this = *this * x;
    return *this;
}
Fraction &Fraction::operator+=(const Fraction &x)
{
    *this = *this + x;
    return *this;
}
Fraction &Fraction::operator-=(const Fraction &x)
{
    *this = *this - x;
    return *this;
}
Fraction &Fraction::operator/=(const Fraction &x)
{
    *this = *this / x;
    return *this;
}

Fraction Fraction::operator++()
{
    *this = *this + Fraction(1, 1);
    return Fraction(numerator, denominator);
}
Fraction Fraction::operator++(int x)
{
    Fraction f(*this);
    *this = *this + Fraction(1, 1);
    return f;
}

Fraction Fraction::operator--()
{
    *this = *this + Fraction(-1, 1);
    return Fraction(numerator, denominator);
}
Fraction Fraction::operator--(int x)
{
    Fraction f(*this);
    *this = *this + Fraction(-1, 1);
    return f;
}

Fraction Fraction::operator+(int x)
{
    return *this + Fraction(x, 1);
}

Fraction operator+(int x, const Fraction &f)
{
    return Fraction(x * f.denominator + f.numerator, f.denominator);
}

Fraction ::operator int()
{
    return numerator / denominator;
}
Fraction ::operator float()
{
    return (float)numerator / denominator;
}
ostream &operator<<(ostream &os, const Fraction f)
{
    if (f.numerator % f.denominator == 0)
        os << f.numerator / f.denominator;
    else
    {
        os << f.numerator << '/' << f.denominator;
    }
    return os;
}
istream &operator>>(istream &is, Fraction &f)
{
    char x;
    is >> f.numerator >> x >> f.denominator;
    return is;
}
