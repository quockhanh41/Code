#include "Student.h"
Student::Student(char *studentId, double gpa, char *fullname, char *address)
{
    this->studentId = new char[strlen(studentId) + 1];
    strcpy(this->studentId, studentId);

    this->fullname = new char[strlen(fullname) + 1];
    strcpy(this->fullname, fullname);

    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);

    this->gpa = gpa;
}

Student ::Student(const Student &student)
{
    this->studentId = new char[strlen(student.studentId) + 1];
    strcpy(this->studentId, student.studentId);

    this->fullname = new char[strlen(student.fullname) + 1];
    strcpy(this->fullname, student.fullname);

    this->address = new char[strlen(student.address) + 1];
    strcpy(this->address, student.address);

    this->gpa = student.gpa;
}
ostream &operator<<(ostream &os, const Student &s)
{
    os << "ID: " << s.studentId << "\nFullname: " << s.fullname << "\nGPA: " << s.gpa << "\nAddress: " << s.address << "\n";
    return os;
}
istream &operator>>(istream &is, Student &s)
{
    char id[100];
    char name[100];
    char addr[100];
    double gpa;

    cout << "Enter student ID: ";
    is >> id;

    cout << "Enter GPA: ";
    is >> gpa;

    cout << "Enter full name: ";
    is.ignore();
    is.getline(name, 100);

    cout << "Enter address: ";
    is.getline(addr, 100);

    s.studentId = new char[strlen(id) + 1];
    strcpy(s.studentId, id);

    s.fullname = new char[strlen(name) + 1];
    strcpy(s.fullname, name);

    s.address = new char[strlen(addr) + 1];
    strcpy(s.address, addr);

    s.gpa = gpa;

    return is;
}

Student::~Student()
{
    delete[] studentId;
    delete[] fullname;
    delete[] address;
}
