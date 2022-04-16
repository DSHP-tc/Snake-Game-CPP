#pragma once
#include<SFML/Graphics.hpp>

class Food {
private:
	int size = 20;
	sf::RectangleShape food;
	sf::RenderWindow* win=NULL;
	int xpos=0;
	int ypos=0;
public:
	Food(sf::RenderWindow&);
	void draw();
	void move();
	int random(int, int);
	int getXPos();
	int getYPos();
};