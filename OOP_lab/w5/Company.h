#include "ManagementStaff.h"
#include "OfficeStaff.h"
#include "ProductionStaff.h"
#include <vector>
#pragma once
class Company
{
private:
    vector<Staff *> listStaff;

public:
    Company();
    void display();
    double calcTotalSalary();
    Staff *findByFullName(string);
    Staff *findByID(string);
    void addStaff(vector<Staff *>);
    Staff *findHighestSalaryStaff();
    int countProductionStaff();
    int countOfficeStaff();
    double calcAverageSalary();
    void displayStaffUnder3M();
    int numberMay_monthStaff();
};
