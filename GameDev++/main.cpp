#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Matrix.h"
#include "GameOfLifeManager.h"

sf::Vector2u windowSize{ 750,750 };
constexpr unsigned TPS = 60;
const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
sf::Vector2f tileSize(30.f, 30.f);

void ResetList(std::vector<Cell>& deadList, std::vector<Cell>& aliveList, Matrix& matrix)
{
	matrix.deadCells.clear();
	matrix.aliveCells.clear();
	matrix.FillCellLists(matrix, matrix.deadCells, matrix.aliveCells);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Make a grid!");
	window.setPosition(sf::Vector2i{ window.getPosition().x,0 });

	auto view = window.getDefaultView();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate
		= sf::Time::Zero;
	sf::Time FrameTime = sf::seconds(1.f / 60.f);

	Matrix matrix = Matrix(25, 25);
	GameOfLifeManager manager;

	matrix.FillCellLists(matrix, matrix.deadCells, matrix.aliveCells);

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			}
		}

		window.clear();
		manager.PerformAlgorithm(matrix); // changes made in algorithms not saving, missing reference somewhere (?)
		ResetList(matrix.deadCells, matrix.aliveCells, matrix);

		for (auto& cell : matrix.aliveCells) // checks matrix and paints all scells black or white
		{
			matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::White);
		}
		for (auto& cell : matrix.deadCells)
		{
			matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::Black);
		}

		matrix.DrawMatrix(window);
		window.display();
	}

	return 0;

}
