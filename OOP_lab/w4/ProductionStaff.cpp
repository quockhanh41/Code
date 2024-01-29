#include "ProductionStaff.h"
ProductionStaff::ProductionStaff()
{
    baseSalary = 0;
    amountProduct = 0;
}

ProductionStaff::ProductionStaff(string fullName, int startedYear, int baseSalary, int amountProduct) : Staff(fullName, startedYear)
{
    this->baseSalary = baseSalary;
    this->amountProduct = amountProduct;
}

ProductionStaff::ProductionStaff(string fullName, int startedYear, int baseSalary) : Staff(fullName, startedYear)
{
    this->baseSalary = baseSalary;
    amountProduct = 0;
}

ProductionStaff::ProductionStaff(string fullName, int startedYear) : Staff(fullName, startedYear)
{
    baseSalary = 0;
    amountProduct = 0;
}

ProductionStaff::ProductionStaff(string fullName) : Staff(fullName)
{
    baseSalary = 0;
    amountProduct = 0;
}

void ProductionStaff::setSalary()
{
    cout << "Base salary: ";
    cin >> baseSalary;
    cout << "Amount of product: ";
    cin >> amountProduct;
};
int ProductionStaff::getBaseSalary() { return baseSalary; };
void ProductionStaff::SetBaseSalary(int baseSalary) { this->baseSalary = baseSalary; };
int ProductionStaff::getAmountProduct() { return amountProduct; };
void ProductionStaff::setAmountProduct(int amountProduct) { this->amountProduct = amountProduct; };

double ProductionStaff::getSalary()
{
    return baseSalary + amountProduct * 2000;
};
void ProductionStaff::display()
{
    cout << "Full name: " << Staff::getFullName() << " - Production staff\n";
    cout << "Started year: " << Staff::getStartedYear() << '\n';
    cout << "Base salary: " << getBaseSalary() << '\n';
    cout << "Amount of product: " << getAmountProduct() << '\n';
}
void ProductionStaff::setInfo()
{
        string full_Name;
        int started_year;
        cout << "\nFull name: ";
        cin.ignore();
        getline(cin, full_Name);
        Staff::setFullName(full_Name);
        cout << "Started year: ";
        cin >> started_year;
        Staff::setStartedYear(started_year);
        cout << "Base salary: ";
        cin >> baseSalary;
        cout << "Amount product: ";
        cin >> amountProduct;
};
