#include <iostream>
#include <exception>
#include <string>

using namespace std;

class DividedByZeroException : public exception
{
public:
    const char *what() const throw()
    {
        return "Exception: Cannot divide by zero!";
    }
};

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    void SetValue(int num, int den);

    int GetNumerator() const;

    int GetDenominator() const;
};