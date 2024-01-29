#include "Shape.cpp"
class Triangle : public Shape
{
public:
    Triangle() : Shape(3){};
    double getArea()
    {
        Point A = getPoint(0);
        Point B = getPoint(1);
        Point C = getPoint(2);
        double a = A.distance(B);
        double b = B.distance(C);
        double c = C.distance(A);
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
