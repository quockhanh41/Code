#include <iostream>
#include "Date.h"
using namespace std;
bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 4 == 0)
        return 1;
    return 0;
}
bool is31days(int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 1;
    else
        return 0;
}
Date::Date(){};
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
};
int Date::getDay() { return day; };
int Date::getMonth() { return month; };
int Date::getYear() { return year; };
void Date::input()
{
    cin >> day >> month >> year;
};
void Date::increase1Day()
{
    day++;
    if (day == 32 && month == 12)
    {
        day = 1;
        month = 1;
        year++;
        return;
    }
    if (month == 2 && ((day == 29 && isLeapYear(year) == 0) || day == 30))
    {
        day = 1;
        month = 3;
        return;
    }
    if ((day == 31 && is31days(month) == 0) || (day == 32 && is31days(month) == 1))
    {
        day = 1;
        month++;
    }
}

void Date::increaseNDays(int n)
{
    for (int i = 0; i < n; i++)
        increase1Day();
};

void Date::decrease1Day()
{
    day--;
    if (day == 0 && month == 1)
    {
        day = 31;
        month = 12;
        year--;
        return;
    }
    if (month == 3 && day == 0)
    {
        if (isLeapYear(year) == 1)
            day = 29;
        else
            day = 28;
        month = 2;
        return;
    }
    if (day == 0)
    {
        if (is31days(month - 1) == 1)
            day = 31;
        else
            day = 30;
        month--;
    }
};

void Date::decreaseNDays(int n)
{
    for (int i = 0; i < n; i++)
        decrease1Day();
};

int Date::compare(Date x)
{
    if (year > x.getYear())
        return 1;
    else if (year < x.getYear())
        return -1;
    else
    {
        if (month > x.getMonth())
            return 1;
        else if (month < x.getMonth())
            return -1;
        else
        {
            if (day > x.getDay())
                return 1;
            else if (day < x.getDay())
                return -1;
            else
                return 0;
        }
    }
};
void Date::display()
{
    if (day < 10)
        cout << "0";
    cout << day << '/';
    if (month < 10)
        cout << "0";
    cout << month << '/';
    cout << year << '\n';
}
