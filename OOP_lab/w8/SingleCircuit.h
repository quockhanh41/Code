#include <iostream>
#include <vector>
#include "Circuit.h"
using namespace std;

class SingleCircuit : public Circuit
{
private:
    double resistance;

public:
    SingleCircuit(){};
    SingleCircuit(double);
    double getResistance();
};