#include <iostream>
#include <vector>
using namespace std;
class Polygon
{
private:
    char *name;

public:
    Polygon(){};
    ~Polygon()
    {
        cout << "destructor\n";
        delete[] name;
    };
};

int main()
{
    Polygon n;
    Polygon *p = new Polygon;
    delete p;
    return 0;
}