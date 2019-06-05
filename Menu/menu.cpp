#include "Menu/menu.h"
#include <unistd.h>

Menu::Menu()
{

}

Menu::MenuResult Menu::show(sf::RenderWindow& window)
{
    // loading textures
    sf::Texture texture_normal;
    texture_normal.loadFromFile("Images/main_menu_normal.png");
    sf::Sprite sprite(texture_normal);

    sf::Texture texture_play;
    texture_play.loadFromFile("Images/main_menu_play.png");
    sf::Sprite sprite_play(texture_play);

    sf::Texture texture_score;
    texture_score.loadFromFile("Images/main_menu_score.png");
    sf::Sprite sprite_score(texture_score);

    sf::Texture texture_exit;
    texture_exit.loadFromFile("Images/main_menu_exit.png");
    sf::Sprite sprite_exit(texture_exit);

    // Set up clickable regions

    MenuItem playButton;
    playButton.rect.top = 285;
    playButton.rect.height = 60;
    playButton.rect.left = 195;
    playButton.rect.width = 430;
    playButton.action = Play;

    MenuItem scoreButton;
    scoreButton.rect.top = 365;
    scoreButton.rect.height = 60;
    scoreButton.rect.left = 195;
    scoreButton.rect.width = 430;
    scoreButton.action = Score;

    MenuItem exitButton;
    exitButton.rect.top = 445;
    exitButton.rect.height = 60;
    exitButton.rect.left = 195;
    exitButton.rect.width = 430;
    exitButton.action = Exit;



    _menuItems.push_back(playButton);
    _menuItems.push_back(scoreButton);
    _menuItems.push_back(exitButton);

    // Drawing Main Menu
    window.clear(sf::Color::Green);
    window.draw(sprite);
    window.display();
    switch(getMenuresponse(window, _menuItems))
    {
    case NoAction:
        {
            break;
        }
    case Play:
        {
            window.clear(sf::Color::Green);
            window.draw(sprite_play);
            window.display();
            usleep(250000);
            return Play;
        }
    case Score:
        {
            window.clear(sf::Color::Green);
            window.draw(sprite_score);
            window.display();
            usleep(250000);
            return Score;
        }
    case Exit:
        {
            window.clear(sf::Color::Green);
            window.draw(sprite_exit);
            window.display();
            usleep(250000);
            return Exit;
        }
    }
    return NoAction;
}
Menu::MenuResult Menu::getMenuresponse(sf::RenderWindow& window,  std::list<MenuItem>& _menuItems)
{
    sf::Event menuEvent;
    while(true)
    {
        while(window.waitEvent(menuEvent))
        {
            if(menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, _menuItems);
            }
            if(menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}

Menu::MenuResult Menu::handleClick(int x, int y,  std::list<MenuItem>& _menuItems)
{
    std::list<MenuItem>::iterator it;
    for (it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        if( menuItemRect.contains(x,y))
        {

            return (*it).action;
        }
    }
    return NoAction;
}
