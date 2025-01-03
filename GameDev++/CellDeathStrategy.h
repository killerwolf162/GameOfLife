#pragma once
#include "Strategy.h"
class CellDeathStrategy : public Strategy
{
	virtual void doAlgorithm(Matrix& matrix) override;
};

