#include "Objects/gameobject.h"

GameObject::GameObject()
{

}

bool GameObject::load(std::string filename)
{
    if(_texture.loadFromFile(filename))
    {
        _sprite.setTexture(_texture);
        return true;
    }
        return false;
}

void GameObject::setPosition(float x, float y)
{
    _sprite.setPosition(x,y);
}

void GameObject::move(float x, float y)
{
    _sprite.move(x,y);
}

void GameObject::rotate(float angle)
{
    _sprite.rotate(angle);
}

void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
}

void GameObject::playAnimation(float animation_duration)
{
    if(_clock.getElapsedTime().asSeconds() > animation_duration / _frames.size())
    {
        if(_iter < _frames.size() - 1)
        {
            _iter++;
        } else
        {
            _iter = 0;
        }
        _sprite.setTexture(_frames.at(_iter));
        _clock.restart();
    }
}

void GameObject::setAnimation()
{

}

sf::FloatRect GameObject::getBounds()
{
    return _sprite.getGlobalBounds();
}

sf::Vector2f GameObject::getOrigin()
{
    return _sprite.getOrigin();
}
