#include "Fraction.h"

void Fraction::SetValue(int num, int den)
{
    if (den == 0)
    {
        throw DividedByZeroException();
    }
    numerator = num;
    denominator = den;
}

int Fraction::GetNumerator() const
{
    return numerator;
}

int Fraction::GetDenominator() const
{
    return denominator;
}
