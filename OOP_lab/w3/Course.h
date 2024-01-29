#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Student.h"
using namespace std;
class Course
{
private:
    string courseId;
    string courseName;
    vector<pair<Student, bool>> studentList; // enroll: 1, unenroll: 0

public:
    Course();
    Course(string, string);
    void enroll(vector<Student>);
    void unenroll(vector<string>);
    void display();
    void display(vector<Student>);
    vector<Student> getExcellentStudentlist();
    vector<Student> getVeryGoodStudentlist();
    vector<Student> getGoodStudentlist();
    vector<Student> getAverageStudentlist();
    vector<Student> getUnderAverageStudentlist();
    int getAmountPassingStudent();
    int getAmountUnPassingStudent();
    void sortStudentListByIncreasingName();
    void sortStudentListByDecreasingName();
    void sortStudentListByIncreasingGrade();
    void sortStudentListByDecreasingGrade();
    void writeStudentListToFile(string fileName);
    void readStudentListFromFile(string filename);
};
