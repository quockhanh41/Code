#include <iostream>
#include <vector>
using namespace std;
class Job
{
private:
    string name;
    int month;
    double costPerMonth;

public:
    Job(string name, int month, double costPerMonth)
    {
        this->name = name;
        this->month = month;
        this->costPerMonth = costPerMonth;
    };
    string getName() { return name; }
    int getMonth() { return month; }
    double getCost() { return month * costPerMonth; }
};

class Project
{
private:
    string name;
    vector<Job> job;

public:
    Project(string name)
    {
        this->name = name;
    }
    string getName() { return name; }
    void addJob(Job j)
    {
        job.push_back(j);
    }
    double grantMoney()
    {
        double totalCost = 0;
        for (auto x : job)
        {
            totalCost += x.getCost();
        }
        return totalCost;
    };
    void print()
    {
        cout << name << " ";
        for (auto x : job)
        {
            cout << x.getName() << ": " << x.getMonth() << " thang. ";
        }
        cout << "Kinh phi: " << grantMoney();
    };
};
class Idea : public Project
{
public:
    Idea(string name, int month) : Project(name)
    {
        addJob({"Phat trien", month, 20});
    };
};
class mvp : public Project
{
public:
    mvp(string name, int marketing, int operating) : Project(name)
    {
        addJob({"Van hanh", marketing, 15.0});
        addJob({"Marketing", operating, 15.0});
    };
};

int main()
{

    vector<Project *> project = {new Idea("SuperTech", 6),
                                 new mvp("FutureCar", 6, 3),
                                 new Idea("VirtualHouse", 7),
                                 new Idea("NightVision", 4),
                                 new mvp("SmartKey", 4, 5)};
    double sum = 0;
    for (int i = 0; i < project.size(); i++)
    {
        sum += project[i]->grantMoney();
        cout << i + 1 << ".";
        project[i]->print();
        cout << '\n';
    }
    cout << sum;
    return 0;
}