#include <iostream>
#include <vector>
using namespace std;
class Fibonacci
{
private:
    int size;
    int *elements;

public:
    Fibonacci() : size(0), elements(nullptr) {}
    void genarate(int size)
    {
        if (elements != nullptr)
        {
            delete[] elements;
        }
        this->size = size;
        elements = new int[size + 1];
        elements[0] = 0;
        elements[1] = 1;
        for (int i = 2; i <= size; i++)
        {
            elements[i] = elements[i - 1] + elements[i - 2];
        }
    };
    ~Fibonacci()
    {
        delete[] elements;
    }
    friend ostream &operator<<(ostream &os, const Fibonacci other)
    {
        for (int i = 0; i < other.size; i++)
        {
            os << "F[" << i << "] = " << other.elements[i] << endl;
        }
        return os;
    }
};
int main()
{
    Fibonacci a;
    a.genarate(5);
    cout << a;
    return 0;
}