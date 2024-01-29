#include <iostream>
using namespace std;
class TimeFormatException : public exception
{
private:
    int hour;
    int minute;
    int second;

public:
    TimeFormatException(){};
    TimeFormatException(int, int, int);
    const char *what() const throw()
    {
        return "Exception: Time format";
    }
};
void checkTimeFormat(int hour, int minute, int second);
