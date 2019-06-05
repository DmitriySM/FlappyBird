#include "Objects/ground.h"

Ground::Ground()
{
    load("Images/gnd.png");
}

void Ground::setAnimation()
{
    sf::Texture t1;
    t1.loadFromFile("Images/gnd1.png");
    _frames.push_back(t1);
    sf::Texture t2;
    t1.loadFromFile("Images/gnd2.png");
    _frames.push_back(t2);
}
