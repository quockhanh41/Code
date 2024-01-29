#include <iostream>
#include <vector>
using namespace std;
class Staff
{
private:
    string id;
    string name;
    string birthday;
    string address;
    double hesoluong;
    string startedDay;
    int baseSalary;

public:
    Staff(string id,
          string name,
          string birthday,
          string address,
          double hesoluong,
          string startedDay,
          int baseSalary)
    {
        this->id = id;
        this->name = name;
        this->birthday = birthday;
        this->address = address;
        this->hesoluong = hesoluong;
        this->startedDay = startedDay;
        this->baseSalary = baseSalary;
    };
    int getBaseSalary() { return baseSalary; }
    double getHesoluong() { return hesoluong; }
    virtual double getSalary() = 0;
    virtual int getNumberUnderStaff() = 0;
    virtual void addStaff(Staff *){};
};
class Manager : public Staff
{
    vector<Staff *> list_underStaff;

public:
    Manager(string id,
            string name,
            string birthday,
            string address,
            double hesoluong,
            string startedDay,
            int baseSalary) : Staff(id, name, birthday, address, hesoluong, startedDay, baseSalary){};
    double getSalary() override
    {
        return getBaseSalary() * getHesoluong();
    };
    int getNumberUnderStaff() override
    {
        int numberUnderStaff = 0;
        for (auto x : list_underStaff)
        {
            if (Manager *managePtr = dynamic_cast<Manager *>(x))
                numberUnderStaff++;
            numberUnderStaff += x->getNumberUnderStaff();
        }
        return numberUnderStaff;
    }
    void addStaff(Staff *newStaff)
    {
        list_underStaff.push_back(newStaff);
    }
};
class Programmer : public Staff
{
private:
    double overtime;

public:
    Programmer(string id,
               string name,
               string birthday,
               string address,
               double hesoluong,
               string startedDay,
               int baseSalary, double overtime) : Staff(id, name, birthday, address, hesoluong, startedDay, baseSalary)
    {
        this->overtime = overtime;
    }

    double getSalary()
    {
        return getBaseSalary() * getHesoluong() + overtime;
    };
    int getNumberUnderStaff() override
    {
        return 1;
    }
};
class Designer : public Staff
{
private:
    double bonus;

public:
    Designer(string id,
             string name,
             string birthday,
             string address,
             double hesoluong,
             string startedDay,
             int baseSalary, double bonus) : Staff(id, name, birthday, address, hesoluong, startedDay, baseSalary) { this->bonus = bonus; };
    double getSalary()
    {
        return getBaseSalary() * getHesoluong() + bonus;
    };
    int getNumberUnderStaff() override
    {
        return 1;
    }
};
class Tester : public Staff
{
private:
    int error;

public:
    Tester(string id,
           string name,
           string birthday,
           string address,
           double hesoluong,
           string startedDay,
           int baseSalary, int error) : Staff(id, name, birthday, address, hesoluong, startedDay, baseSalary) { this->error = error; };
    double getSalary()
    {
        return getBaseSalary() * getHesoluong() + 200 * error;
    };
    int getNumberUnderStaff() override
    {
        return 1;
    }
};
int main()
{
    Staff *m1 = new Manager("123", "khanh", "41", "BH", 1.2, "2020", 100);
    Staff *m2 = new Manager("123", "kiet", "41", "BH", 1.2, "2020", 100);
    Staff *s1 = new Programmer("123", "a", "41", "BH", 1.2, "2020", 100, 20);
    Staff *s2 = new Tester("123", "a", "41", "BH", 1.2, "2020", 100, 20);
    Staff *s3 = new Designer("123", "a", "41", "BH", 1.2, "2020", 100, 20);
    Staff *s4 = new Programmer("123", "a", "41", "BH", 1.2, "2020", 100, 20);
    Staff *s5 = new Programmer("123", "a", "41", "BH", 1.2, "2020", 100, 20);
    Staff *s6 = new Programmer("123", "a", "41", "BH", 1.2, "2020", 100, 20);
    m1->addStaff(s1);
    m1->addStaff(s2);
    m2->addStaff(s3);
    m2->addStaff(s4);
    m2->addStaff(s5);
    m2->addStaff(s6);
    m1->addStaff(m2);
    cout << m1->getNumberUnderStaff();
    return 0;
}