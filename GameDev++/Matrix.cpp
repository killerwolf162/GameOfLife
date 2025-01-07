#include "Matrix.h"
#include <iostream>
#include <random>

Matrix::Matrix(int width, int length, float seed)
{
	
	this->width = width;
	this->length = length;
	for (auto x = 0; x < length; x++)
	{
		for (auto y = 0; y < width; y++)
		{
			float randomNum = rand() % 100;

			matrix.emplace_back();
			auto tile = new Cell;
			tile->rect.setSize({ tileSize.x, tileSize.y });
			tile->rect.setFillColor(sf::Color::Black);
			tile->rect.setOutlineThickness(0.5f);
			tile->rect.setOutlineColor(sf::Color::White);
			tile->rect.setPosition(x * tileSize.x, y * tileSize.y);
			tile->xPos = x * tileSize.x;
			tile->yPos = y * tileSize.y;
			tile->xIndex = x;
			tile->yIndex = y;
			if (randomNum > seed)
				tile->isAlive = true;
			matrix[x].push_back(*tile);
		}
	}
}

Matrix::~Matrix()
{
}


void Matrix::DrawMatrix(sf::RenderWindow& window)
{
	for (auto& index : matrix)
	{
		for (auto& it : index)
		{
			window.draw(it.rect);
		}
	}
}

void Matrix::SetCellColor(Cell& cell, sf::Color color)
{
	cell.ChangeColor(color);
}

void Matrix::CheckAliveCells(Matrix& matrix)
{
	for (auto index : matrix.matrix)
	{
		for (auto cell : index)
		{
			if (cell.isAlive == true)
			{
				std::cout << "Cell: " << cell.xIndex << "," << cell.yIndex << " is alive" << std::endl;
			}
			if (cell.isAlive == false)
			{
				std::cout << "Cell: " << cell.xIndex << "," << cell.yIndex << " is dead" << std::endl;
			}
		}
	}
}

Cell& Matrix::GetCell(int width, int lenght)
{
	return matrix[width][lenght];
}

std::vector<Cell> Matrix::GetNeighboursOfCell(Cell cell)
{
	auto neighbours = std::vector<Cell>();

	for (auto x = -1; x <= 1; x++)    //check neighbours
		for (auto y = -1; y <= 1; y++)
		{
			auto newX = x + cell.xIndex;
			auto newY = y + cell.yIndex;

			if (newX == -1 || newX == width ||
				newY == -1 || newY == length || //out of bounds
				(x == 0 && y == 0)) //Cell itself
			{
				continue;
			}

			Cell neighbour = GetCell(newX, newY);
			neighbours.emplace_back(neighbour);
		}

	return neighbours;
}

std::vector<Cell> Matrix::GetAliveCells(Matrix& matrix)
{
	std::vector<Cell> aliveCells;

	for (auto index : matrix.matrix)
	{
		for (auto cell : index)
		{
			if (cell.isAlive == true)
				aliveCells.emplace_back(cell);
		}
	}
	return aliveCells;
}

std::vector<Cell> Matrix::GetDeadCells(Matrix& matrix)
{
	std::vector<Cell> deadCells;

	for (auto index : matrix.matrix)
	{
		for (auto cell : index)
		{
			if (cell.isAlive != true)
				deadCells.emplace_back(cell);
		}
	}
	return deadCells;
}

std::ostream& operator<<(std::ostream& os, Matrix matrix)
{
	for (auto index : matrix.matrix)
	{
		for (auto it : index)
		{
			os << "xPos: " << it.xPos << " , "
				<< "yPos: " << it.yPos << " , ";
			os << std::endl;
		}
	}

	return os;
}
