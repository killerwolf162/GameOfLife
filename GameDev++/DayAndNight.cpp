#include "DayAndNight.h"

void DayAndNight::doAlgorithm(Matrix& matrix)
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
				if (counter == 3 || counter == 4 || counter == 6 || counter == 7 || counter == 8)
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
				if (counter == 3 || counter  ==6 || counter == 7 || counter == 8)
				{
					matrix.GetCell(cell.xIndex, cell.yIndex).isAlive = true;
					counter = 0;
				}
			}
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == true)
				matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::Yellow);
			if (matrix.GetCell(cell.xIndex, cell.yIndex).isAlive == false)
				matrix.GetCell(cell.xIndex, cell.yIndex).ChangeColor(sf::Color::Black);

		}
	}
}
