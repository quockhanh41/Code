#include "Time.h"
TimeFormatException::TimeFormatException(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}
void checkTimeFormat(int hour, int minute, int second)
{
    if (hour < 0 || hour > 24 || minute < 0 || minute > 60 || second < 0 || second > 60)
        throw TimeFormatException(hour, minute, second);
    cout << hour << ":" << minute << ":" << second << " valid!\n";
}
