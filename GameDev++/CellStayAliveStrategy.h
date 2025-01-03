#pragma once
#include "Strategy.h"
class CellStayAliveStrategy : public Strategy
{
	virtual void doAlgorithm(Matrix& matrix) override;
};

