#pragma once
#include <string>
#include "Matrix.h"
 class Strategy
{

public:

	virtual ~Strategy() = default;
	virtual void doAlgorithm(Matrix& matrix);

};
