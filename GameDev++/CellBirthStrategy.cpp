#include "CellBirthStrategy.h"
#include <iostream>

void CellBirthStrategy::doAlgorithm(Matrix& matrix)
{
	// check matrix for all dead cells
	// check all neighbours of dead cells
	// if alive cell has 3 alive neighbours
	// make Cell alive

	int counter = 0;

	for (Cell& cell : matrix.deadCells)
	{
		for (Cell& neighbour : (matrix.GetNeighboursOfCell(cell)))
		{
			neighbour.isAlive = true;
			counter++;
		}
		if (counter > 3)
		{
			cell.isAlive = true;
			matrix.SetCellColor(cell, sf::Color::White);
		}

	}

}
