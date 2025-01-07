#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Cell.h"

class Matrix
{
public:

	Matrix(int width, int length, float seed);
	virtual ~Matrix();

	void DrawMatrix(sf::RenderWindow& window);
	void SetCellColor(Cell& cell, sf::Color color);
	void CheckAliveCells(Matrix& matrix);
	Cell& GetCell(int width, int lenght);

	std::vector<Cell> GetNeighboursOfCell(Cell cell);
	std::vector<Cell> GetAliveCells(Matrix& matrix);
	std::vector<Cell> GetDeadCells(Matrix& matrix);

	int width;
	int length;
	std::vector<std::vector<Cell>> matrix;

	sf::Vector2f tileSize{ 30.f, 30.f };

	friend std::ostream& operator<<(std::ostream& os, Matrix matrix);


private:

};

