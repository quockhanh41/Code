#include <iostream>
#include <vector>
#pragma once
using namespace std;
class Circuit
{
private:
    vector<Circuit *> v;

public:
    Circuit(){};
    virtual void addCircuit(Circuit *c){};
    virtual double getResistance() = 0;
};
