#include "Objects/background.h"

Background::Background()
{
    load("Images/bkg1.png");
    frames[0] = _sprite;
    load("Images/bkg2.png");
    frames[1] = _sprite;
}

void Background::play(sf::RenderWindow& window)
{

}
