#ifndef MENU_H
#define MENU_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
// std includes
#include <iostream>
#include <stdio.h>
#include <list>

class Menu
{
public:
    Menu();
    enum MenuResult {NoAction, Play, Score, Exit};

    struct MenuItem
    {
        sf::Rect<int> rect;
        MenuResult action;

    };
    MenuResult show(sf::RenderWindow& window);
    MenuResult getMenuresponse(sf::RenderWindow& window,  std::list<MenuItem>& _menuItems);
    MenuResult handleClick(int x, int y,  std::list<MenuItem>& _menuItems);
private:
    std::list<MenuItem> _menuItems;
};

#endif // MENU_H
