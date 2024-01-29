#include <iostream>
#include <exception>
using namespace std;
class IndexOutOfRangeException : public exception
{
public:
    const char *what() const throw()
    {
        return "Exception: Index out of range!";
    }
};

class Array
{
private:
    int *arr;
    int size;

public:
    Array(int sz) : size(sz)
    {
        arr = new int[size];
    }
    int &getValueAt(int index) const;

    ~Array();
};