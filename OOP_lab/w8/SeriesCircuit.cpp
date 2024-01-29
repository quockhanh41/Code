#include "SeriesCircuit.h"
void SeriesCircuit::addCircuit(Circuit *c)
{
    v.push_back(c);
}
SeriesCircuit::SeriesCircuit(const vector<Circuit *> &v) : v(v) {}
double SeriesCircuit::getResistance()
{
    double r = 0;
    for (auto x : v)
    {

        r += x->getResistance();
    }
    return r;
}