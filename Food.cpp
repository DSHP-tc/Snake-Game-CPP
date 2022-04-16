#include "Food.h"
#include<SFML/Graphics.hpp>
#include<time.h>

Food::Food(sf::RenderWindow& window)
{	
	food.setSize(sf::Vector2f(size, size));
	food.setFillColor(sf::Color::Red);
	win = &window;
	move();
}
int Food::random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); 
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

void Food::draw()
{	
	win->draw(food);
}

void Food::move()
{	
	xpos = random(0, 39) * size;
	ypos = random(0, 39) * size;
	food.setPosition(sf::Vector2f(xpos, ypos));
}

int Food::getXPos()
{
	return xpos;
}

int Food::getYPos()
{	
	return ypos;
}