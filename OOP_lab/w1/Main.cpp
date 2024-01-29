#include "Date.cpp"
#include "Point.cpp"
#include "Rectangle.cpp"
#include "Student.cpp"
int main()
{
    // Bài 2
    cout << "Bai 2 ----------------------------\n";
    Date date1;
    Date date2;
    cout << "Enter day A: ";
    date1.input();
    cout << "The previous day: ";
    date1.decrease1Day();
    date1.display();
    cout << "The next day: ";
    date1.increase1Day();
    date1.increase1Day();
    date1.display();
    date1.decrease1Day();
    cout << "Enter day B: ";
    date2.input();
    cout << date1.compare(date2) << '\n';
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << "Day A after " << n << " day(s): ";
    date1.increaseNDays(n);
    date1.display();

    // Bài 3
    cout << "Bai 3 ----------------------------\n";
    Point point1;
    Point point2;
    cout << "Enter point A: ";
    point1.input();
    cout << "Enter point B: ";
    point2.input();
    cout << "A";
    point1.display();
    cout << "B";
    point2.display();
    cout << "Distance between A and B: " << point1.distance(point2) << '\n';

    // Bài 4
    cout << "Bai 4 ----------------------------\n";
    Rectangle rectangle;
    cout << "Enter 4 points of rectangle: ";
    rectangle.input();
    rectangle.display();
    if (rectangle.isRectangle())
    {
        cout << "Area: " << rectangle.getArea() << '\n';
        cout << "Perimeter: " << rectangle.getPerimeter() << '\n';
    }
    else
        cout << "Is not a rectangle\n";

    // Bài 5
    cout << "Bai 5 ----------------------------\n";
    Student s;
    s.input();
    s.display();
}
