#include <iostream>
#include <vector>
using namespace std;
class Person
{
protected:
    string name;

public:
    virtual void introduce()
    {
        cout << "I'm " << name << endl;
    }
    virtual void work() = 0;
    void doDailyTask()
    {
        introduce();
        work();
    }
};
// I'm Hinton
// teach

// I'm Bengio
// My advisor
// I'm Hinton

// I'm LeCun
// My advisor
// I'm Bengio
// My advisor
// I'm Hinton
class Student : public Person
{
private:
    Person *pAdvisor;

public:
    Student(string name, Person *pAdvisor)
    {
        this->name = name;
        this->pAdvisor = pAdvisor;
    }
    void introduce()
    {
        Person::introduce();
        cout << "My advisor " << endl;
        pAdvisor->introduce();
    }

    void work() { cout << "study" << endl; }
};
class Professor : public Person
{

public:
    Professor(string name) { this->name = name; };
    void work() { cout << "teach" << endl; }
};

int main()
{
    Professor p1("Hinton");
    Student p2("Bengio", &p1);
    Person *p3 = new Student("LeCun", &p2);
    p1.introduce();
    p1.work();
    p2.introduce();
    p3->introduce();

    return 0;
}