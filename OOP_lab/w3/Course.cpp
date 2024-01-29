#include "Course.h"
bool cmp_greater_name(pair<Student, bool> a, pair<Student, bool> b)
{
    return a.first.getFullname() < b.first.getFullname();
}
bool cmp_less_name(pair<Student, bool> a, pair<Student, bool> b)
{
    return a.first.getFullname() > b.first.getFullname();
}
bool cmp_greater_grade(pair<Student, bool> a, pair<Student, bool> b)
{
    return a.first.getGrade() < b.first.getGrade();
}
bool cmp_less_grade(pair<Student, bool> a, pair<Student, bool> b)
{
    return a.first.getGrade() > b.first.getGrade();
}
bool cmp_id(pair<Student, bool> a, pair<Student, bool> b)
{
    return a.first.getStudentId() < b.first.getStudentId();
}
Course::Course()
{
    courseId = '\0';
    courseName = '\0';
};
Course::Course(string courseId, string courseName)
{
    this->courseId = courseId;
    this->courseName = courseName;
};
void Course::enroll(vector<Student> EnrollList)
{
    for (auto x : EnrollList)
        studentList.push_back({x, 1});
};
void Course::unenroll(vector<string> unenrollList)
{
    sort(studentList.begin(), studentList.end(), cmp_id);
    sort(unenrollList.begin(), unenrollList.end());
    int i = 0, j = 0;
    while (j < unenrollList.size())
    {
        if (studentList[i].first.getStudentId() == unenrollList[j])
        {
            studentList[i].second = 0;
            j++;
        }
        i++;
    }
};
void Course::display()
{
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].second == 1)
            cout << studentList[i].first.getStudentId() << " " << studentList[i].first.getFullname() << " " << studentList[i].first.getGrade() << endl;
    }
};
void Course::display(vector<Student> s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i].getStudentId() << " " << s[i].getFullname() << " " << s[i].getGrade() << endl;
};

vector<Student> Course::getExcellentStudentlist()
{
    vector<Student> res;
    for (auto x : studentList)
    {
        if (x.first.getGrade() >= 9 && x.second == 1)
            res.push_back(x.first);
    }
    return res;
};
vector<Student> Course::getVeryGoodStudentlist()
{
    vector<Student> res;
    for (auto x : studentList)
    {
        if (x.first.getGrade() >= 8 && x.first.getGrade() < 9 && x.second == 1)
            res.push_back(x.first);
    }
    return res;
};
vector<Student> Course::getGoodStudentlist()
{
    vector<Student> res;
    for (auto x : studentList)
    {
        if (x.first.getGrade() >= 6.5 && x.first.getGrade() < 8 && x.second == 1)
            res.push_back(x.first);
    }
    return res;
};
vector<Student> Course::getAverageStudentlist()
{
    vector<Student> res;
    for (auto x : studentList)
    {
        if (x.first.getGrade() >= 5 && x.first.getGrade() < 6.5 && x.second == 1)
            res.push_back(x.first);
    }
    return res;
};
vector<Student> Course::getUnderAverageStudentlist()
{
    vector<Student> res;
    for (auto x : studentList)
    {
        if (x.first.getGrade() < 5 && x.second == 1)
            res.push_back(x.first);
    }
    return res;
};
int Course::getAmountPassingStudent()
{
    int count = 0;
    for (auto x : studentList)
    {
        if (x.first.getGrade() < 5 && x.second == 1)
            count++;
    }
    return count;
};
int Course::getAmountUnPassingStudent()
{
    int count = 0;
    for (auto x : studentList)
    {
        if (x.first.getGrade() >= 5 && x.second == 1)
            count++;
    }
    return count;
};

void Course::sortStudentListByIncreasingName()
{
    sort(studentList.begin(), studentList.end(), cmp_greater_name);
};
void Course::sortStudentListByDecreasingName()
{
    sort(studentList.begin(), studentList.end(), cmp_less_name);
};
void Course::sortStudentListByIncreasingGrade()
{
    sort(studentList.begin(), studentList.end(), cmp_greater_grade);
};
void Course::sortStudentListByDecreasingGrade()
{
    sort(studentList.begin(), studentList.end(), cmp_less_grade);
};
void Course::writeStudentListToFile(string fileName)
{
    fstream f(fileName, ios ::out);
    if (!f.is_open())
    {
        cout << "Could not open file to write!\n";
        return;
    }
    for (auto x : studentList)
    {
        if (x.second == 1)
        {
            f << x.first.getStudentId() << '\n'
              << x.first.getFullname() << '\n'
              << x.first.getGrade() << '\n';
        }
    }
    f.close();
};
void Course::readStudentListFromFile(string fileName)
{
    fstream f(fileName, ios ::in);
    if (!f.is_open())
    {
        cout << "Could not open file to read!\n";
        return;
    }
    string temp;
    while (getline(f, temp))
    {
        Student s;
        s.setStudentId(temp);
        getline(f, temp);
        s.setFullname(temp);
        getline(f, temp);
        s.setGrade(stod(temp));
        studentList.push_back({s, 1});
    }
    f.close();
};