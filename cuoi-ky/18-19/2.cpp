#include <iostream>
#include <vector>
using namespace std;
class Astronaunt
{
private:
    string name;
    string nationality;
    int hourInSpace;

public:
    Astronaunt(string name,
               string nationality,
               int hourInSpace)
    {
        this->name = name;
        this->nationality = nationality;
        this->hourInSpace = hourInSpace;
    };
};

class Food
{
private:
    string name;
    double weight;
    int MFG;
    int EXP;

public:
    Food(){};
    Food(string name,
         double weight,
         int MFG,
         int EXP)
    {
        this->name = name;
        this->weight = weight;
        this->MFG = MFG;
        this->EXP = EXP;
    };
    void setWeight(double weight)
    {
        this->weight = weight;
    }
};

class Spacecraft
{
private:
    string ID;
    string name;
    string mission;
    double speed;
    int lauchDate;

public:
    Spacecraft(string ID,
               string name,
               string mission,
               double speed,
               int lauchDate)
    {
        this->ID = ID;
        this->name = name;
        this->mission = mission;
        this->speed = speed;
        this->lauchDate = lauchDate;
    };
    int getLauchDate() { return lauchDate; };
    virtual double getFlightTime() = 0;
};
class UncrewedSpacecraft : public Spacecraft
{
private:
    int flightTime;

public:
    UncrewedSpacecraft(string ID,
                       string name,
                       string mission,
                       double speed,
                       int lauchDate, int flightTime) : Spacecraft(ID, name, mission, speed, lauchDate)
    {
        this->flightTime = flightTime;
    }
    double getFlightTime() { return flightTime; }
};
class CrewedSpacecraft : public Spacecraft
{
private:
    int crewSize;
    int landingDate;
    vector<Astronaunt> listAstronaunt;
    Food food;

public:
    CrewedSpacecraft(string ID,
                     string name,
                     string mission,
                     double speed,
                     int lauchDate, int crewSize,
                     int landingDate) : Spacecraft(ID, name, mission, speed, lauchDate)
    {
        this->crewSize = crewSize;
        this->landingDate = landingDate;
    };
    double getFlightTime() { return landingDate - getLauchDate(); }
    void setFood()
    {
        food.setWeight(max(1000.0, 2000.0 * getFlightTime() * listAstronaunt.size() / 1000));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}