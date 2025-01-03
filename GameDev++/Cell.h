#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
public:

	Cell();
	virtual ~Cell();

	void ChangeColor(sf::Color color);

	int xPos = 0;
	int yPos = 0;
	int xIndex = 0;
	int yIndex = 0;
	sf::RectangleShape rect;
	sf::Color color;
	bool isAlive = false;

	friend std::ostream& operator<<(std::ostream& os, Cell cell);

};

