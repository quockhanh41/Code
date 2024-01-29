#include "Game.h"
// Implemented by devB
Bar ::Bar()
{
    length = 5;
}
Bar *Bar::getInstance()
{
    if (!instance)
        instance = new Bar();
    return instance;
}
void Bar::deleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}
Ball ::Ball()
{
    radius = 2;
};
Ball *Ball ::getInstance()
{
    if (!instance)
        instance = new Ball();
    return instance;
}
void Ball ::deleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}

