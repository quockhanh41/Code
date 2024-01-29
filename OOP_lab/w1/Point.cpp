#include <iostream>
#include "Point.h"
#include <cmath>
using namespace std;

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