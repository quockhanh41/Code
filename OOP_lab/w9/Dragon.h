#include <iostream>
#include <vector>
#include <string>
// #include "State.h"
#pragma once
class State;
class Dragon {
private:
    double damage;
    double defense;
    double HP;
    std::string name;
    int level;
    State* state;

public:
    Dragon();
    Dragon(std::string name, int level, double damage, double defense, double HP);
    double getDamage();
    double getDefense();
    double getHP();
    int getLevel();
    std::string getName();
    void setState(State* state);
    void power();
    void move();
    void attack();
};