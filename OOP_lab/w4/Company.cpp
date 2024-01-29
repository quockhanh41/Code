#include "Company.h"
Company::Company(){};
void Company::addStaff(Staff *staff)
{
    listStaff.push_back(staff);
};

void Company::display()
{
    for (auto x : listStaff)
        x->display();
}

double Company::calcTotalSalary()
{
    double totalSalary = 0;
    for (Staff *x : listStaff)
        totalSalary += x->getSalary();
    return totalSalary;
}
Staff *Company::findByFullName(string fullName)
{
    for (Staff *x : listStaff)
    {
        if ((*x).getFullName() == fullName)
            return x;
    }
    return nullptr;
}