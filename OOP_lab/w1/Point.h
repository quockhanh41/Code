#pragma once
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
