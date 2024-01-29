#include <iostream>
#include <vector>
using namespace std;

class State;

class Dragon {
private:
    double damage;
    double defense;
    double HP;
    string name;
    int level;
    State* state;

public:
    Dragon(){};
    Dragon(string name, int level, double damage, double defense, double HP, State* state)
    {
        this->name = name;
        this->level = level;
        this->defense = defense;
        this->damage = damage;
        this->HP = HP;
        this->state = state;
    };
    double getDamage() { return damage; }
    double getDefense() { return defense; }
    double getHP() { return HP; }
    int getLevel() { return level; }
    string getName() { return name; }
    void setState(State* state)
    {
        this->state = state;
    }
    void power()
    {
        cout << "Power: " << state->getPower();
    }
    void move()
    {
        cout << state->getMove();
    }
    void attack() // Fixed typo here
    {
        cout << state->getAttack(); // Fixed typo here
    }
};

class State {
private:
    Dragon dragon;

public:
    State(){};
    Dragon getDragon() { return dragon; }
    virtual double getPower() = 0;
    virtual string getAttack() = 0;
    virtual string getMove() = 0;
};

class NormalState : public State {
public:
    double getPower() override
    {
        return (getDragon().getDamage() + getDragon().getDefense() + getDragon().getHP()) * getDragon().getLevel();
    }
    string getAttack() override
    {
        return "Rong " + getDragon().getName() + " phun lua mau vang";
    }
    string getMove() override
    {
        return "Rong " + getDragon().getName() + " di chuyen toc do binh thuong";
    }
};

class RampageState : public State {
public:
    RampageState(){};
    double getPower() override
    {
        return (2 * getDragon().getDamage() + getDragon().getDefense() + getDragon().getHP()) * getDragon().getLevel();
    }
    string getAttack() override
    {
        return "Rong " + getDragon().getName() + " phun lua mau do";
    }
    string getMove() override
    {
        return "Rong " + getDragon().getName() + " di chuyen nhanh";
    }
};

class DefenseState : public State {
public:
    DefenseState(){};
    double getPower() override
    {
        return (getDragon().getDamage() + 1.5 * getDragon().getDefense() + 1.5 * getDragon().getHP()) * getDragon().getLevel();
    }
    string getAttack() override
    {
        return "Rong " + getDragon().getName() + " phun lua mau xanh la";
    }
    string getMove() override
    {
        return "Rong " + getDragon().getName() + " di chuyen cham";
    }
};

int main()
{
    Dragon a("khanh", 10, 100, 50, 1000, new RampageState);
    a.attack(); // Fixed typo here
    return 0;
}
