#pragma once

#include "Figure.h"

class Triangle : public Figure
{
private:
	double* side;
	double* base_side;

public:
	Triangle(double,double);
	~Triangle() override;
	double calc_area() override;
	std::string to_string() override;
};