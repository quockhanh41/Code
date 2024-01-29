#include "Staff.h"
#include "ManagementStaff.h"
#include "OfficeStaff.h"
#include "ProductionStaff.h"
#include "Company.h"
int main()
{
    // Bai 1
    Staff s1;
    Staff s2("Khanh", 2010);
    Staff s3(2010, "Khanh");
    Staff s4("Khanh");
    Staff s5(2010);

    // Bai 2
    OfficeStaff o1;
    OfficeStaff o2("Khanh", 2010, 100, 5, 100);
    OfficeStaff o3("Khanh", 2010, 100, 6);
    OfficeStaff o4("Khanh", 2010, 100);
    OfficeStaff o5("Khanh", 2010);

    // Bai 3
    ProductionStaff p1;
    ProductionStaff p2("Khanh", 2010, 100, 100);
    ProductionStaff p3("Khanh", 2010, 100);
    ProductionStaff p4("Khanh", 2010);
    ProductionStaff p5("Khanh");

    // Bai 4
    ManagementStaff m1;
    ManagementStaff m2("Khanh", 2010, 100, 2.3, 300);
    ManagementStaff m3("Khanh", 2010, 100, 2.3);
    ManagementStaff m4("Khanh", 2010, 100);
    ManagementStaff m5("Khanh", 2010);

    // Bai 5
    // done

    // Bai 6
    // done

    // Bai 7
    // done

    // Bai 8
    // done

    // Bai 9, 10, 11, 12, 13
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
        cout << "Option 6: Calculate sum salary" << endl;
        cout << "Option 7: Exit" << endl;
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
            while (n--)
            {
                newStaff = new ProductionStaff;
                newStaff->setInfo();
                company.addStaff(newStaff);
            }
            break;
        }
        case 2:
        {
            cout << "Number of staff: ";
            int n;
            cin >> n;
            while (n--)
            {
                newStaff = new ManagementStaff;
                newStaff->setInfo();
                company.addStaff(newStaff);
            }
            break;
        }
        case 3:
        {
            cout << "Number of staff: ";
            int n;
            cin >> n;
            while (n--)
            {
                newStaff = new OfficeStaff;
                newStaff->setInfo();
                company.addStaff(newStaff);
            }
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
