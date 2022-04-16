#pragma once

#include<vector>
#include<SFML/Graphics.hpp>
class Snake {
private:
	int length=0;
	int size=0;
	std::vector<int> xpos;
	std::vector<int> ypos;
	sf::RenderWindow* win=NULL;
	int direction;
	bool isFirstRun = true;

public:
	Snake(sf::RenderWindow&);
	void draw();
	void run();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	int getDirection();
	int checkCollision(int,int);
	void increaseLength();

};