#include "Figure.h"
#include <sstream>

std::string Figure::to_string() 
{
    std::stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"unknown\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}

double calc_cylinder_volume(Figure* base, double height) 
{
    if (base == nullptr || height < 0)
        return -1;

    return base->calc_area() * height;
}