#pragma once

#include "Summator.h"

class SquareSummator : public Summator
{
public:
	int transform(int i) const override;
};