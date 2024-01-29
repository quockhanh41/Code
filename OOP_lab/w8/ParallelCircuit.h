#include <iostream>
#include <vector>
#include "Circuit.h"
class ParallelCircuit : public Circuit
{
private:
    vector<Circuit *> v;
    double getResistance();

public:
    ParallelCircuit(){};
    void addCircuit(Circuit *c);
    ParallelCircuit(vector<Circuit *> &);
};