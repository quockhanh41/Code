#include <iostream>
#include <exception>
#pragma once
using namespace std;
class DateFormatException : public exception
{
private:
    int day;
    int month;
    int year;

public:
    DateFormatException(){};
    DateFormatException(int, int, int);
    const char *what() const throw()
    {
        return "Exception: Date format";
    }
};
void checkDateFormat(int day, int month, int year);