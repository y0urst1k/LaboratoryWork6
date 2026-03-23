#pragma once

#include "Figure.h"

class Hexagon : public Figure
{
private:
	double* side;

public:
	Hexagon(double);
	~Hexagon() override;
	double calc_area() override;
	std::string to_string() override;
};

