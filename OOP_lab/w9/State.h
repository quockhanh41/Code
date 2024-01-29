#include "Dragon.h"
#pragma once
// class Dragon;
class State
{
private:
    Dragon *dragon;

public:
    State();
    Dragon *getDragon();
    void setDragon(Dragon *dragon);
    virtual double getPower() = 0;
    virtual std::string getAttack() = 0;
    virtual std::string getMove() = 0;
};

class NormalState : public State
{
public:
    double getPower() override;
    std::string getAttack() override;
    std::string getMove() override;
};

class RampageState : public State
{
public:
    RampageState();
    double getPower() override;
    std::string getAttack() override;
    std::string getMove() override;
};

class DefenseState : public State
{
public:
    DefenseState();
    double getPower() override;
    std::string getAttack() override;
    std::string getMove() override;
};