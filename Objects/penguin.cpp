#include "Objects/penguin.h"

Penguin::Penguin()
{

}

void Penguin::move(sf::RenderWindow &window, sf::Time frameTime)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) )
    {
        _birdis = FLYING;
        _flyClock.restart();
    }

    if (_birdis == FLYING)
    {
        _sprite.move(0, -1* FLYING_SPEED * frameTime.asSeconds());
        if(_flyClock.getElapsedTime().asSeconds() > 0.25f)
        {
            _flyClock.restart();
            _birdis = FALLIING;
        }
    } else
    if (_birdis == FALLIING)
    {
        _sprite.move(0, FALLING_SPEED * frameTime.asSeconds());
    }
    window.draw(_sprite);
}

void Penguin::stop()
{
    _movement.y = 0.0f;
}
