#include "Student.h"
Student::Student()
{
    studentId = "\0";
    grade = -1;
    fullname = "\0";
};
Student::Student(string studentId, double grade, string fullname)
{
    this->studentId = studentId;
    this->grade = grade;
    this->fullname = fullname;
};
void Student::getInfo()
{
    cout << "Student ID: ";
    cin >> studentId;
    cout << "Grade: ";
    cin >> grade;
    cout << "Fullname: ";
    cin >> fullname;
};
void Student::display()
{
    cout << "Student ID: " << studentId << '\n';
    cout << "Grade: " << grade << '\n';
    cout << "Fullname: " << fullname << '\n';
};
string Student::getStudentId()
{
    return studentId;
};
void Student::setStudentId(string studentId)
{
    this->studentId = studentId;
};
double Student::getGrade()
{
    return grade;
};
void Student::setGrade(double grade)
{
    this->grade = grade;
};
string Student::getFullname()
{
    return fullname;
};
void Student::setFullname(string fullname)
{
    this->fullname = fullname;
};
