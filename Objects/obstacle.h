#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Objects/gameobject.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <list>

class Obstacle : public GameObject
{
public:
    Obstacle();
    using GameObject::move;
    void move(sf::Time frameTime);
    void addNew();
    sf::Sprite addNewTop(sf::Sprite sprite);
    sf::RectangleShape scoreLine(sf::Sprite sprite);
    std::list<sf::Sprite> getObstacles();
private:
    sf::Texture _texture;
    static sf::Vector2i screenDimensions;
    static sf::Clock frameClock;
    static sf::Vector2f _movement;
    std::list<sf::Sprite> _obstacles;

};

#endif // OBSTACLE_H
