#pragma once
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
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
};
