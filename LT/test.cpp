#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public:
    virtual int getSpeed() = 0;
    virtual string getName() = 0;
};

class Cheetah : public Animal
{
    int getSpeed()
    {
        return 100;
    }
    string getName()
    {
        return "Cheetah";
    }
};
class Antelope : public Animal
{
    int getSpeed()
    {
        return 80;
    }
    string getName()
    {
        return "Antelope";
    }
};
class Lion : public Animal
{
    int getSpeed()
    {
        return 70;
    }
    string getName()
    {
        return "Lion";
    }
};
class Dog : public Animal
{
    int getSpeed()
    {
        return 60;
    }
    string getName()
    {
        return "Dog";
    }
};
class Human : public Animal
{
    int getSpeed()
    {
        return 30;
    }
    string getName()
    {
        return "Human";
    }
};
class Horse : public Animal
{
    int getSpeed()
    {
        return 60;
    }
    string getName()
    {
        return "Horse";
    }
};
vector<Animal *> WinnerX(Animal *A, Animal *B)
{
    if (A->getSpeed() > B->getSpeed())
        return {A};
    else if (A->getSpeed() < B->getSpeed())
        return {B};
    return {A, B};
}

int main()
{
    for (auto x : WinnerX(new Horse, new Dog))
        cout << x->getName() << " ";
}