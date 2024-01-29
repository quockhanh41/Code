#include <iostream>
#include <string>
#pragma once
using namespace std;
class Staff
{
private:
    string fullName;
    int startedYear;

public:
    Staff();
    Staff(string, int);
    Staff(string);
    Staff(int);
    Staff(int, string);
    string getFullName() { return fullName; }
    void setFullName(string fullName) { this->fullName = fullName; };
    int getStartedYear() { return startedYear; }
    void setStartedYear(int startedYear) { this->startedYear = startedYear; };
    double virtual getSalary();
    void virtual setSalary();
    void virtual display();
    void virtual setInfo();
};