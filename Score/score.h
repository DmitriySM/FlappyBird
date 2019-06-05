#ifndef SCORE_H
#define SCORE_H

#include "Objects/gameobject.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Objects/background.h"

class Score
{
public:
    Score() {}
    void setScore(int score);
    int getBestScore();
    int getCurrentScore();
    void displayScore(sf::RenderWindow& window);
private:
    int _currentScore;
    static int _bestScore;
};

#endif // SCORE_H
