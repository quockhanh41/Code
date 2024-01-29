#pragma once
class Student
{
private:
    double mathGrade;
    double englishGrade;
    double programmingGrade;

public:
    Student();
    Student(double, double, double);
    void input();
    void setMathGrade(double);
    double getMathGrade();
    void setEnglishGrade(double);
    double getEnglishGrade();
    void setProgrammingGrade(double);
    double getProgrammingGrade();
    double calcAverage();
    bool isExcellentStudent();
    void display();
};
