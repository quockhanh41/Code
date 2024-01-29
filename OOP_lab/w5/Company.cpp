#include "Company.h"
Company::Company(){};
void Company::addStaff(vector<Staff *> list)
{
    for (auto x : list)
        listStaff.push_back(x);
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
        if (x->getFullName() == fullName)
            return x;
    return nullptr;
}

Staff *Company::findByID(string ID)
{
    for (Staff *x : listStaff)
        if (x->getID() == ID)
            return x;
    return nullptr;
}

Staff *Company::findHighestSalaryStaff()
{
    Staff *res = listStaff[0];
    for (auto x : listStaff)
        if (x->getSalary() > res->getSalary())
            res = x;
    return res;
};
int Company::countProductionStaff()
{
    int count = 0;
    for (auto x : listStaff)
        if (ProductionStaff *p = dynamic_cast<ProductionStaff *>(x))
            count++;
    return count;
};

int Company::countOfficeStaff()
{
    int count = 0;
    for (auto x : listStaff)
        if (OfficeStaff *p = dynamic_cast<OfficeStaff *>(x))
            count++;
    return count;
};
double Company::calcAverageSalary()
{
    return calcTotalSalary() / listStaff.size();
};
void Company::displayStaffUnder3M()
{
    for (auto x : listStaff)
        if (x->getSalary() < 3000000)
            x->display();
};
int Company::numberMay_monthStaff()
{
    int cnt = 0;
    for (auto x : listStaff)
        if (x->Staff::getMonth() < 5)
            cnt++;
    return cnt;
};
