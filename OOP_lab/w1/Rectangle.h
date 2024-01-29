#include "Point.h"
#pragma once
class Rectangle
{
private:
    Point a;
    Point b;
    Point c;
    Point d;

public:
    Rectangle();
    Rectangle(Point, Point, Point, Point);
    void input();
    void display();
    bool isRectangle();
    double getArea();
    double getPerimeter();
};
