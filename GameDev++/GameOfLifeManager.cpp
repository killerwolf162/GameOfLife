#include "GameOfLifeManager.h"


GameOfLifeManager::GameOfLifeManager()
{
}

GameOfLifeManager::~GameOfLifeManager()
{
}

void GameOfLifeManager::PerformAlgorithm(Matrix& matrix)
{
	Context context(std::make_unique<CellBirthStrategy>());
	context.PerformLogic(matrix);
	context.SetStrategy(std::make_unique<CellStayAliveStrategy>());
	context.PerformLogic(matrix);
	context.SetStrategy(std::make_unique<CellDeathStrategy>());
	context.PerformLogic(matrix);
}
