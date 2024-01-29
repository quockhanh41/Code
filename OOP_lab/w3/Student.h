#include <string>
#include <iostream>
using namespace std;
#pragma once
class Student
{
private:
    string studentId;
    double grade;
    string fullname;

public:
    Student();
    Student(string, double, string);
    void getInfo();
    void display();
    string getStudentId();
    void setStudentId(string);
    double getGrade();
    void setGrade(double);
    string getFullname();
    void setFullname(string);
};
