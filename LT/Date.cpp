#include <iostream>
#include <ctime>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(const Date &);
    Date(int);
    Date(int, int, int);
    int getDay();
    int getMonth();
    int getYear();
    void input();
    void increase1Day();
    void increaseNDays(int);
    void decrease1Day();
    void decreaseNDays(int);
    int compare(Date);
    void display();
    void getDayOfWeek();
};
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
Date::Date()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
};
Date::Date(const Date &d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
};
Date::Date(int n)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    increaseNDays(n);
};
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
void Date::getDayOfWeek()
{
    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2)
    {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 +
            j / 4 + 5 * j;
    h = h % 7;
    switch (h)
    {
    case 0:
        cout << "Saturday \n";
        break;
    case 1:
        cout << "Sunday \n";
        break;
    case 2:
        cout << "Monday \n";
        break;
    case 3:
        cout << "Tuesday \n";
        break;
    case 4:
        cout << "Wednesday \n";
        break;
    case 5:
        cout << "Thursday \n";
        break;
    case 6:
        cout << "Friday \n";
        break;
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
int main()
{
    Date d(25,9,2072);
    d.getDayOfWeek();
    // double n = 2.6;
    // cout << (int)n;
}