#include "ParallelCircuit.h"
void ParallelCircuit::addCircuit(Circuit *c)
{
    v.push_back(c);
}
ParallelCircuit::ParallelCircuit(vector<Circuit *> &v) : v(v) {}
double ParallelCircuit::getResistance()
{
    double r = 0;
    for (auto x : v)
    {
        r += 1 / x->getResistance();
    }
    return 1 / r;
}