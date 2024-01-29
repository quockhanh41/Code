#include "ManagementStaff.h"
ManagementStaff::ManagementStaff()
{
    baseSalary = 0;
    coefficientsSalary = 1;
    bonus = 0;
}

ManagementStaff::ManagementStaff(string fullName, int startedYear, int baseSalary, double coefficientsSalary, int bonus) : Staff(fullName, startedYear)
{
    this->baseSalary = baseSalary;
    this->coefficientsSalary = coefficientsSalary;
    this->bonus = bonus;
};

ManagementStaff::ManagementStaff(string fullName, int startedYear, int baseSalary, double coefficientsSalary) : Staff(fullName, startedYear)
{
    this->baseSalary = baseSalary;
    this->coefficientsSalary = coefficientsSalary;
    bonus = 0;
};

ManagementStaff::ManagementStaff(string fullName, int startedYear, int baseSalary) : Staff(fullName, startedYear)
{
    this->baseSalary = baseSalary;
    coefficientsSalary = 1;
    bonus = 0;
};

ManagementStaff::ManagementStaff(string fullName, int startedYear) : Staff(fullName, startedYear)
{
    baseSalary = 0;
    coefficientsSalary = 1;
    bonus = 0;
};
int ManagementStaff::getBaseSalary() { return baseSalary; }
void ManagementStaff::SetBaseSalary(int baseSalary) { this->baseSalary = baseSalary; };

double ManagementStaff::getCoefficientsSalary() { return coefficientsSalary; }
void ManagementStaff::SetCoefficientsSalary(double coefficientsSalary) { this->coefficientsSalary = coefficientsSalary; };

int ManagementStaff::getBonus() { return bonus; }
void ManagementStaff::SetBonus(int bonus) { this->bonus = bonus; };
void ManagementStaff::setSalary()
{
    cout << "Base salary: ";
    cin >> baseSalary;
    cout << "Coefficients salary: ";
    cin >> coefficientsSalary;
    cout << "Bonus: ";
    cin >> bonus;
};

double ManagementStaff::getSalary()
{
    return baseSalary * coefficientsSalary + bonus;
};
void ManagementStaff::display()
{
    cout << "Full name: " << Staff::getFullName() << " - Management staff\n";
    cout << "Started year: " << Staff::getStartedYear() << '\n';
    cout << "Base salary: " << getBaseSalary() << '\n';
    cout << "Coefficient salary: " << getCoefficientsSalary() << '\n';
    cout << "Bonus: " << getBonus() << '\n';
}
void ManagementStaff::setInfo()
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
    cout << "Coefficient salary: ";
    cin >> coefficientsSalary;
    cout << "Bonus: ";
    cin >> bonus;
}