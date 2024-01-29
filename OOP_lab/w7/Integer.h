#include <iostream>
using namespace std;
class IntegerFormatException : public exception
{
private:
    string integer;

public:
    IntegerFormatException(){};
    IntegerFormatException(string);
    const char *what() const throw()
    {
        return "Exception: Can not change the integer";
    }
};
void changeToInteger(string integer);