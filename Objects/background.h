#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Objects/gameobject.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#define DURATION 0.5f

class Background : public GameObject
{
public:
    Background();
    void play(sf::RenderWindow& window);
private:
    sf::Clock _clock;
    sf::Sprite frames[2];
    int iter;
};

#endif // BACKGROUND_H
