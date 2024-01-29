#include <iostream>
using namespace std;
class Point
{
private:
    double x, y;

public:
    Point() {}
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    };
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
{
}

Point::~Point()
{
}
