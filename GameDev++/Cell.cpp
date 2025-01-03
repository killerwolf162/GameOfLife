#include "Cell.h"

Cell::Cell()
{
}

Cell::~Cell()
{
}

void Cell::ChangeColor(sf::Color color)
{
	this->color = color;
	rect.setFillColor(this->color);
}

std::ostream& operator<<(std::ostream& os, Cell cell)
{
	os << "xPos: " << cell.xPos << " , "
		<< "yPos: " << cell.yPos;
	os << std::endl;

	return os;
}
