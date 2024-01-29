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
    void addStaff(Staff *);
};
