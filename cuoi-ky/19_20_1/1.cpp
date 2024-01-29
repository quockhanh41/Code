#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isArmtrong(int n)
{
    int m = n;
    int sum = 0;
    int numDigit = 1;
    while (n / numDigit > 10)
    {
        numDigit *= 10;
    }
    numDigit = log10(numDigit) + 1;
    while (m > 0)
    {
        sum += pow(m % 10, numDigit);
        m /= 10;
    }
    return sum == n;
}
class Armstrong
{
private:
    int value;

public:
    Armstrong(int value) { this->value = value; }
    Armstrong()
    {
        value = 1;
    };
    int getValue() { return value; }
    friend istream &operator>>(istream &is, Armstrong &other)
    {
        is >> other.value;
        while (isArmtrong(other.value) == 0)
        {
            other.value++;
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, Armstrong &other)
    {
        os << other.value;
        return os;
    }
    Armstrong operator++()
    {
        while (isArmtrong(value) == 0)
        {
            value++;
        }
        return *this;
    }
    Armstrong operator++(int x)
    {
        Armstrong temp(value);
        value++;
        return temp;
    }
    bool operator==(const Armstrong &a) { return value == a.value; }
};

int main()
{
    Armstrong a;
    cin >> a;
    cout << a;
    Armstrong b = a;
    ++b;
    cout << b;
    a = b++;
    if (a == b)
        cout << 1;
    else
        cout << 0;
    return 0;
}