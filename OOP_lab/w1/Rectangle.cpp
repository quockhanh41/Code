#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(){};

Rectangle::Rectangle(Point a, Point b, Point c, Point d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
};

void Rectangle::input()
{
    a.input();
    b.input();
    c.input();
    d.input();
};

void Rectangle::display()
{
    a.display();
    b.display();
    c.display();
    d.display();
};

bool Rectangle::isRectangle()
{
    if ((a.getX() + c.getX() != b.getX() + d.getX()) || (a.getY() + c.getY() != b.getY() + d.getY()))
        return 0;
    double x = pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2);
    double y = pow(a.getX() - d.getX(), 2) + pow(a.getY() - d.getY(), 2);
    double z = pow(b.getX() - d.getX(), 2) + pow(b.getY() - d.getY(), 2);
    if (x + y != z)
        return 0;
    return 1;
};

double Rectangle::getArea()
{
    return a.distance(b) * b.distance(c);
};

double Rectangle::getPerimeter()
{
    return (a.distance(b) + b.distance(c)) * 2;
};
