#include "B25_S13.h"

void B25_S13::doAlgorithm(Matrix& matrix)
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
				if (counter == 2 || counter == 5)
				{
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = true;
				}
				else
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = false;

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
				if (counter == 1 || counter == 3 )
				{
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = true;
					counter = 0;
				}
			}
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == true)
				matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::Cyan);
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == false)
				matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::Black);

		}
	}
}
