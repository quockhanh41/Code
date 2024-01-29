#include <iostream>
#include <vector>
#include "Circuit.h"
class SeriesCircuit : public Circuit
{
private:
    vector<Circuit *> v;

public:
    SeriesCircuit(){};
    SeriesCircuit(const vector<Circuit *> &);
    double getResistance();
    void addCircuit(Circuit *c);
};