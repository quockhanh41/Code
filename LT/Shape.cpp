#include "Point.cpp"
#include <vector>
class Shape
{
private:
    int numberOfPoint;
    Point *point;

public:
    // Shape()
    // {
    //     this->numberOfPoint = 5;
    //     point = new Point[5];
    // }
    Shape(int numberOfPoint)
    {
        this->numberOfPoint = numberOfPoint;
        point = new Point[numberOfPoint];
    };
    void setPoint()
    {
        for (int i = 0; i < numberOfPoint; i++)
        {
            double a, b;
            cin >> a >> b;
            point[i] = Point(a, b);
        }
    }
    ~Shape()
    {
        delete[] point;
    };
    Point getPoint(int index)
    {
        return point[index];
    }
    // virtual double getArea() = 0;
};
