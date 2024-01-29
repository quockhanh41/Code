#include <cstring>
#include <iostream>
#pragma once
using namespace std;
class Student
{
private:
    char *studentId;
    double gpa;
    char *fullname;
    char *address;

public:
    Student(){};
    Student(char *studentId, double gpa, char *fullname, char *address);
    Student(const Student &student);
    ~Student();
    friend ostream &operator<<(ostream &os, const Student &s);
    friend istream &operator>>(istream &is, Student &s);
};