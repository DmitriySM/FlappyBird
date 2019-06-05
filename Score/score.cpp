#include "Score/score.h"

void Score::setScore(int score)
{
    _currentScore = score;
    std::ofstream outfile;
    outfile.open("/home/dmitry/Qt_projects/FlappyBird/Files/score.txt", std::ios_base::app);
    outfile << _currentScore << "\n";
    outfile.close();
}

int Score::getCurrentScore()
{
    return _currentScore;
}

int Score::getBestScore()
{
    std::string line;
    std::ifstream f;
    f.open("/home/dmitry/Qt_projects/FlappyBird/Files/score.txt");
    int num;
    while(std::getline(f, line))
    {
        num = std::stoi(line);
        std::cout << line << num <<"\n";
        if(_bestScore < num)
        {
            _bestScore = std::stoi(line);
        }
    }

    return 0;
}

void Score::displayScore(sf::RenderWindow& window)
{
    getBestScore();
    while(!sf::Event::Closed)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return;
        }
        sf::Font font;
        font.loadFromFile("/home/dmitry/Qt_projects/FlappyBird/Fonts/Xcelsion.ttf");
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Blue);
        text.setPosition(200, 250);
        Background bkg;
        std::string s;

        s = "Best Score: " + std::to_string(_bestScore) +"\n";
        text.setString(s.c_str());
        window.clear(sf::Color::Green);
        // Drawing background
        bkg.draw(window);
        window.draw(text);
        window.display();
    }
}

int Score::_bestScore(0);
