#include <iostream>
#include <vector>
using namespace std;
class Chef
{
public:
    virtual void prepare() = 0;
    void makeDish()
    {
        prepare();
        cout << "Made by Chef\n";
    }
};


class HeadChef : public Chef
{

public:
    virtual void prepare()
    {
        cout << "Prepare by HeadChef\n";
    }
};

class SecondChef : public HeadChef
{

public:
    void prepare()
    {
        HeadChef::prepare();
        cout << "Added by SecondChef\n";
    }
};
void makeFood(HeadChef c1, SecondChef c2)
{
    c1.makeDish();
    c2.makeDish();
}
int main()
{
    SecondChef c;
    makeFood(c, c);

    Chef *c1;
    c1 = new HeadChef;
    c1->prepare();

    c1 = new SecondChef;
    c1->prepare();
    return 0;
}
