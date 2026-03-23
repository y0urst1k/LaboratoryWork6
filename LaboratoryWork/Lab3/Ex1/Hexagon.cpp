#include "Hexagon.h"

#include <string>
#include <sstream>
#include <cmath>

Hexagon::Hexagon(double side)
{
    this->side = new double(side);
}

Hexagon::~Hexagon()
{
    delete this->side;
}

double Hexagon::calc_area()
{
    return (3 * sqrt(3) * (*side * *side)) / 2;
}

std::string Hexagon::to_string()
{
    std::stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"hexagon\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}