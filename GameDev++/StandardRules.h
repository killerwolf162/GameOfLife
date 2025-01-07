#pragma once
#include "Strategy.h"
class StandardRules : public Strategy
{
	virtual void doAlgorithm(Matrix& matrix) override;
};

