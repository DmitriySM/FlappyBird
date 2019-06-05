#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Objects/penguin.h"
#include "Objects/background.h"
#include "Objects/ground.h"
#include "Objects/obstacle.h"
#include "Score/score.h"

class Game
{
public:
    Game();
    void gameLoop(sf::RenderWindow& window);
    void dispalyPause(sf::RenderWindow& window, int score);
private:
    sf::Clock _frameClock;
    sf::Time _frameTime;
    bool _inPlay;
    sf::Font _font;
    sf::Text _text;
};

#endif // GAME_H
