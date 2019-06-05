#include "Objects/obstacle.h"
#include <iostream>

Obstacle::Obstacle()
{
    _texture.loadFromFile("Images/obstacleh.png");
    addNew();
}

void Obstacle::move(sf::Time frameTime)
{
    _movement.x = -160.0f;
    std::list<sf::Sprite>::iterator iter;
    std::list<sf::Sprite>::iterator prev;
    int rndlocY = (250 + (std::rand() % static_cast<int>((500 - 250 + 1))));
    for(iter = _obstacles.begin(), prev = _obstacles.end(); iter != _obstacles.end(); prev = iter, iter++)
    {
        iter->move(_movement * frameTime.asSeconds());
        if(iter->getPosition().x < -161){
            iter->setPosition(800, rndlocY);
            addNew();
        }
    }
}

sf::RectangleShape Obstacle::scoreLine(sf::Sprite sprite)
{
    sf::RectangleShape rect;
    rect.setPosition(sprite.getPosition().x + 159, sprite.getPosition().y - 300);
    rect.setSize(sf::Vector2f(2.5f, 600.f));
    rect.setFillColor(sf::Color::Transparent);
    return rect;
}

void Obstacle::addNew()
{
    sf::Sprite sp;
    sp.setTexture(_texture);
    int rndlocY = (250 + (std::rand() % static_cast<int>((500 - 250 + 1))));
    int rndlocX = 300 + (std::rand() % (402 - 300));
    if(_obstacles.empty())
    {
        sp.setPosition(800 + rndlocX, rndlocY);
    }
        else
    {
        std::list<sf::Sprite>::iterator iter = _obstacles.end();
        sp.setPosition(iter->getPosition().x - rndlocX, rndlocY);
    }

    _obstacles.push_back(sp);
}

sf::Sprite Obstacle::addNewTop(sf::Sprite sprite)
{
    sf::Sprite sp = sprite;
    sp.rotate(180);
    sp.setPosition(sprite.getPosition().x + 160, sprite.getPosition().y -200);
    return sp;
}

std::list<sf::Sprite> Obstacle::getObstacles()
{
    return _obstacles;
}

sf::Vector2i Obstacle::screenDimensions(800, 600);
sf::Vector2f Obstacle::_movement(0.0f,0.0f);

