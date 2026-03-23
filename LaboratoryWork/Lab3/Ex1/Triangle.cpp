#include "Triangle.h"

#include <string>
#include <sstream>

Triangle::Triangle(double side, double base_side)
{
	this->side = new double(side);
	this->base_side = new double(base_side);
}

Triangle::~Triangle()
{
	delete this->side;
	delete this->base_side;
}

double Triangle::calc_area()
{
	return (*side * *base_side) / 2;
}

std::string Triangle::to_string()
{
    std::stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"triangle\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}