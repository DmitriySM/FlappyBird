#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class GameObject
{
public:
    GameObject();
    virtual bool load(std::string filename);
    virtual void setPosition(float x, float y);
    virtual void move(float x, float y);
    virtual void rotate(float angle);
    virtual void draw(sf::RenderWindow& window);
    virtual void setAnimation();
    virtual void playAnimation(float animation_duration);
    virtual sf::FloatRect getBounds();
    virtual sf::Vector2f getOrigin();
protected:
    sf::Sprite _sprite;
    std::vector<sf::Texture> _frames;
private:
    sf::Texture _texture;
    std::string _filename;
    sf::Clock _clock;
    unsigned long _iter;
};

#endif // GAMEOBJECT_H
