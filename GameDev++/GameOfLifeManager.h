#pragma once
#include "Matrix.h"
#include "CellBirthStrategy.h"
#include "CellDeathStrategy.h"
#include "CellStayAliveStrategy.h"
#include "Context.h"

class GameOfLifeManager
{
public:

	GameOfLifeManager();
	virtual ~GameOfLifeManager();

	void PerformAlgorithm(Matrix& matrix);
};

