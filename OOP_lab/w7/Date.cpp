#include "Date.h"
DateFormatException::DateFormatException(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
void checkDateFormat(int day, int month, int year)
{
    if (day < 0 || day > 31 || month < 0 || month > 12 || year < 0 || year > 9999)
        throw DateFormatException(day, month, year);
    cout << day << "/" << month << "/" << year << " valid!\n";
}

