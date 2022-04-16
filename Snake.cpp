#include"Snake.h"
#include<vector>
#include<SFML/Graphics.hpp>


Snake::Snake(sf::RenderWindow& window)
{
	length = 10;
	size = 20;
	direction = 2;
	xpos = std::vector<int>(length, size);
	ypos = std::vector<int>(length, size);
	win = &window;

}

void Snake::run()
{	
	for (int i = length - 1; i > 0; i--)
	{
		xpos[i] = xpos[i - 1];
		ypos[i] = ypos[i - 1];
	}

	if (direction == 1)
		ypos[0] -= size;
	if (direction == 2)
		xpos[0] += size;
	if (direction == 3)
		ypos[0] += size;
	if (direction == 4)
		xpos[0] -= size;

	draw();

	if (isFirstRun == true)
		isFirstRun = false;

}

void Snake::draw()
{
	sf::RectangleShape temprect(sf::Vector2f(20, 20));
	temprect.setFillColor(sf::Color::White);
	for (int i = 0; i < length; i++)
	{
		temprect.setPosition(sf::Vector2f(xpos[i], ypos[i]));
		win->draw(temprect);
	}
	
}

void Snake::moveUp()
{
	direction = 1;
}

void Snake::moveDown()
{
	direction = 3;
}

void Snake::moveRight()
{
	direction = 2;
}

void Snake::moveLeft()
{
	direction = 4;
}

int Snake::getDirection()
{
	return direction;
}

int Snake::checkCollision(int food_xpos,int food_ypos)
{
	if ((xpos[0] >= food_xpos && xpos[0] <= food_xpos + size) && (ypos[0] >= food_ypos && ypos[0] <= food_ypos + size))
	{
		increaseLength();
		return 1;
	}
	
	if (isFirstRun == false)
	{
		for (int i = 1; i < length; i++)
		{
			if (xpos[0] == xpos[i] && ypos[0] == ypos[i])
				return 0;
		}
	}

	if (xpos[0] + size > 800)
		xpos[0] = 0;
	else if (xpos[0] + size < 0)
		xpos[0] = 800;
	else if (ypos[0] + size < 0)
		ypos[0] = 800;
	else if (ypos[0] + size >800)
		ypos[0] = 0;

	return -1;

}

void Snake::increaseLength()
{
	xpos.push_back(20);
	ypos.push_back(20);
	length++;
}