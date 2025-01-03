#pragma once
#include <memory>
#include "Strategy.h"
#include <iostream>
#include "Cell.h"
#include "Matrix.h"

class Context
{

private:

	std::unique_ptr<Strategy> strategy_;

public:

	explicit Context(std::unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy))
	{
	}

	void SetStrategy(std::unique_ptr<Strategy>&& strategy)
	{
		strategy_ = std::move(strategy);
	}

	void PerformLogic(Matrix& matrix) const
	{
		if (strategy_)
		{
			strategy_->doAlgorithm(matrix);
		}
		else
		{
			std::cout << "Context: Strategy isnt set\n";
		}
	}

};

