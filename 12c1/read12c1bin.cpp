#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int stt;
    char name[100];
    char position[100];
    char address[100];
    char phone[100];
    char email[100];
};
int main()
{
    Student a;
    fstream f("12c1.bin", ios::in | ios::binary);
    while (!f.eof())
    {
        f.read((char *)&a, sizeof(a));
        cout << a.stt << endl;
        cout << a.name << endl;
        cout << a.position << endl;
        cout << a.address << endl;
        cout << a.phone << endl;
        cout << a.email << endl;
    }
}