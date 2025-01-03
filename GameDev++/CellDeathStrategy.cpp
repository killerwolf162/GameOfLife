#include "CellDeathStrategy.h"
#include <iostream>

void CellDeathStrategy::doAlgorithm(Matrix& matrix)
{
	// check matrix for all alive cells
	// check all neighbours of alive cells
	// if alive cell has <2 or >3 neighbours cell dies
	for (Cell& cell : matrix.aliveCells)
	{
		if (matrix.GetNeighboursOfCell(cell).size() < 2 || matrix.GetNeighboursOfCell(cell).size() > 3)
		{
			cell.isAlive = false;
			matrix.SetCellColor(cell, sf::Color::Black);
		}
	}

}
