#include "Game/game.h"
#include <iostream>
#include <sstream>

Game::Game()
{
    _font.loadFromFile("Fonts/Xcelsion.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(30);
    _text.setColor(sf::Color::Blue);
}

void Game::gameLoop(sf::RenderWindow& window)
{
    std::cout << "Entering game loop!\n";
    _inPlay = false;
    // Loading game objects
    Penguin penguin;
    penguin.load("penguin.png");
    Ground ground;
    Background bkg;
    Obstacle obst;
    Score sc;
    // Starting timers
    _frameClock.restart();
    ground.setPosition(0,575);
    penguin.setPosition(25, 250);
    _inPlay = true;
    // text
    _text.setPosition(10, 20);
    int score = 0;
    std::string s;
    s = "Score: " + std::to_string(score);
    _text.setString(s.c_str());
    while(_inPlay && window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            _inPlay = false;
            return;
        }

        _frameTime = _frameClock.restart();
        window.clear(sf::Color::Green);
        // Drawing background
        bkg.draw(window);
        window.draw(_text);

        for(sf::Sprite ob: obst.getObstacles())
        {

            window.draw(ob);
            window.draw(obst.addNewTop(ob));
            window.draw(obst.scoreLine(ob));
            if(ob.getGlobalBounds().intersects(penguin.getBounds()) ||
                    obst.addNewTop(ob).getGlobalBounds().intersects(penguin.getBounds()))
            {
                _inPlay = false;
            } else
                if (obst.scoreLine(ob).getGlobalBounds().contains(penguin.getBounds().left, penguin.getBounds().top))
                {
                    score++;
                    _text.setPosition(10, 20);
                    s = "Score: " + std::to_string(score);
                    _text.setString(s.c_str());
                }
        }

        if(ground.getBounds().top <= (penguin.getBounds().top + penguin.getBounds().height))
        {
            _inPlay = false;
        }

        ground.draw(window);
        obst.move(_frameTime);
        penguin.move(window, _frameTime);
        penguin.draw(window);
        window.display();

        }

    sc.setScore(score);

    if(_inPlay == false)
    {
        dispalyPause(window, score);
    }
}

void Game::dispalyPause(sf::RenderWindow& window, int score)
{
    sf::Event event;
    _text.setPosition(200, 200);
    std::string s = "Your score: " + std::to_string(score) + "\nGame Over!\nClick to start again...\n";
    _text.setString(s.c_str());

    Background bkg;

    while(window.waitEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        } else
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
                return;
        } else
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) )
                {
                    gameLoop(window);
                    return;
                }
            }

    window.clear(sf::Color::Green);
    bkg.draw(window);
    window.draw(_text);
    window.display();
    }
}
