#include <iostream>
using namespace std;
class Rectangle
{
private:
    double width, length;

public:
    Rectangle() {}
    Rectangle(double length, double width)
    {
        this->length = length;
        this->width = width;
    };
    double calculatePerimeter() { return (width + length) * 2; }
    void display()
    {
        cout << "Perimeter: " << calculatePerimeter();
    }
};
int main() {}
