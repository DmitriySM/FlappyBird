#ifndef GROUND_H
#define GROUND_H

#include "Objects/gameobject.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#define DURATION 0.5f

class Ground  : public GameObject
{
public:
    Ground();
    void setAnimation();

private:
    sf::Clock _gndClock;
    sf::Sprite frames[2];
    int iter;
};

#endif // GROUND_H
