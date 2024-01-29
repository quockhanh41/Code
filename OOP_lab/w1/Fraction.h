#pragma once
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int, int);
    void setNumerator(int);
    int getNumerator();
    void setDenominator(int);
    int getDenominator();
    void input();
    void simplify();
    void calcSum(Fraction, Fraction);
    void calcDifference(Fraction, Fraction);
    void calcProduct(Fraction, Fraction);
    void calcQuotient(Fraction, Fraction);
    void display();
};
