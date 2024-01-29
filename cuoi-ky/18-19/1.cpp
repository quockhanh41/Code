#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
class Fibonacci
{
private:
    int size;
    int *elements;

public:
    Fibonacci(int n)
    {
        size = n;
        elements = new int[n + 1];
        elements[0] = 0;
        elements[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            elements[i] = elements[i - 1] + elements[i - 2];
        }
    };
    ~Fibonacci()
    {
        delete[] elements;
    };
    friend ostream &operator<<(ostream &os, Fibonacci f)
    {
        for (int i = 0; i <= f.size; i++)
        {
            os << "F[" << i << "] = " << f.elements[i] << '\n';
        }
        return os;
    }
};

int main()
{
    Fibonacci f(5);
    cout << f;
    return 0;
}