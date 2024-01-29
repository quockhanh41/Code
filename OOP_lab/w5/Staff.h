#include <iostream>
#include <string>
#pragma once
using namespace std;
class Staff
{
private:
    string fullName;
    int startedYear;
    string ID;
    int month;

public:
    Staff();
    Staff(string, string, int, int);
    string getFullName() { return fullName; }
    string getID() { return ID; }
    int getMonth() { return month; }
    void setFullName(string fullName) { this->fullName = fullName; };
    void setMonth(int month) { this->month = month; };
    int getStartedYear() { return startedYear; }
    void setStartedYear(int startedYear) { this->startedYear = startedYear; };
    double virtual getSalary() = 0;
    void virtual setSalary() = 0;
    void virtual display() = 0;
    void virtual setInfo() = 0;
};