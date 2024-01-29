#include <iostream>
#include <vector>
using namespace std;
// Implemented by devB
class Bar
{
private:
    int length;
    static Bar *instance;
    Bar();

public:
    static Bar *getInstance();
    static void deleteInstance();
};
// Implemented by devB
class Ball
{
private:
    double radius;
    static Ball *instance;
    Ball();

public:
    static Ball *getInstance();
    static void deleteInstance();
};
// Implemented by devB
class Brick
{
    Brick(){};
};
// Implemented by devB
class Game
{
public:
    Game(){};
    vector<Brick *> bricks;
    Bar *bar;
    Ball *ball;
};
