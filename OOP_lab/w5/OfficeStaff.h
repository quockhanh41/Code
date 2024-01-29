#include "Staff.h"
#pragma once
class OfficeStaff : public Staff
{
private:
    int baseSalary;
    int workday;
    int subsidy;

public:
    OfficeStaff();
    OfficeStaff(string, string, int,int, int, int, int);
    int getBaseSalary();
    void SetBaseSalary(int);
    int getWorkday();
    void setWorkday(int);
    int getSubsidy();
    void setSubsidy(int);
    double getSalary();
    void setSalary();
    void display();
    void setInfo();
};
