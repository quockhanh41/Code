#include "Staff.h"
#pragma once
class ManagementStaff : public Staff
{
private:
    int baseSalary;
    double coefficientsSalary;
    int bonus;

public:
    ManagementStaff();
    ManagementStaff(string, string, int,int, int, double, int);
    int getBaseSalary();
    void SetBaseSalary(int);
    double getCoefficientsSalary();
    void SetCoefficientsSalary(double);
    int getBonus();
    void SetBonus(int);
    double getSalary();
    void setSalary();
    void display();
    void setInfo();
};
