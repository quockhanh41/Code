#include "State.h"

State::State() {}

void State::setDragon(Dragon *dragon)
{
    this->dragon = dragon;
}
Dragon *State::getDragon()
{
    return dragon;
}

double NormalState::getPower()
{
    return (getDragon()->getDamage() + getDragon()->getDefense() + getDragon()->getHP()) * getDragon()->getLevel();
}

std::string NormalState::getAttack()
{
    return "Dragon " + getDragon()->getName() + " spews yellow fire";
}

std::string NormalState::getMove()
{
    return "Dragon " + getDragon()->getName() + " moves at normal speed";
}

RampageState::RampageState() {}

double RampageState::getPower()
{
    return (2 * getDragon()->getDamage() + getDragon()->getDefense() + getDragon()->getHP()) * getDragon()->getLevel();
}

std::string RampageState::getAttack()
{

    return "Dragon " + getDragon()->getName() + " spews red fire";
}

std::string RampageState::getMove()
{
    return "Dragon " + getDragon()->getName() + " moves quickly";
}

DefenseState::DefenseState() {}

double DefenseState::getPower()
{
    return (getDragon()->getDamage() + 1.5 * getDragon()->getDefense() + 1.5 * getDragon()->getHP()) * getDragon()->getLevel();
}

std::string DefenseState::getAttack()
{
    return "Dragon " + getDragon()->getName() + " spews green fire";
}

std::string DefenseState::getMove()
{
    return "Dragon " + getDragon()->getName() + " moves slowly";
}
