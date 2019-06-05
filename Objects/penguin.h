#ifndef PENGUIN_H
#define PENGUIN_H

#include "Objects/gameobject.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#define FLYING_SPEED 240.0f
#define FALLING_SPEED 120.0f

class Penguin  : public GameObject
{
public:
    Penguin();
    using GameObject::move;
    void move(sf::RenderWindow &window, sf::Time frameTime);
    void stop();
private:
    sf::Vector2f _movement;
    enum _penguinState {FLYING, FALLIING};
    int _birdis;
    sf::Clock _flyClock;
};

#endif // PENGUIN_H
