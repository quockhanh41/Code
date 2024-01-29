#include "Staff.h"
Staff::Staff()
{
    fullName = "\0";
    startedYear = -1;
}

Staff::Staff(string fullName, string ID, int startedYear, int month)
{
    this->fullName = fullName;
    this->ID = ID;
    this->startedYear = startedYear;
    this->month = month;
}