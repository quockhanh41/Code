#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int, int);
    Fraction(const Fraction &x);
    void setNumerator(int);
    int getNumerator();
    void setDenominator(int);
    int getDenominator();
    void input();
    void display();
    Fraction &operator=(const Fraction &x);
    Fraction operator+(const Fraction &x);
    Fraction operator+(int x);
    friend Fraction operator+(int x, const Fraction &f);
    Fraction operator-(const Fraction &x);
    Fraction operator-(int x);
    Fraction operator*(const Fraction &x);
    friend Fraction operator*(int x, const Fraction &f);
    Fraction operator/(const Fraction &x);
    bool operator>(const Fraction &x);
    bool operator<(const Fraction &x);
    bool operator==(const Fraction &x);
    bool operator!=(const Fraction &x);
    bool operator>=(const Fraction &x);
    bool operator<=(const Fraction &x);
    Fraction operator++();
    Fraction operator++(int x);
    Fraction operator--();
    Fraction operator--(int x);
    Fraction &operator*=(const Fraction &x);
    Fraction &operator/=(const Fraction &x);
    Fraction &operator+=(const Fraction &x);
    Fraction &operator-=(const Fraction &x);
    friend ostream &operator<<(ostream &os, const Fraction f);
    friend istream &operator>>(istream &is, Fraction &f);
    operator int();
    operator float();
};
void simplifyFraction(int &numerator, int &denominator);
int gcd(int a, int b);
