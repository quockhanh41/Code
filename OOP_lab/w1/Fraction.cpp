#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(){};
Fraction::Fraction(int numerator, int denominator)
{
    this->denominator = denominator;
    this->numerator = numerator;
}
void Fraction::setNumerator(int numerator) { this->numerator = numerator; }
int Fraction::getNumerator() { return numerator; }
void Fraction::setDenominator(int denominator) { this->denominator = denominator; }
int Fraction::getDenominator() { return denominator; }
void Fraction::input()
{
    cin >> numerator >> denominator;
}
void Fraction::simplify()
{
    int x;
    if (numerator < denominator)
        x = abs(numerator);
    else
        x = abs(denominator);
    while (numerator % x != 0 || denominator % x != 0)
        x--;
    numerator /= x;
    denominator /= x;
}
void Fraction::Fraction::calcSum(Fraction x, Fraction y)
{
    numerator = (x.getNumerator() * y.getDenominator()) + (y.getNumerator() * x.getDenominator());
    denominator = x.getDenominator() * y.getDenominator();
    simplify();
}
void Fraction::calcDifference(Fraction x, Fraction y)
{
    y.setNumerator(-y.getNumerator());
    calcSum(x, y);
    simplify();
}
void Fraction::calcProduct(Fraction x, Fraction y)
{
    numerator = x.getNumerator() * y.getNumerator();
    denominator = x.getDenominator() * y.getDenominator();
    simplify();
}
void Fraction::calcQuotient(Fraction x, Fraction y)
{
    numerator = x.getNumerator() * y.getDenominator();
    denominator = x.getDenominator() * y.getNumerator();
    simplify();
}

void Fraction::display()
{
    cout << numerator << "/" << denominator << " = " << (double)numerator / denominator << '\n';
}

