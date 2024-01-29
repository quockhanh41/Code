#include "Staff.h"
#pragma once
class ProductionStaff : public Staff
{
private:
    int baseSalary;
    int amountProduct;

public:
    ProductionStaff();
    ProductionStaff(string, int, int, int);
    ProductionStaff(string, int, int);
    ProductionStaff(string, int);
    ProductionStaff(string);
    int getBaseSalary();
    void SetBaseSalary(int);
    int getAmountProduct();
    void setAmountProduct(int);
    double getSalary();
    void setSalary();
    void display();
    void setInfo();
};
