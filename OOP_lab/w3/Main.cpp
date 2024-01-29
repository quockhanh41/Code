#include "Fraction.cpp"
#include "Stack.cpp"
#include "Student.cpp"
#include "Course.cpp"
int main()
{
    // Bai 1 --------------------------------------
    Stack<int> x1(9);
    for (int i = 0; i < 10; i++)
        x1.push(i);
    for (int i = 0; i < x1.getSize(); i++)
        cout << x1.At(i) << " ";
    cout << '\n';
    Stack<Fraction> x2(8);
    for (int i = 1; i < 11; i++)
    {
        x2.push(Fraction(1, i));
    }
    for (int i = 0; i < x2.getSize(); i++)
    {
        cout << x2.At(i) << " ";
    }
    cout << endl;

    // Bai 2 --------------------------------------
    Student a;
    a.getInfo();
    a.display();
    cout << endl;

    // Bai 3 --------------------------------------
    Course c("MTH01", "Toan roi rac");
    vector<Student> s;
    c.readStudentListFromFile("text.txt");
    Student s1("1", 8.1, "Khanh");
    Student s2("3", 7.5, "Nhan");
    Student s3("9", 9.5, "Linh");
    Student s4("6", 9.6, "Hinh");
    vector<string> u = {"3", "6"};
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    s.push_back(s4);
    c.enroll(s);
    c.sortStudentListByDecreasingGrade();
    cout << "List after sort by decreasing grade: \n";
    c.display();
    cout << endl;
    c.unenroll(u);
    cout << "List after unenroll and sort by increasing name: \n";
    c.sortStudentListByIncreasingName();
    c.writeStudentListToFile("list.txt");
    c.display();
    system("pause");
    return 0;
}