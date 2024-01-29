#include "Dragon.h"
#include "State.h"
Dragon::Dragon() {}

Dragon::Dragon(std::string name, int level, double damage, double defense, double HP)
{
    this->name = name;
    this->level = level;
    this->defense = defense;
    this->damage = damage;
    this->HP = HP;
    this->state = nullptr;
}

double Dragon::getDamage() { return damage; }

double Dragon::getDefense() { return defense; }

double Dragon::getHP() { return HP; }

int Dragon::getLevel() { return level; }

std::string Dragon::getName() { return name; }

void Dragon::setState(State *state)
{
    this->state = state;
    state->setDragon(this);
}

void Dragon::power()
{
    std::cout << "Power: " << state->getPower();
}

void Dragon::move()
{
    std::cout << state->getMove();
}

void Dragon::attack()
{
    std::cout << state->getAttack();
}
