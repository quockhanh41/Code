#include <iostream>
#include <vector>
using namespace std;
class Mobile
{
private:
    int code;
    string name;
    string brand;
    int date;

public:
    Mobile(int code, string name, string brand, int date)
    {
        this->code = code;
        this->name = name;
        this->brand = brand;
        this->date = date;
    };
    friend istream &operator>>(istream &is, Mobile other)
    {
        is >> other.code >> other.name >> other.brand >> other.date;
        return is;
    }
    friend ostream &operator<<(ostream &os, Mobile other)
    {
        os << other.code << other.name << other.brand << other.date;
        return os;
    }
    bool operator>(Mobile other)
    {
        return date > other.date;
    }
    bool operator==(Mobile other)
    {
        return date == other.date;
    }
};

int main()
{
    Mobile a(123, "a", "ip", 9);
    Mobile b(123, "a", "ip", 5);
    cout << (a > b);
    return 0;
}