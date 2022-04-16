#include <SFML/Graphics.hpp>
#include"Snake.h"
#include "Food.h"
#include<string>
#include<sstream>
#include<fstream>

std::string toString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

std::string readSettings()
{
    std::string setting;
    std::ifstream   in;
    in.open("settings.ini");

    in >> setting;

    return setting;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Snake Game!");
    window.setFramerateLimit(60);
    sf::Font font;
    font.loadFromFile("arial.ttf");
    float gameSpeed = 0.2f;
    std::string setting;
    setting = readSettings();

    if (setting == "easy")
        gameSpeed = 0.2f;
    else if (setting == "medium")
        gameSpeed = 0.1f;
    else
        gameSpeed = 0.05f;


    sf::Text score_text;
    score_text.setFont(font);
    score_text.setCharacterSize(30);
    score_text.setFillColor(sf::Color::Green);
    score_text.setPosition(sf::Vector2f(5, 5));
    score_text.setString("Score: 0");

    sf::Text game_over_text;
    game_over_text.setFont(font);
    game_over_text.setCharacterSize(100);
    game_over_text.setFillColor(sf::Color::Yellow);
    game_over_text.setPosition(sf::Vector2f(100, 350));
    game_over_text.setString("Game Over");

    Snake snake(window);
    Food food(window);
    int score = 0;
    int check = -1;
    bool isGameOver = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up && snake.getDirection()!=3)
                    snake.moveUp();
                if (event.key.code == sf::Keyboard::Right && snake.getDirection() != 4)
                    snake.moveRight();
                if (event.key.code == sf::Keyboard::Down && snake.getDirection() != 1)
                    snake.moveDown();
                if (event.key.code == sf::Keyboard::Left && snake.getDirection() != 2)
                    snake.moveLeft();
            }
        }
        if (isGameOver == false)
        {
            check = snake.checkCollision(food.getXPos(), food.getYPos());
            if (check == 1)
            {
                food.move();
                score++;
                score_text.setString("Score: " + toString(score));

            }
            else if (check == 0)
                isGameOver = true;
            window.clear();
            snake.run();
            food.draw();
            
        }
        else
        {
            window.clear();
            window.draw(game_over_text);

        }
        window.draw(score_text);
        window.display();
        sf::sleep(sf::seconds(gameSpeed));
    }

    return 0;
}
