#include "Staff.h"
Staff::Staff()
{
    fullName = "\0";
    startedYear = -1;
}
Staff::Staff(string fullName)
{
    this->fullName = fullName;
    startedYear = 0;
}
Staff::Staff(int startedYear)
{
    fullName = "\0";
    this->startedYear = startedYear;
}
Staff::Staff(string fullName, int startedYear)
{
    this->fullName = fullName;
    this->startedYear = startedYear;
}
Staff::Staff(int startedYear, string fullName)
{
    this->fullName = fullName;
    this->startedYear = startedYear;
}
double Staff::getSalary() { return 0; };
void Staff::setSalary(){};
void Staff::display(){};
void Staff::setInfo(){};
