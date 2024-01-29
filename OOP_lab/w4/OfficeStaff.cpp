#include "OfficeStaff.h"
OfficeStaff::OfficeStaff()
{
    baseSalary = 0;
    workday = 0;
    subsidy = 0;
};

OfficeStaff::OfficeStaff(string fullNamme, int startedYear, int baseSalary, int workday, int subsidy) : Staff(fullNamme, startedYear)
{
    this->baseSalary = baseSalary;
    this->workday = workday;
    this->subsidy = subsidy;
};

OfficeStaff::OfficeStaff(string fullNamme, int startedYear, int baseSalary, int workday) : Staff(fullNamme, startedYear)
{
    this->baseSalary = baseSalary;
    this->workday = workday;
    subsidy = 0;
};

OfficeStaff::OfficeStaff(string fullNamme, int startedYear, int baseSalary) : Staff(fullNamme, startedYear)
{
    this->baseSalary = baseSalary;
    workday = 0;
    subsidy = 0;
};

OfficeStaff::OfficeStaff(string fullNamme, int startedYear) : Staff(fullNamme, startedYear)
{
    baseSalary = 0;
    workday = 0;
    subsidy = 0;
};
int OfficeStaff::getBaseSalary() { return baseSalary; };
void OfficeStaff::SetBaseSalary(int baseSalary) { this->baseSalary = baseSalary; };
int OfficeStaff::getWorkday() { return workday; };
void OfficeStaff::setWorkday(int workday) { this->workday = workday; };
int OfficeStaff::getSubsidy() { return subsidy; };
void OfficeStaff::setSubsidy(int subsidy) { this->subsidy = subsidy; };

void OfficeStaff::setSalary()
{
    cout << "Base salary: ";
    cin >> baseSalary;
    cout << "Day of work: ";
    cin >> workday;
    cout << "Subsidy: ";
    cin >> subsidy;
};

double OfficeStaff::getSalary()
{
    return baseSalary + workday * 100000 + subsidy;
};
void OfficeStaff::display()
{
    cout << "Full name: " << Staff::getFullName() << " - Office staff\n";
    cout << "Started year: " << Staff::getStartedYear() << '\n';
    cout << "Base salary: " << getBaseSalary() << '\n';
    cout << "Day of work: " << getWorkday() << '\n';
    cout << "Subsidy: " << getSubsidy() << '\n';
}
void OfficeStaff::setInfo()
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
        cout << "Number of workday: ";
        cin >> workday;
        cout << "Subsidy: ";
        cin >> subsidy;

}