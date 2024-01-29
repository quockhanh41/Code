#include "Staff.h"
#include "ManagementStaff.h"
#include "OfficeStaff.h"
#include "ProductionStaff.h"
#include "Company.h"
int main()
{
    // Bai 1,2,3,4,5,6,7,8,9,10,11,12,13 done
    Company company;
    Staff *newStaff;
    bool check = true;
    while (check)
    {
        cout << "\nOption 1: Add production staff" << endl;
        cout << "Option 2: Add management staff" << endl;
        cout << "Option 3: Add office staff" << endl;
        cout << "Option 4: Print staff's information" << endl;
        cout << "Option 5: Search for staff by name" << endl;
        cout << "Option 6: Calculate sum of salary" << endl;
        cout << "Option 7: Print the highest salary staff's information" << endl;
        cout << "Option 8: Print number of staff has birthmonth before May" << endl;
        cout << "Option 9: Exit" << endl;
        cout << "Enter your choice: " << endl;
        int choice;
        cin >> choice;
        cin.ignore();
        Staff *newStaff;
        switch (choice)
        {
        case 1:
        {
            cout << "Number of staff: ";
            int n;
            cin >> n;
            vector<Staff *> v;
            while (n--)
            {
                newStaff = new ProductionStaff;
                newStaff->setInfo();
                v.push_back(newStaff);
            }
            company.addStaff(v);
            break;
        }
        case 2:
        {
            cout << "Number of staff: ";
            int n;
            cin >> n;
            vector<Staff *> v;
            while (n--)
            {
                newStaff = new ManagementStaff;
                newStaff->setInfo();
                v.push_back(newStaff);
            }
            company.addStaff(v);
            break;
        }
        case 3:
        {
            cout << "Number of staff: ";
            int n;
            cin >> n;
            vector<Staff *> v;
            while (n--)
            {
                newStaff = new OfficeStaff;
                newStaff->setInfo();
                v.push_back(newStaff);
            }
            company.addStaff(v);
            break;
        }
        case 4:
        {
            company.display();
            break;
        }
        case 5:
        {
            string name;
            cout << "Enter staff's name that need to find: ";
            getline(cin, name);
            Staff *lookingFor = company.findByFullName(name);
            if (lookingFor)
                lookingFor->display();
            else
                cout << "Could not find name: " << name;
            break;
        }
        case 6:
        {
            cout << "Sum salary: " << company.calcTotalSalary() << endl;
            break;
        }
        case 7:
        {
            company.findHighestSalaryStaff()->display();
            break;
        }
        case 8:
        {
            cout << "Number of staff has birthmonth before May: " << company.numberMay_monthStaff();
            break;
        }
        case 9:
        {
            check = false;
            break;
        }
        default:
        {
            cout << "Enter your choice: " << endl;
            int choice;
            cin >> choice;
        }
        }
    }
    return 0;
}
