#include "Game.cpp"
#include "SeriesCircuit.cpp"
#include "SingleCircuit.cpp"
#include "ParallelCircuit.cpp"
#include "Circuit.h"
using namespace std;

Bar *Bar::instance = NULL;
Ball *Ball::instance = NULL;

int main()
{
    // Bai 1 -----------------------------

    Game game;
    Ball *b1 = Ball::getInstance();
    Ball *b2 = game.ball->getInstance();
    cout << "Dia chi con tro thu nhat: " << b1 << "\n"
         << "Dia chi con tro thu hai: " << b2 << "\n";

    // // Bai 2 -----------------------------
    // Circuit *c35 = new SeriesCircuit;
    // Circuit *c3 = new SingleCircuit(3);
    // Circuit *c5 = new SingleCircuit(5);
    // c35->addCircuit(c3);
    // c35->addCircuit(c5);

    // Circuit *c4 = new SingleCircuit(4);

    // Circuit *c345 = new ParallelCircuit;
    // c345->addCircuit(c35);
    // c345->addCircuit(c4);

    // Circuit *c1345 = new SeriesCircuit;
    // c1345->addCircuit(new SingleCircuit(1));
    // c1345->addCircuit(c345);

    // Circuit *c12345 = new ParallelCircuit;
    // c12345->addCircuit(new SingleCircuit(2));
    // c12345->addCircuit(c1345);

    // cout << "Dien tro toan mach la: " << c12345->getResistance();
    return 0;
}