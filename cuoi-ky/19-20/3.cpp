#include <iostream>
#include <vector>
using namespace std;
class Circuit
{
public:
    virtual double getR() = 0;
};

class SingleCircuit : public Circuit
{
private:
    double r;

public:
    SingleCircuit(double r)
    {
        this->r = r;
    };
    double getR() override
    {
        return r;
    }
};
class SeriesCircuit : public Circuit
{
private:
    vector<Circuit *> listSubCircuit;

public:
    SeriesCircuit(){};
    SeriesCircuit(vector<Circuit *> listSubCircuit)
    {
        this->listSubCircuit = listSubCircuit;
    };
    void addCircuit(Circuit *subCircuit)
    {
        listSubCircuit.push_back(subCircuit);
    }
    double getR() override
    {
        double r = 0;
        for (auto x : listSubCircuit)
        {
            r += x->getR();
        }
        return r;
    }
};
class ParallelCircuit : public Circuit
{
private:
    vector<Circuit *> listSubCircuit;

public:
    ParallelCircuit(){};
    ParallelCircuit(vector<Circuit *> listSubCircuit)
    {
        this->listSubCircuit = listSubCircuit;
    };
    void addCircuit(Circuit *subCircuit)
    {
        listSubCircuit.push_back(subCircuit);
    }
    double getR() override
    {
        double r = 0;
        for (auto x : listSubCircuit)
        {
            r += 1 / x->getR();
        }
        return 1 / r;
    }
};
int main()
{
    SingleCircuit r1(1);
    SingleCircuit r2(2);
    SingleCircuit r3(3);
    SingleCircuit r4(4);
    SingleCircuit r5(5);

    SeriesCircuit r35;
    r35.addCircuit(&r3);
    r35.addCircuit(&r5);

    ParallelCircuit r345;
    r345.addCircuit(&r35);
    r345.addCircuit(&r4);

    SeriesCircuit r1345;
    r1345.addCircuit(&r1);
    r1345.addCircuit(&r345);

    ParallelCircuit r12345;
    r12345.addCircuit(&r2);
    r12345.addCircuit(&r1345);

    cout << r12345.getR();
    return 0;
}