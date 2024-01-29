#include <iostream>
#include "Student.h"
using namespace std;
Student::Student(){};
Student::Student(double mathGrade, double englishGrade, double programmingGrade)
{
    this->mathGrade = mathGrade;
    this->englishGrade = englishGrade;
    this->programmingGrade = programmingGrade;
};
void Student::input()
{
    cin >> mathGrade >> englishGrade >> programmingGrade;
};
void Student::setMathGrade(double mathGrade) { this->mathGrade = mathGrade; };
double Student::getMathGrade() { return mathGrade; };
void Student::setEnglishGrade(double englishGrade) { this->englishGrade = englishGrade; };
double Student::getEnglishGrade() { return englishGrade; };
void Student::setProgrammingGrade(double programmingGrade) { this->programmingGrade = programmingGrade; };
double Student::getProgrammingGrade() { return programmingGrade; };
double Student::calcAverage() { return (mathGrade + englishGrade + programmingGrade) / 3; };
bool Student::isExcellentStudent()
{
    if (mathGrade < 6.5 || englishGrade < 6.5 || programmingGrade < 6.5 || calcAverage() < 8)
        return 0;
    return 1;
}
void Student::display()
{
    if (isExcellentStudent())
        cout << "Excellent student!\n";
    else
        cout << "Is not Excellent student!\n";
}