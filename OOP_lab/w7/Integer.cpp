#include "Integer.h"
void changeToInteger(string integer)
{
    for (int i = 0; i < integer.size(); i++)
    {
        if (integer[i] < '0' || integer[i] > '9')
            throw IntegerFormatException(integer);
    }
    cout << "Change to integer successfully: " << integer << '\n';
}
IntegerFormatException::IntegerFormatException(string integer)
{
    this->integer = integer;
}
