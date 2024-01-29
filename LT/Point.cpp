#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double, double);
    void setX(double);
    void setY(double);
    double getX();
    double getY();
    void input();
    void display();
    double distance(Point);
};

Point::Point(){};
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
};

void Point::input()
{
    cin >> x >> y;
};

void Point::setX(double x) { this->x = x; };
void Point::setY(double y) { this->y = y; };
double Point::getX() { return x; };
double Point::getY() { return y; };

void Point::display()
{
    cout << "(" << x << "," << y << ")\n";
};

double Point::distance(Point point)
{
    return sqrt(pow(x - point.getX(), 2) + pow(y - point.getY(), 2));
};