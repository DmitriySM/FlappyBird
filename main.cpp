#include <iostream>
#include "Menu/menu.h"
#include "Game/game.h"
#include "Score/score.h"

using namespace std;

int main()
{
    sf::RenderWindow _mainWindow;
    _mainWindow.create(sf::VideoMode(800, 600,32), "Flappy Bird, Dmitry!");
    _mainWindow.setFramerateLimit(60);
    Menu menu;
    Game game;
    Score sc;
    enum MenuResult {NoAction, Play, Score, Exit};
    while(!sf::Event::Closed)
    {
    switch(menu.show(_mainWindow))
    {
        case NoAction:
        {
            break;
        }
        case Play:
        {
            std::cout << "Entering game loop!\n";
            game.gameLoop(_mainWindow);
            menu.show(_mainWindow);
            break;
        }
        case Score:
        {
            sc.displayScore(_mainWindow);
            break;
        }
        case Exit:
        {
            _mainWindow.close();
            break;
        }
    }
    }
    return 0;
}
