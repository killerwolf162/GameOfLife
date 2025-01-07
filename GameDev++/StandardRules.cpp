#include "StandardRules.h"
#include <iostream>

void StandardRules::doAlgorithm(Matrix& matrix)
{

	for (auto index : matrix.matrix)
	{
		for (auto cell : index)
		{
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == true)
			{
				auto neighboursofAlive = matrix.GetNeighboursOfCell(cell);
				int counter = 0;
				for (auto neighbour : neighboursofAlive)
				{
					if (neighbour.isAlive == true)
						counter++;
				}
				if (counter < 2 || counter > 3)
				{
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = false;
				}
				if (counter == 2 || counter == 3)
				{
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = true;
				}
				counter = 0;
			}
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == false)
			{
				auto neighboursofDead = matrix.GetNeighboursOfCell(cell);
				int counter = 0;
				for (auto neighbour : neighboursofDead)
				{
					if (neighbour.isAlive == true)
						counter++;
				}
				if (counter == 3)
				{
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = true;
					counter = 0;
				}
			}
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == true)
				matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::White);
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == false)
				matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::Black);

		}
	}
}
